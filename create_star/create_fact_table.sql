USE AllElec_star
GO 
IF (SELECT object_id('dbo.ElectFact')) > 0
   DROP TABLE dbo.ElectFact
CREATE TABLE dbo.ElectFact
	(
	ProductKey	int NOT NULL,
	CustomerKey	int NOT NULL,	
	TimeKey		int NOT NULL,
	unit_sold	int NOT NULL,
	total		money NOT NULL
	)

USE ALLelec_star
GO 
ALTER TABLE dbo.ElectFact WITH NOCHECK ADD
	CONSTRAINT PK_Sales_fact
		PRIMARY KEY NONCLUSTERED(ProductKey,CustomerKey,TimeKey)

GO