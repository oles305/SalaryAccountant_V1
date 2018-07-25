CREATE TABLE [dbo].[Employees]
(
    [Id] INT NOT NULL PRIMARY KEY IDENTITY (1,1), 
    [Name] NVARCHAR(50) NULL DEFAULT 1, 
    [Surname] NVARCHAR(50) NULL DEFAULT 1, 
    [PositionsId] INT NULL DEFAULT 1, 
    [IndividualCode] NCHAR(10) NULL DEFAULT N'Not set', 
    [DateOfHiring] TIMESTAMP NULL DEFAULT GETDATE(), 
    [OrderId] INT NULL DEFAULT 1, 
    [WorkExperience] INT NULL DEFAULT 0, 
    [PercentId] INT NULL DEFAULT 1, 
    [QualificationsId] INT NULL DEFAULT 1 
)
