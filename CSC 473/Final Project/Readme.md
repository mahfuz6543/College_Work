1. Set up database connection on backend/.env file
install mysql, create a database and a user. 


After creating a database and a user, there is a .env file in the backend where you will set the database name, username and the password you created on mysql. 


After setting up database credentials, run "npm run init-db" to initiate the database and create table


DB_USER=blogUser
PASSWORD=blogUser@Password2
DATABASE=blog
HOST=localhost
JWT_SECRET = 7665ygdtGDHUYS
PORT = 4000

2. Navigate to backend directory and run 
   - npm i - To install dependencies
   - npm run init-db - To initialize the databse
   - npm start - To start the server 

3. Navigate to frontend directory and run 
 npm start  - To start the client