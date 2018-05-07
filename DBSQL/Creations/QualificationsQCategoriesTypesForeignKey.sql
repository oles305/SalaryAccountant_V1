ALTER TABLE [dbo].[Qualifications]
	ADD CONSTRAINT [QualificationsQCategoriesTypesForeignKey]
	FOREIGN KEY (CategorieTypeId)
	REFERENCES [QCategoriesTypes] (Id)
	on delete cascade