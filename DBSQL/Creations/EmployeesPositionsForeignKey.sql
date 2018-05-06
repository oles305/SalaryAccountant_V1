ALTER TABLE [dbo].[Employees]
	ADD CONSTRAINT [EmployeesPositionsForeignKey]
	FOREIGN KEY (PositionsId)
	REFERENCES [Positions] (Id)
	on delete cascade