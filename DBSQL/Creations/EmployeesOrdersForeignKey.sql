ALTER TABLE [dbo].[Employees]
	ADD CONSTRAINT [EmployeesOrdersForeignKey]
	FOREIGN KEY (OrderId)
	REFERENCES [Orders] (Id)
	on delete cascade