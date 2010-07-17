USE Northwind_star 
GO 
IF (SELECT object_id('dbo.Customer_Dim')) > 0
   DROP TABLE dbo.Customer_Dim
CREATE TABLE dbo.Customer_Dim
	(
	CustomerKey int IDENTITY (1,1) NOT NULL,
	CustomerID nvarchar(50)  NOT NULL,
	CompanyName nvarchar(100)  NOT NULL,
	ContactName nvarchar(100)   NULL,
	ContactTitle nvarchar(100)   NULL,
	Address nvarchar(256)   NULL,
	City nvarchar(100)   NULL,
	Region nvarchar(100)   NULL,
	PostalCode nvarchar(100)   NULL,
	Country nvarchar(100)   NULL,
	Phone nvarchar(50)   NULL,
	Fax nvarchar(50)   NULL,
	)

IF (SELECT object_id('dbo.Product_Dim')) > 0
   DROP TABLE dbo.Product_Dim
CREATE TABLE Product_Dim
	(
	ProductKey int IDENTITY (1,1) NOT NULL,
	ProductID int NOT NULL,
	ProductName nvarchar(100)  NOT NULL,
	SupplierName nvarchar(100)  NOT NULL,
	CategoryName nvarchar(100)  NOT NULL,
	ListUnitPrice money NULL
	)

IF (SELECT object_id('dbo.Employee_Dim')) > 0
   DROP TABLE dbo.Employee_Dim
CREATE TABLE dbo.Employee_Dim
	(
	EmployeeKey	int IDENTITY (1,1) NOT NULL,
	EmployeeID	int NOT NULL,
	EmployeeName	nvarchar(100)  NOT NULL,
	HireDate	datetime  NULL,
	)
	
IF (SELECT object_id('dbo.Shiper_Dim')) > 0
   DROP TABLE dbo.Shiper_Dim
CREATE TABLE dbo.Shiper_Dim
	(
	ShiperKey	int IDENTITY (1,1) NOT NULL,
	ShiperID	int NOT NULL,
	ProductName	nvarchar(100)  NOT NULL,
	ShiperNam	nvarchar(100)  NOT NULL,
	)


IF (SELECT object_id('dbo.Time_Dim')) > 0
   DROP TABLE dbo.Time_Dim
CREATE TABLE dbo.Time_Dim
	(
	  TimeKey int IDENTITY (1,1) NOT NULL,
  TheDate datetime NOT NULL,
  DayOfWeek nvarchar(30)   NOT NULL,
  Month int NOT NULL,
  Year int NOT NULL,
  Quarter int NOT NULL,
  DayOfYear int NOT NULL,
  Holiday nvarchar(1)    NULL,
  Weekend nvarchar(1)    NULL,
  YearMonth nvarchar(61)    NULL,
  WeekOfYear int NOT NULL,
	)




USE Northwind_star 
GO 
ALTER TABLE dbo.Customer_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Customer_Dim
		PRIMARY KEY NONCLUSTERED(CustomerKey)

ALTER TABLE dbo.Product_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Product_Dim
		PRIMARY KEY NONCLUSTERED(ProductKey)

ALTER TABLE dbo.Time_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Time_Dim
		PRIMARY KEY NONCLUSTERED(TimeKey)

ALTER TABLE dbo.Shiper_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Shiper_Dim
		PRIMARY KEY NONCLUSTERED(ShiperKey)

ALTER TABLE dbo.Employee_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Employee_Dim
		PRIMARY KEY NONCLUSTERED(EmployeeKey)


GO