CREATE TABLE [dbo].[Departments]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY (1,1), 
    [DepartmentName] NVARCHAR(50) NOT NULL , 
    [PositionId] INT NULL DEFAULT 1
)
