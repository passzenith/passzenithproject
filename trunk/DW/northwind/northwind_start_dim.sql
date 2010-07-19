USE Northwind_star
GO 
IF (SELECT object_id('dbo.Customer_Dim')) > 0
   DROP TABLE dbo.Customer__Dim
CREATE TABLE dbo.Customer__Dim
	(
	CustomerKey	int IDENTITY (1,1) NOT NULL,
	CustoMerID	nchar(5) NOT NULL,
	CompanyName nvarchar(40) NOT NULL,
	ContactName nvarchar(30),
	ContactTitle nvarchar(30),
	CustomerAddress nvarchar(60),
	City nvarchar(15),
	Region nvarchar(15),
	PostalCode nvarchar(10),
	Country nvarchar(15),
	Phone nvarchar(24),
	Fax nvarchar(24) 
	)

IF (SELECT object_id('dbo.Product_Dim')) > 0
   DROP TABLE dbo.Product_Dim
CREATE TABLE dbo.Product_Dim
	(
	ProductKey	int IDENTITY (1,1) NOT NULL,
	ProductID	int NOT NULL,
	ProductName	nvarchar(40) NOT NULL,
	SupplierName	nvarchar(40) NOT NULL,
	CategoryName nvarchar(15) NOT NULL,
	ListUnitPrice money NOT NULL
	)

IF (SELECT object_id('dbo.Employee_Dim')) > 0
   DROP TABLE dbo.Employee_Dim
CREATE TABLE dbo.Employee_Dim
	(
	EmployeeKey	int IDENTITY (1,1) NOT NULL,
	EmployeeID	int NOT NULL,
	EmployeeName	nvarchar(40) NOT NULL,
	Hiredate	datetime NOT NULL,
	)	

IF (SELECT object_id('dbo.Shipper_Dim')) > 0
   DROP TABLE dbo.Shipper_Dim
CREATE TABLE dbo.Shipper_Dim
	(
	ShipperKey	int IDENTITY (1,1) NOT NULL,
	ShipperID	int NOT NULL,
	ShipperName	nvarchar(40) NOT NULL,
	)
	
IF (SELECT object_id('dbo.Time_Dim')) > 0
   DROP TABLE dbo.Time_Dim
CREATE TABLE dbo.Time_Dim
	(
	TimeKey		int IDENTITY (1,1) NOT NULL,
	TheDate	datetime NOT NULL,
	TimeDayOfWeek	nchar(10) NOT NULL,
	TimeMonth	int NOT NULL,
	TimeYear	int NOT NULL,
	TimeQuarter	int NOT NULL,
	TimeDayOfYear	int NOT NULL,
	Holiday	nchar(1) NOT NULL,
	Weekend nchar(1) NOT NULL,
	YearMonth nvarchar(100) NOT NULL,
	WeekOfYear int NOT NULL
	)
 	
USE Northwind_star
GO 
ALTER TABLE dbo.Customer_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Customer_Dim
		PRIMARY KEY NONCLUSTERED(CustomerKey)

ALTER TABLE dbo.Product_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Product_Dim
		PRIMARY KEY NONCLUSTERED(ProductKey)

ALTER TABLE dbo.Employee_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Employee_Dim
		PRIMARY KEY NONCLUSTERED(EmployeeKey)

ALTER TABLE dbo.Shipper_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Shipper_Dim
		PRIMARY KEY NONCLUSTERED(ShipperKey)		
		
ALTER TABLE dbo.Time_Dim WITH NOCHECK ADD
	CONSTRAINT PK_Time_Dim
		PRIMARY KEY NONCLUSTERED(TimeKey)

GO