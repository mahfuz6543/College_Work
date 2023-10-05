CREATE TABLE Users (
   Id INT PRIMARY KEY,
   Username VARCHAR(255) UNIQUE NOT NULL,
   Password VARCHAR(255) NOT NULL,
   ConfirmPassword VARCHAR(255) NOT NULL,
   Age INT CHECK (Age BETWEEN 12 AND 100),
   Gender CHAR(1) CHECK (Gender IN ('F', 'M')),
   CONSTRAINT matchPassword CHECK (Password = ConfirmPassword)
);
