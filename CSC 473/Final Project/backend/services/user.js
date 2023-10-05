import bcrypt from "bcryptjs"
import conn, { db, tableNames } from "../db.js"


export const user = {
    create: async ({ username, password }) => {
        const hashedPassword = await bcrypt.hash(password, 10);
        try {
            conn.query('START TRANSACTION');

            const [result] = await conn.query(
                `INSERT INTO ${tableNames.USER} (username, password) VALUES (?, ?)`,
                [username, hashedPassword]
            );

            conn.query('COMMIT');

            return  result.insertId;
        } catch (err) {
            conn.query('ROLLBACK');
            throw err;
        }
    },
    one: async (id) => {
        const query = `SELECT * FROM ${tableNames.USER} WHERE id =?`;
        const [result] = await conn.query(query, [id])

        return result[0];
    },
    all: async () => {
        const query = `SELECT * FROM ${tableNames.USER}`;

        const [result] = await conn.query(query)

        return result;
    },

    update: async ({ password, username, id }) => {
        const hashedPassword = await bcrypt.hash(password, 10);
        try {
            conn.query('START TRANSACTION');

            const [result] = await conn.query(
                'UPDATE users SET username=?, password=? WHERE id=?',
                [username, hashedPassword, id]
            );

            conn.query('COMMIT');

            return result.affectedRows;
        } catch (err) {
            conn.query('ROLLBACK');

            throw err;
        }
    },
    delete: async (id) => {
        try {
            conn.query('START TRANSACTION');

            const [result] = await conn.query(
                'DELETE FROM users WHERE id=?',
                [id]
            );

            conn.query('COMMIT');

            return result.affectedRows;
        } catch (err) {
            conn.query('ROLLBACK');

            throw err;
        }
    },
    byUsername: async (username) => {
        const query = `SELECT * FROM ${tableNames.USER} WHERE username =?`;
        const [result] = await conn.query(query, [username])

        if (result.length > 0) {
            return result[0]
        }
        return null;
    },

}

export default user