import jwt from "jsonwebtoken";
import userService from "../services/user.js";

const isLoggedIn = async(req, res, next) => {
    const token = req.headers['authorization'];

    if (!token) {
        return res.status(401).json({ message: 'Authentication failed: no token provided' });
    }

    try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        const user = await userService.one(decoded.userId)
        req.user = user;
        next();

    } catch (err) {
        console.log(err)
        return res.status(401).json({ message: 'Authentication failed: invalid token' });
    }
};

export default isLoggedIn;
