ALTER TABLE [dbo].[Employees]
	ADD CONSTRAINT [EmployeesSurnamesForeignKey]
	FOREIGN KEY (SurnamesId)
	REFERENCES [Surnames] (Id)
	on delete cascade