CREATE TABLE [dbo].[Qualifications]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [Number] INT NOT NULL , 
    [CategorieTypeId] INT NOT NULL, 
    [CategoriePositionId] INT NOT NULL, 
    [From] DATE NOT NULL, 
    [To] DATE NOT NULL
)
