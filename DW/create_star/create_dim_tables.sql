USE Northwind_star 
GO 
IF (SELECT object_id('dbo.CustomerDim')) > 0
   DROP TABLE dbo.CustomerDim
CREATE TABLE dbo.CustomerDim
	(
	CustomerKey	int IDENTITY (1,1) NOT NULL,
	CustoMerID	int NOT NULL,
	CustomerName	nvarchar(50) NOT NULL,
	CustomerAge	int NOT NULL,
	CustomerIncome	float NOT NULL,
	CustomerCredit	nvarchar(50) NOT NULL
	)

IF (SELECT object_id('dbo.ProductDim')) > 0
   DROP TABLE dbo.ProductDim
CREATE TABLE dbo.ProductDim
	(
	ProductKey	int IDENTITY (1,1) NOT NULL,
	ProductID	int NOT NULL,
	ProductName	nvarchar(50) NOT NULL,
	ProductCategory	nvarchar(50) NOT NULL,
	SupplierName	nvarchar(50) NOT NULL,
	ProductBrand	nvarchar(50) NOT NULL,
	ProductPrice	money NOT NULL,
	ProductType	nvarchar(50) NOT NULL,
	ProductPlace_made	nvarchar(50) NOT NULL
	)

IF (SELECT object_id('dbo.TimeDim')) > 0
   DROP TABLE dbo.TimeDim
CREATE TABLE dbo.TimeDim
	(
	TimeKey		int IDENTITY (1,1) NOT NULL,
	TimeDay		int NOT NULL,
	TimeMonth	int NOT NULL,
	TimeDate	datetime NOT NULL
	)
 	
USE Northwind_star 
GO 
ALTER TABLE dbo.CustomerDim WITH NOCHECK ADD
	CONSTRAINT PK_CustomerDim
		PRIMARY KEY NONCLUSTERED(CustomerKey)

ALTER TABLE dbo.ProductDim WITH NOCHECK ADD
	CONSTRAINT PK_ProductDim
		PRIMARY KEY NONCLUSTERED(ProductKey)

ALTER TABLE dbo.TimeDim WITH NOCHECK ADD
	CONSTRAINT PK_TimeDim
		PRIMARY KEY NONCLUSTERED(TimeKey)

GO