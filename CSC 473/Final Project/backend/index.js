import * as dotenv from 'dotenv'
import cors from "cors"
import bodyParser from "body-parser";
import express from "express"
import userRoutes from "./routes/users.js"
import authRoutes from "./routes/auth.js"
import blogRoutes from "./routes/blog.js"
import multer from 'multer';

dotenv.config()
const app = express();
const PORT = process.env.PORT || 4000;

// Set up middleware
app.use(cors());
app.use(bodyParser.json());
app.use(express.urlencoded({ extended: true }))
app.use("/", (req, res, next) => {
  console.log(`[${req.method}] ${req.originalUrl}`);
  next();
})


// Set up multer storage for uploaded images
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, 'public/images');
  },
  filename: (req, file, cb) => {

    const uniqueSuffix = Date.now() + '-' + Math.round(Math.random() * 1e9);
    const ext = file.originalname.split(".")[1];
    cb(null, file.fieldname + '-' + uniqueSuffix +"."+ ext);
  }
});

const upload = multer({ storage: storage });

app.post("/upload/", upload.single("file"), (req, res) => {
  res.status(200).json(req.file.filename)
})

// Set up routes
app.use('/auth', authRoutes);
app.use('/users', userRoutes);
app.use('/blog', blogRoutes);

// Serve static files from the public directory
app.use(express.static('public'));


// Start server
app.listen(PORT, () => {
  console.log(`Server started on port ${PORT}`);
});