SELECT DISTINCT
	Date=S.ShippedDate,
	DayOfWeek=DateName(dw,S.ShippedDate),
	Month=DatePart(mm,S.ShippedDate),
	Year=DatePart(yy,S.ShippedDate),
	Quarter=DatePart(qq,S.ShippedDate),
	DayOfYear=DatePart(dy,S.ShippedDate),
	Holiday='N',
	Weekend=case DatePart(dw,S.ShippedDate)
		when(1) then 'Y'
		when (7) then 'Y'
		else 'N'
		end,
	YearMonth = DateName(month,S.ShippedDate) + '_' + DateName(year,S.ShippedDate),
	WeekOfYear=DatePart(wk,S.ShippedDate)
FROM northwind.dbo.Orders S
WHERE S.ShippedDate IS NOT NULL