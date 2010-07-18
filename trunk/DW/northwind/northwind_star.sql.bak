

--SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";

-- 
-- Database: `northwind_star`
-- 

-- --------------------------------------------------------

-- 
-- Table structure for table `customer_dim`
-- 

CREATE TABLE `customer_dim` (
  `CustomerKey` int(11) NOT NULL auto_increment,
  `CustomerID` varchar(50) collate utf8_unicode_ci NOT NULL,
  `CompanyName` varchar(100) collate utf8_unicode_ci NOT NULL,
  `ContactName` varchar(100) collate utf8_unicode_ci default NULL,
  `ContactTitle` varchar(100) collate utf8_unicode_ci default NULL,
  `Address` varchar(256) collate utf8_unicode_ci default NULL,
  `City` varchar(100) collate utf8_unicode_ci default NULL,
  `Region` varchar(100) collate utf8_unicode_ci default NULL,
  `PostalCode` varchar(100) collate utf8_unicode_ci default NULL,
  `Country` varchar(100) character set utf8 collate utf8_turkish_ci default NULL,
  `Phone` varchar(50) collate utf8_unicode_ci default NULL,
  `Fax` varchar(50) collate utf8_unicode_ci default NULL,
  PRIMARY KEY  (`CustomerKey`),
  KEY `CustomerKey` (`CustomerKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- 
-- Dumping data for table `customer_dim`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `employee_dim`
-- 

CREATE TABLE `employee_dim` (
  `EmployeeKey` int(11) NOT NULL auto_increment,
  `EmployeeID` int(11) NOT NULL,
  `EmployeeName` varchar(100) collate utf8_unicode_ci NOT NULL,
  `HireDate` datetime default NULL,
  PRIMARY KEY  (`EmployeeKey`),
  KEY `EmployeeKey` (`EmployeeKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- 
-- Dumping data for table `employee_dim`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `product_dim`
-- 

CREATE TABLE `product_dim` (
  `ProductKey` int(11) NOT NULL auto_increment,
  `ProductID` int(11) NOT NULL,
  `ProductName` varchar(100) collate utf8_unicode_ci NOT NULL,
  `SupplierName` varchar(100) collate utf8_unicode_ci NOT NULL,
  `CategoryName` varchar(100) collate utf8_unicode_ci NOT NULL,
  `ListUnitPrice` double default NULL,
  PRIMARY KEY  (`ProductKey`),
  KEY `ProductKey` (`ProductKey`),
  KEY `ProductKey_2` (`ProductKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- 
-- Dumping data for table `product_dim`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `sales_fact`
-- 

CREATE TABLE `sales_fact` (
  `CustomerKey` int(11) NOT NULL,
  `EmployeeKey` int(11) NOT NULL,
  `ProductKey` int(11) NOT NULL,
  `ShipperKey` int(11) NOT NULL,
  `TimeKey` int(11) NOT NULL,
  `RequiredDate` datetime NOT NULL,
  `LineItemTotal` double NOT NULL,
  `LineItemQuantity` int(11) NOT NULL,
  `LineItemDiscount` double NOT NULL,
  PRIMARY KEY  (`CustomerKey`,`EmployeeKey`,`ProductKey`,`ShipperKey`,`TimeKey`),
  KEY `EmployeeKey` (`EmployeeKey`),
  KEY `ProductKey` (`ProductKey`),
  KEY `ShipperKey` (`ShipperKey`),
  KEY `TimeKey` (`TimeKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- 
-- Dumping data for table `sales_fact`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `shiper_dim`
-- 

CREATE TABLE `shiper_dim` (
  `ShiperKey` int(11) NOT NULL auto_increment,
  `ShiperID` int(11) NOT NULL,
  `ShiperName` varchar(100) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`ShiperKey`),
  KEY `ShiperKey` (`ShiperKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

-- 
-- Dumping data for table `shiper_dim`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `time_dim`
-- 

CREATE TABLE `time_dim` (
  `TimeKey` int(11) NOT NULL auto_increment,
  `TheDate` datetime NOT NULL,
  `DayOfWeek` varchar(30) character set utf8 collate utf8_unicode_ci NOT NULL,
  `Month` int(11) NOT NULL,
  `Year` int(11) NOT NULL,
  `Quarter` int(11) NOT NULL,
  `DayOfYear` int(11) NOT NULL,
  `Holiday` varchar(1) character set utf8 collate utf8_unicode_ci default NULL,
  `Weekend` varchar(1) character set utf8 collate utf8_unicode_ci default NULL,
  `YearMonth` varchar(61) character set utf8 collate utf8_unicode_ci default NULL,
  `WeekOfYear` int(11) NOT NULL,
  PRIMARY KEY  (`TimeKey`),
  KEY `TimeKey` (`TimeKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=1 ;

-- 
-- Dumping data for table `time_dim`
-- 


-- 
-- Constraints for dumped tables
-- 

-- 
-- Constraints for table `sales_fact`
-- 
ALTER TABLE `sales_fact`
  ADD CONSTRAINT `sales_fact_ibfk_1` FOREIGN KEY (`CustomerKey`) REFERENCES `customer_dim` (`CustomerKey`),
  ADD CONSTRAINT `sales_fact_ibfk_2` FOREIGN KEY (`EmployeeKey`) REFERENCES `employee_dim` (`EmployeeKey`),
  ADD CONSTRAINT `sales_fact_ibfk_3` FOREIGN KEY (`ProductKey`) REFERENCES `product_dim` (`ProductKey`),
  ADD CONSTRAINT `sales_fact_ibfk_4` FOREIGN KEY (`ShipperKey`) REFERENCES `shiper_dim` (`ShiperKey`),
  ADD CONSTRAINT `sales_fact_ibfk_5` FOREIGN KEY (`TimeKey`) REFERENCES `time_dim` (`TimeKey`);
