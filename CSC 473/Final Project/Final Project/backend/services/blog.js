import conn, { tableNames } from "../db.js"


export const blog = {
    /**
     * 
     * @param {{title:string, content:string, user_id:number, image:string}} param0 
     * @returns string - blog id
     */
    create: async ({ title, content, user_id, image }) => {
        try {
            conn.query('START TRANSACTION');

            const [result] = await conn.query(
                `INSERT INTO ${tableNames.BLOG} (title, content, user_id, image ) VALUES (?, ?, ?, ?)`,
                [title, content, user_id, image]
            );

            conn.query('COMMIT');

            return result.insertId;
        } catch (err) {
            conn.query('ROLLBACK');
            throw err;
        }
    },
    /**
     * Get One Blog
     * @param {number} id 
     * @returns {{id:string, content:string, image:string, user_id:string}}
     */
    one: async (id) => {
        const query = `SELECT * FROM ${tableNames.BLOG} WHERE id =?`;
        const [result] = await conn.query(query, [id])

        return result[0];
    },
    /**
     * 
     * @returns {Array<{id:string, content:string, image:string, user_id:string}>}
     */
    all: async () => {
        const query = `SELECT * FROM ${tableNames.BLOG}`;

        const [result] = await conn.query(query)

        return result;
    },

    updateBlog: async ({ content, image, title, id }) => {
        console.log({ content, image, title, id })
        const [result] = await conn.query(
            `UPDATE ${tableNames.BLOG} SET content=?, image=?, title=? WHERE id=?`,
            [content, image, title, id]
        );

        return result.affectedRows;
    },

    delete: async (id) => {
        try {
            conn.query('START TRANSACTION');

            const [result] = await conn.query(
                `DELETE FROM  ${tableNames.BLOG} WHERE id=?`,
                [id]
            );

            conn.query('COMMIT');

            return result.affectedRows;
        } catch (err) {
            conn.query('ROLLBACK');

            throw err;
        }
    },


}

export default blog