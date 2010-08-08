--3.1
SELECT	Customer.Location.Distict, 
		Customer.LocationProvince,
		COUNT(*) AS ViewingCount,
		COUNT(DISTINCT Property.CategoryName) AS PropertyCount
FROM	OwnerBy INNER JOIN 
		Property ON Property.OwnerID = Ownerby.OwnerID INNER JOIN
		[Owner] ON Ownerby.OwnerID = Owner.OwnerID INNER JOIN
		Viewing ON Viewing.OwnerID =  Property.OwnerID INNER JOIN
		Customer ON Customer.CustomerID = Sale.CustomerID INNER JOIN
		Location ON Location.LocationID = Customer.CustomerID  
		
WHERE	DATEPART(yyyy,Viewing.[Datetime]) = 2552 AND
		DATEPART(m,Viewing.[Datetime]) = 7
GROUP BY Customers.District,Customer.Province
HAVING   COUNT(DISTINCT Property.CategoryName)>2

--3.2
SELECT  Agent.AgentName,Property.CategoryName, 
		(COUNT(*)/COUNT(DISTINCT Sale.agreeprice)) AS avgcount-- ???????
FROM	OwnerBy INNER JOIN 
		Property ON Property.OwnerID = Ownerby.OwnerID INNER JOIN
		Owner ON Ownerby.ID = Owner.OwnerID INNER JOIN 
		Sale ON Sale.OwnerID =  Owner.OwnerID INNER JOIN 
		Agent ON Sale.AgentID = AgentID
WHERE	DATEPART(yyyy,Viewing.[Datetime]) = 2552 AND
		DATEPART(m,Viewing.[Datetime]) = 7
GROUP BY Property.CategoryName,Agent.AgentName

--3.3
SELECT  Customer.CustomerType,Property.CategoryName,
		SUM(Sale.Agreeprice) AS TotalPrice
FROM	OwnerBy INNER JOIN 
		Property ON Property.ID = Ownerby.ID INNER JOIN
		Owner ON Ownerby.ID = Owner.ID INNER JOIN 
		Sale ON Sale.OwnerID =  Owner.ID INNER JOIN 
		Agent ON Sale.AgentID = AgentID
WHERE	DATEPART(yyyy,Viewing.[Datetime]) = 2552 AND
		DATEPART(m,Viewing.[Datetime]) = 7
GROUP BY Customer.CustomerType,Agent.AgentName
HAVING   COUNT(DISTINCT Property.CategoryName)>2 
ORDER BY SUM(Sale.Agreeprice)

--3.4
SELECT  Agent.AgentName,SUM(Sale.Agreeprice) AS TotalPrice,
		Property.Location.District,Property.Location.Province,
		[MONTH] = DATEPART(m,Viewing.Datetime),[YEAR] = DATEPART(yyyy,Viewing.Datetime)
FROM	OwnerBy INNER JOIN 
		Property ON Property.OwnerID = Ownerby.OwnerID INNER JOIN
		[Owner] ON Ownerby.ID = Owner.OwnerID INNER JOIN 
		Sale ON Sale.OwnerID =  Owner.OwnerID INNER JOIN 
		Agent ON Sale.AgentID = AgentID INNER JOIN
		Location ON Location.LocationID = Customer.CustomerID  
WHERE	DATEPART(yyyy,Viewing.[Datetime]) = 2552 AND
		DATEPART(m,Viewing.[Datetime]) = 7
GROUP BY [MONTH],[YEAR],Property.CategoryName,Agent.AgentName,
		Property.Location.District,Property.Location.Province
		
--3.5
SELECT  [Quarter] = DatePart(qq,Viewing.Datetime),
		[YEAR] = DATEPART(yyyy,Viewing.Datetime),
		Customer.Location.Distict, Customer.LocationProvince,
		Province.Location.Distict, Province.LocationProvince,
		COUNT(*)
FROM	OwnerBy INNER JOIN 
		Property ON Property.OwnerID = Ownerby.OwnerID INNER JOIN
		[Owner] ON Ownerby.OwnerID = Owner.OwnerID INNER JOIN
		Viewing ON Viewing.OwnerID =  Property.OwnerID INNER JOIN
		Customer ON Customer.CustomerID = Sale.CustomerID INNER JOIN
		Location ON Location.LocationID = Customer.CustomerID  
		
WHERE	DATEPART(yyyy,Viewing.[Datetime]) = 2552 AND
		DATEPART(m,Viewing.[Datetime]) = 7
GROUP BY [MONTH],[YEAR],[Quarter],Customer.Location.Distict,
		Customer.LocationProvince,Province.Location.Distict, 
		Province.LocationProvince

		