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

--populatetime
SELECT DISTINCT
	Date=S.TableDate,
	DayOfWeek=DateName(dw,S.TableDate),
	Month=DatePart(mm,S.TableDate),
	Year=DatePart(yy,S.TableDate),
	Quarter=DatePart(qq,S.TableDate),
	DayOfYear=DatePart(dy,S.TableDate),
	Holiday='N',
	Weekend=case DatePart(dw,S.TableDate)
		when(1) then 'Y'
		when (7) then 'Y'
		else 'N'
		end,
	YearMonth = DateName(month,S.TableDate) + '_' + DateName(year,S.TableDate),
	WeekOfYear=DatePart(wk,S.TableDate)
FROM northwind.dbo.Orders S
WHERE S.TableDate IS NOT NULL

--script

Imports System
Imports System.Data
Imports System.Math
Imports Microsoft.SqlServer.Dts.Pipeline.Wrapper
Imports Microsoft.SqlServer.Dts.Runtime.Wrapper

<Microsoft.SqlServer.Dts.Pipeline.SSISScriptComponentEntryPointAttribute> _
<CLSCompliant(False)> _
Public Class ScriptMain
    Inherits UserComponent

    Public Overrides Sub Input0_ProcessInputRow(ByVal Row As Input0Buffer)
        If (Row.Region_IsNull) Then Row.region2 = "Other" Else Row.region2 = Row.Region
    End Sub

End Class

-- Load Fact
SELECT  T_Dim.TimeKey, 
		S_Dim.ShipperKey, 
		P_Dim.ProductKey, 
		E_Dim.EmployeeKey, 
		C_Dim.CustomerKey, 
		O.RequiredDate, 
		SUM(OD.Quantity * OD.UnitPrice) AS LineItemTotal, 
		SUM(OD.Quantity) AS LineItemQuantity, 
		SUM(OD.Discount) AS LineItemDiscount
FROM         	Orders O,
		[Order Details] OD, 
	      	Northwind_star.dbo.Employee_Dim E_Dim,
	      	Northwind_star.dbo.Product_Dim P_Dim,
	      	Northwind_star.dbo.Shipper_Dim S_Dim,
	      	Northwind_star.dbo.Time_Dim T_Dim,
	      	Northwind_star.dbo.Customer_Dim C_Dim

WHERE		(O.OrderID = OD.OrderID) AND
		(E_Dim.EmployeeID = O.EmployeeID) AND
		(P_Dim.ProductID = OD.ProductID) AND
		(S_Dim.ShipperID = O.ShipVia) AND
		(T_Dim.TheDate = O.ShippedDate) AND
		(C_Dim.CustomerID = O.CustomerID)
GROUP BY 	T_Dim.TimeKey, 
		S_Dim.ShipperKey, 
		P_Dim.ProductKey, 
		E_Dim.EmployeeKey, 
		C_Dim.CustomerKey, 
		O.RequiredDate




--Sql Example ดึงข้อมูลจากหลายๆตาราง

SELECT  dbo.Categories.CategoryName, 
		dbo.Suppliers.CompanyName, 
		dbo.Products.ProductID, 
		dbo.Products.ProductName, 
		Sum(dbo.Products.UnitPrice) AS ListUnitPrice
FROM    dbo.Products INNER JOIN  
		dbo.Categories ON dbo.Products.CategoryID = dbo.Categories.CategoryID INNER JOIN
        dbo.Suppliers ON dbo.Products.SupplierID = dbo.Suppliers.SupplierID
GROUP BY 
		dbo.Categories.CategoryName, 
		dbo.Suppliers.CompanyName,
		dbo.Products.ProductID,
		dbo.Products.ProductName,
		dbo.Products.UnitPrice