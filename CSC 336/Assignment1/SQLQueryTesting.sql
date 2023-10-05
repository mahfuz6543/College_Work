
--valid data: Users
Insert into Users values (1, 'alu', 'alu-123', 'alu-123', 16, 'F');
Insert into Users values (2, 'alu2', 'alu-123', 'alu-123', 18, 'M');
Insert into Users values (3, 'alu3', 'alu-123', 'alu-123', 22, 'M');

--invalid data: Users
Insert into Users values (4, 'alu4', 'alu-123', 'abc-456', 3, 'F'); -- same user name error, match password error, age error
Insert into Users values (4, 'alu5', 'hshd', 'gghs', 33, 'S'); -- Gender error, match password error
Insert into Users(Id,password,ConfirmPassword,Gender)  values (5, 'hshd', 'gghs', 'M'); -- Username is NULL
Insert into Users values (3, 'alu4', 'alu-123', 'alu-123', 22, 'M');-- same primary key
Insert into Users values(4, 'alu4','alu2222','alu33',25,'M');--Match Password constraint failed


--Valid data: Faculty
Insert into Faculty values (11, 'Adnan', 'CSC', 1);
Insert into Faculty values (12, 'Abdul', 'CSC', 2);
Insert into Faculty values (13, 'Nikhil', 'CSC', 3);
Update Faculty set DepartmentName='Math' where DepartmentId = 13; 

--Invalid data: Faculty
Insert into Faculty values (11, 'Kan', 'Eng', 2); --same username

--Delete users id
Delete from Users where Id = 2;


-- Valid Data: Courses
Insert into Courses values (111, 'Database', 11); 
Insert into Courses values (112, 'Algorithm', 12); 
Insert into Courses values (113, 'Calc', 13); 

-- Invalid Data: Courses
Insert into Courses values (111, 'Trig', 13); --same CourseId already exist

-- Update row from Faculty 
Update Faculty set DepartmentId = 25 where DepartmentName='Math' ;