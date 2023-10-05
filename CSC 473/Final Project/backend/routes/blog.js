import { Router } from "express"
import isLoggedIn from "../middleware/middleware.js";
import blogService from "../services/blog.js"

const router = Router()

router.get('/', async (req, res) => {
    try {
        const result = await blogService.all()
        console.log(result)
        res.status(200).send(JSON.stringify(result))

    } catch (error) {
        res.status(500).status(error)
    }
});

router.post('/', isLoggedIn, async (req, res) => {
    try {
        const { title, content, image } = req.body;

        const userId = req.user.id;
        console.log(content, title, userId, image)
        const result = await blogService.create({
            content, title, user_id: userId, image
        })
        console.log(result)
        res.status(200).send(JSON.stringify(result))

    } catch (error) {
        res.status(500).status(error)
    }
});

router.get('/:id', async (req, res) => {
    const { id } = req.params;
    try {
        const result = await blogService.one(id);
        res.status(200).send(JSON.stringify(result))
    } catch (error) {
        res.status(500).status(error)
    }
});

router.post('/:id', async (req, res) => {
    const { id } = req.params;
    try {
        const { title, content, image } = req.body;

        const result = await blogService.updateBlog({
            content, title, image, id
        })
        res.status(200).send(JSON.stringify(result))

    } catch (error) {
        res.status(500).status(error)
    }
});

// delete a user by id
router.delete('/:id', async (req, res) => {
    const { id } = req.params;
    try {
        const result = await blogService.delete(id)
        res.status(200).send(JSON.stringify({
            message: "User Deleted Successfuly!"
        }))
    } catch (error) {
        res.status(500).status(error)
    }
});

export default router