﻿CREATE TABLE [dbo].[Departments]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [Name] NVARCHAR(50) NOT NULL , 
    [PositionId] INT NULL DEFAULT 1
)
