// Initialize Database tables
import * as dotenv from 'dotenv'
dotenv.config()

import fs from "fs"
import db from "./db.js"



const sqlScript = fs.readFileSync('./db.sql').toString();

await db.query(sqlScript);

db.end();