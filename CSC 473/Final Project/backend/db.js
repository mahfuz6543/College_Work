import { createPool } from "mysql2/promise"

import * as dotenv from 'dotenv'
dotenv.config()

export const db =  createPool({
    host: process.env.HOST,
    user: process.env.DB_USER,
    password: process.env.PASSWORD,
    database: process.env.DATABASE,
    multipleStatements: true,
    waitForConnections: true,
    connectionLimit: 10,
    maxIdle: 10,
    idleTimeout: 60000,
    queueLimit: 0
})

export const tableNames = {
    USER: "users",
    BLOG: "blogs",
    CATEGORIES: "categories",
    COMMENTS: "comments",


}

export default db