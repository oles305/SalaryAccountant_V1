ALTER TABLE [dbo].[Departments]
	ADD CONSTRAINT [DepartmentsPositionsForeignKey]
	FOREIGN KEY (PositionId)
	REFERENCES [Positions] (Id)
	on delete cascade