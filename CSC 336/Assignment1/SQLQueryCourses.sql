CREATE TABLE Courses (
  CourseId INT PRIMARY KEY,
  CourseName VARCHAR(255) NOT NULL,
  DepartmentId INT REFERENCES Faculty(DepartmentId) ON UPDATE CASCADE
);
