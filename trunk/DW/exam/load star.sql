SELECT     	T_Dim.TimeKey, 
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