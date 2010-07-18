USE Northwind_star 
GO 
IF (SELECT object_id('dbo.Sales_Fact')) > 0
   DROP TABLE dbo.Sales_Fact
CREATE TABLE dbo.Sales_Fact
	(
	CustomerKey	int NOT NULL,
	EmployeeKey	int NOT NULL,	
	ProductKey	int NOT NULL,
	ShipperKey	int NOT NULL,
	TimeKey		int NOT NULL,
	RequiredDate	DateTime NOT NULL,
	LineItemTotal	money  	NOT NULL,
	LineItemQuantity int 	NOT NULL,
	LineItemDiscount money	NOT NULL,
	)

USE Northwind_star 
GO 
ALTER TABLE dbo.Sales_Fact WITH NOCHECK ADD
	CONSTRAINT PK_Sales_fact
		PRIMARY KEY NONCLUSTERED(CustomerKey,EmployeeKey,ProductKey,ShipperKey,TimeKey)

GO