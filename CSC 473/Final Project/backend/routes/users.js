import { Router } from "express"
import userService from "../services/user.js"

const router = Router()

router.get('', async (req, res) => {
    try {
        const result = await userService.all()
        console.log(result)
        res.status(200).send(JSON.stringify(result))

    } catch (error) {
        res.status(500).status(error)
    }
});

// get a user by id
router.get('/:id',async (req, res) => {
    const { id } = req.params;
    try {
        const result = await userService.one(id);
        res.status(200).send(JSON.stringify(result))
    } catch (error) {
        res.status(500).status(error)
    }
});

// update a user by id
router.post('/:id', (req, res) => {
    const { id } = req.params;
    const { username, password } = req.body;
    try {
        const result = userService.update({ username, password, id })
        res.status(200).send(JSON.stringify(result))
    } catch (error) {
        res.status(500).status(error)
    }
});

// delete a user by id
router.delete('/:id', async (req, res) => {
    const { id } = req.params;
    try {
        const result = await userService.delete(id)
        res.status(200).send(JSON.stringify({
            message: "User Deleted Successfuly!"
        }))
    } catch (error) {
        res.status(500).status(error)
    }
});

export default router