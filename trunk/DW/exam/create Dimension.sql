USE Northwind_star 
GO 
IF (SELECT object_id('dbo.Customer_Dim')) > 0
   DROP TABLE dbo.Customer_Dim
CREATE TABLE dbo.Customer_Dim
	(
	CustomerKey int IDENTITY (1,1) NOT NULL,
	CustomerID nvarchar(50)  NOT NULL,
	ListUnitPrice money NULL
	)

USE Northwind_star 
GO 
ALTER TABLE dbo.Customer_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Customer_Dim
		PRIMARY KEY NONCLUSTERED(CustomerKey)



GO