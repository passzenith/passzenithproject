SELECT     dbo.Categories.CategoryName, dbo.Suppliers.CompanyName, dbo.Products.ProductID, dbo.Products.ProductName, Sum (dbo.Products.UnitPrice) AS ListUnitPrice
FROM         dbo.Products INNER JOIN
                      dbo.Categories ON dbo.Products.CategoryID = dbo.Categories.CategoryID INNER JOIN
                      dbo.Suppliers ON dbo.Products.SupplierID = dbo.Suppliers.SupplierID
GROUP BY dbo.Categories.CategoryName, dbo.Suppliers.CompanyName, dbo.Products.ProductID, dbo.Products.ProductName, dbo.Products.UnitPrice