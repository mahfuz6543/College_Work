CREATE TABLE Faculty (
  DepartmentId INT PRIMARY KEY,
  Name VARCHAR(255) NOT NULL,
  DepartmentName VARCHAR(255) NOT NULL,
  IdRef INT, 
  FOREIGN KEY (IdRef) 
	REFERENCES Users(Id)
	ON DELETE SET NULL

);
