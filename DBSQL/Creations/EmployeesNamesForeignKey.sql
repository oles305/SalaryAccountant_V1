ALTER TABLE [dbo].[Employees]
	ADD CONSTRAINT [EmployeesNamesForeignKey]
	FOREIGN KEY (NamesId)
	REFERENCES [Names] (Id)
	on delete cascade