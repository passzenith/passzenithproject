SELECT     T_Dim.TimeKey, 
		S_Dim.ShipperKey, 
		P_Dim.ProductKey, 
		E_Dim.EmployeeKey, 
		C_Dim.CustomerKey, 
		O.RequiredDate, SUM(OD.Quantity) 
			AS LineItemQuantity, 
		SUM(OD.Quantity * OD.UnitPrice) 
			AS LineItemTotal, 
		SUM(OD.Discount) 
			AS LineItemDiscount
FROM         Orders O,
		[Order Details] OD, 
	      Northwind_star.dbo.Employee_Dim E_Dim,
	      Northwind_star.dbo.Product_Dim P_Dim,
	      Northwind_star.dbo.Shipper_Dim S_Dim,
	      Northwind_star.dbo.Time_Dim T_Dim,
	      Northwind_star.dbo.Customer_Dim C_Dim
WHERE	O.OrderID = OD.OrderID and
		E_Dim.EmployeeID = O.EmployeeID and
		P_Dim.ProductID = OD.ProductID and
		S_Dim.ShipperID = O.ShipVia and
		T_Dim.TheDate = O.ShippedDate and
		C_Dim.CustomerID = O.CustomerID
GROUP BY T_Dim.TimeKey, 
		S_Dim.ShipperKey, 
		P_Dim.ProductKey, 
		E_Dim.EmployeeKey, 
		C_Dim.CustomerKey, 
		O.RequiredDate