SELECT     SUM(dbo.[Order Details].UnitPrice) AS LUnit, 
                 SUM(dbo.[Order Details].Discount) AS LDiscount,                           
		 SUM(dbo.[Order Details].Quantity) AS LQuantity, 
                  O.OrderDate,
                  C_dim.CustomerKey,
                  T_dim.TimeKey,
                  P_dim.ProductKey,
                  S_dim.ShipperKey,
                  E_Dim.EmployeeKey

FROM        Northwind_star.dbo.[Customer_Dim] C_dim,
                  Northwind_star.dbo.[Time_Dim] T_dim, 
                  Northwind_star.dbo.[Product_Dim] P_dim,
                  Northwind_star.dbo.[Shipper_Dim] S_dim,
                  Northwind_star.dbo.[Employee_Dim] E_dim,
                  dbo.[Orders] O,
                  dbo.[Order Details] OD
                  
WHERE       dbo.[Orders].OrderID = dbo.[Order Details].OrderID


GROUP BY  C_dim.CustomerKey, T_dim.TimeKey, P_dim.ProductKey, S_dim.ShipperKey,E_Dim.EmployeeKey