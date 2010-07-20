SELECT     Northwind_star.dbo.Time_Dim.TimeKey, Northwind_star.dbo.Customer_Dim.CustomerKey, Northwind_star.dbo.Shipper_Dim.ShipperKey, 
                      Northwind_star.dbo.Product_Dim.ProductKey, Northwind_star.dbo.Employee_Dim.EmployeeKey, Orders.RequiredDate, SUM([Order Details].UnitPrice) AS LineItemTotal, 
                      SUM([Order Details].Quantity) AS LineItemQuantity, SUM([Order Details].Discount) AS LineItemDiscount
FROM         Orders INNER JOIN
                      Customers ON Orders.CustomerID = Customers.CustomerID INNER JOIN
                      Shippers ON Orders.ShipVia = Shippers.ShipperID INNER JOIN
                      [Order Details] ON Orders.OrderID = [Order Details].OrderID INNER JOIN
                      Employees ON Orders.EmployeeID = Employees.EmployeeID INNER JOIN
                      Products ON [Order Details].ProductID = Products.ProductID INNER JOIN
                      Northwind_star.dbo.Customer_Dim ON Customers.CustomerID = Northwind_star.dbo.Customer_Dim.CustoMerID INNER JOIN
                      Northwind_star.dbo.Shipper_Dim ON Shippers.ShipperID = Northwind_star.dbo.Shipper_Dim.ShipperID INNER JOIN
                      Northwind_star.dbo.Product_Dim ON [Order Details].ProductID = Northwind_star.dbo.Product_Dim.ProductID INNER JOIN
                      Northwind_star.dbo.Employee_Dim ON Employees.EmployeeID = Northwind_star.dbo.Employee_Dim.EmployeeID INNER JOIN
                      Northwind_star.dbo.Time_Dim ON Orders.OrderDate = Northwind_star.dbo.Time_Dim.TheDate
GROUP BY Northwind_star.dbo.Time_Dim.TimeKey, Northwind_star.dbo.Customer_Dim.CustomerKey, Northwind_star.dbo.Shipper_Dim.ShipperKey, 
                      Northwind_star.dbo.Product_Dim.ProductKey, Northwind_star.dbo.Employee_Dim.EmployeeKey, Orders.RequiredDate