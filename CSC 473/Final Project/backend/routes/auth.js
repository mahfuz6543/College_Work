import { Router } from "express"
import userService from "../services/user.js"
import bcrypt from "bcryptjs"
import jwt from "jsonwebtoken"


const JWT_SECRET = process.env.JWT_SECRET;

const router = Router()

router.post('/login',  async (req, res) => {
    try {
        const { username, password } = req.body;
        const user = await userService.byUsername(username);


        if (!user) {
            return res.status(401).send({ message: 'Invalid credentials' });
        }

        const passwordsMatch = await bcrypt.compare(password, user.password);

        if (!passwordsMatch) {
            return res.status(401).send({ message: 'Invalid credentials' });
        }

        const token = jwt.sign({ userId: user.id }, JWT_SECRET, { expiresIn: '1d' });

        res.send({ token, user: JSON.stringify(user) });

    } catch (error) {
        console.error(error);
        res.status(500).send({ message: 'Internal server error' });

    }
});

router.post('/register', async (req, res) => {
    try {
        const { username, password } = req.body;
        const existingUser = await userService.byUsername(username);

        if (existingUser) {
            return res.status(409).send({ message: 'User already exists' });
        }

        const userId = await userService.create({ username, password });
        const user = await userService.one(userId)
        
        const token = jwt.sign({ userId: user.id + "" }, JWT_SECRET, { expiresIn: '1d' });

        res.status(201).send({ token, user: JSON.stringify(user) });
    } catch (err) {
        console.error(err);
        res.status(500).send({ message: 'Internal server error' });
    }
});

export default router