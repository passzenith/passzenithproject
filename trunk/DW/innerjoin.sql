-- innerjoin
SELECT		Billing.SessionID
FROM		Billing 
		INNER JOIN
			DiagnosisCost 
		ON 
			Billing.SessionID = DiagnosisCost.SessionID 
		INNER JOIN
                      PatientRegister 
		ON 
			DiagnosisCost.SessionID = PatientRegister.SessionID

--  time 

SELECT DISTINCT
	Date=P.RegisterDate,
	DayOfWeek=DateName(dw,P.RegisterDate),
	Month=DatePart(mm,P.RegisterDate),
	Year=DatePart(yy,P.RegisterDate),
	Quarter=DatePart(qq,P.RegisterDate),
	DayOfYear=DatePart(dy,P.RegisterDate),
	Holiday='N',
	Weekend=case DatePart(dw,P.RegisterDate)
		when(1) then 'Y'
		when (7) then 'Y'
		else 'N'
		end,
	YearMonth = DateName(month,P.RegisterDate) + '_' + DateName(year,P.RegisterDate),
	WeekOfYear=DatePart(wk,P.RegisterDate)
FROM hospital_OLTP.dbo.PatientRegister P
WHERE P.RegisterDate IS NOT NULL
UNION
SELECT DISTINCT
	Date=B.BillingDate,
	DayOfWeek=DateName(dw,B.BillingDate),
	Month=DatePart(mm,B.BillingDate),
	Year=DatePart(yy,B.BillingDate),
	Quarter=DatePart(qq,B.BillingDate),
	DayOfYear=DatePart(dy,B.BillingDate),
	Holiday='N',
	Weekend=case DatePart(dw,B.BillingDate)
		when(1) then 'Y'
		when (7) then 'Y'
		else 'N'
		end,
	YearMonth = DateName(month,B.BillingDate) + '_' + DateName(year,B.BillingDate),
	WeekOfYear=DatePart(wk,B.BillingDate)
FROM hospital_OLTP.dbo.Billing B
WHERE B.BillingDate IS NOT NULL

--Case
SELECT     Customers.*, 
		AgeRange = 
		CASE 
			WHEN Age < 18 THEN 'young' 
			WHEN Age >= 18 AND Age < 60 THEN 'adult' 					
			WHEN Age >= 60 THEN 'old' 
		END
FROM         Customers

--Date diff

DATEDIFF (datepart ,startdate ,enddate ) As time

	year		=     yy, yyyy
	quarter		=     qq, q
	month		=     mm, m
	dayofyear	=     dy, y
	day		=     dd, d
	week		=    wk, ww
	Hour		=    hh
	minute		=    mi, n
	second		=    ss, s
	millisecond	=     ms 
	
--การเรียก   tablename.column