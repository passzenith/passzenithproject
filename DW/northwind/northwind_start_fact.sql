USE Northwind_star
GO 
IF (SELECT object_id('dbo.SalesFact')) > 0
   DROP TABLE dbo.SalesFact
CREATE TABLE dbo.SalesFact
	(
	TimeKey		int NOT NULL,
	CustomerKey	int NOT NULL,	
	ShipperKey 	int NOT NULL,	
	ProductKey	int NOT NULL,
	EmployeeKey int NOT NULL,	
	RequireDate datetime NOT NULL,	
	LineItemTotal money NOT NULL,
	LineItemQuantity smallint NOT NULL,
	LineItemDiscount real NOT NULL
	)

USE Northwind_star
GO 
ALTER TABLE dbo.SalesFact WITH NOCHECK ADD
	CONSTRAINT PK_Sales_fact
		PRIMARY KEY NONCLUSTERED(TimeKey,CustomerKey,ShipperKey,ProductKey,EmployeeKey)

GO