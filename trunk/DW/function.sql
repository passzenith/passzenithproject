SUM(Billing.TotalCost) AS total, 
COUNT(Billing.TotalCost)  AS counttotal, 
COUNT(*) AS sounttest, 
COUNT(DISTINCT Billing.Tax) AS sounttest
AVG(TEST) AS testt
MAX()
MIN()



SELECT     Customers.Region, Customers.City, Doctors.City AS Expr1, Doctors.Region AS Expr2, SUM(Billing.TotalCost) AS total, COUNT(Billing.HospitalBranchID) 
                      AS counthos, COUNT(DISTINCT Billing.HospitalBranchID) AS counthosdis, AVG(DISTINCT Billing.HospitalBranchID) AS co0u
FROM         DiagnosisDescription INNER JOIN
                      PatientRegister INNER JOIN
                      Customers ON PatientRegister.PatientID = Customers.PateintID INNER JOIN
                      DiagnosisCost ON PatientRegister.SessionID = DiagnosisCost.SessionID INNER JOIN
                      Doctors ON DiagnosisCost.DoctorID = Doctors.DoctorId INNER JOIN
                      Billing INNER JOIN
                      HospitalBranch ON Billing.HospitalBranchID = HospitalBranch.BranchID ON DiagnosisCost.SessionID = Billing.SessionID ON 
                      DiagnosisDescription.Diagnosis_id = DiagnosisCost.Diagnosis_id
GROUP BY Customers.Region, Customers.City, Doctors.City, Doctors.Region
HAVING      (COUNT(DISTINCT Billing.HospitalBranchID) > 1)