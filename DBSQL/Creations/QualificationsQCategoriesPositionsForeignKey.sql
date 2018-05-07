ALTER TABLE [dbo].[Qualifications]
	ADD CONSTRAINT [QualificationsQCategoriesPositionsForeignKey]
	FOREIGN KEY (CategoriePositionId)
	REFERENCES [QCategoriesPositions] (Id)
	on delete cascade