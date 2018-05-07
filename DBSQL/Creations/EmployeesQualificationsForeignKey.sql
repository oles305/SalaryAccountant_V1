ALTER TABLE [dbo].[Employees]
	ADD CONSTRAINT [EmployeesQualificationsForeignKey]
	FOREIGN KEY (QualificationsId)
	REFERENCES [Qualifications] (Id)
	on delete cascade