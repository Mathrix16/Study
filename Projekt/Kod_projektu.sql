--AUTORZY: Adam Wieliczko, Jakub Miga³a

--TABELE

IF OBJECT_ID('dbo.Workers', 'U') IS NOT NULL 
	DROP TABLE Workers
GO
CREATE TABLE Workers(
WorkerID INT PRIMARY KEY IDENTITY(1,1),
PESEL CHAR(11) UNIQUE NOT NULL,
Name NVARCHAR(50) NOT NULL,
Surname NVARCHAR(50) NOT NULL,
Salary MONEY NULL,
Birthdate DATE NOT NULL
)
GO

IF OBJECT_ID('dbo.Customers', 'U') IS NOT NULL 
	DROP TABLE Customers
GO
CREATE TABLE Customers(
CustomerID INT PRIMARY KEY IDENTITY(1,1),
PESEL CHAR(11) UNIQUE NOT NULL,
Name NVARCHAR(50) NOT NULL,
Surname NVARCHAR(50) NOT NULL,
)
GO

IF OBJECT_ID('dbo.CustomersCars', 'U') IS NOT NULL 
	DROP TABLE CustomersCars
GO
CREATE TABLE CustomersCars(
CarID INT PRIMARY KEY IDENTITY(1,1),
CarOwner INT NOT NULL,
Brand NVARCHAR(50) NOT NULL,
ProductionYear INT NOT NULL
)
GO

IF OBJECT_ID('dbo.RepairState', 'U') IS NOT NULL 
	DROP TABLE RepairState
GO
CREATE TABLE RepairState(
StateID INT PRIMARY KEY IDENTITY(1,1),
StateName NVARCHAR(50) NOT NULL
)
GO

IF OBJECT_ID('dbo.Parts', 'U') IS NOT NULL 
	DROP TABLE Parts
GO
CREATE TABLE Parts(
PartID INT PRIMARY KEY IDENTITY(1,1),
PartName NVARCHAR(50) NOT NULL,
PartCategory INT NOT NULL
)
GO

IF OBJECT_ID('dbo.UsedParts', 'U') IS NOT NULL 
    DROP TABLE UsedParts
GO

CREATE TABLE UsedParts(
RepairID INT,
PartID INT,
Quantity INT DEFAULT 1
)
GO

IF OBJECT_ID('dbo.PartsCategories', 'U') IS NOT NULL 
	DROP TABLE PartsCategories
GO
CREATE TABLE PartsCategories(
CategoryID INT PRIMARY KEY IDENTITY(1,1),
CategoryName NVARCHAR(50) NOT NULL
)
GO

IF OBJECT_ID('dbo.Orders', 'U') IS NOT NULL 
	DROP TABLE Orders
GO
CREATE TABLE Orders(
OrderID INT PRIMARY KEY IDENTITY(1,1),
OrderDate DATE NOT NULL,
WholesalerID INT NOT NULL

)
GO

IF OBJECT_ID('dbo.Leaves', 'U') IS NOT NULL 
	DROP TABLE Leaves
GO
CREATE TABLE Leaves(
WorkerID INT NOT NULL,
DateFrom DATE NOT NULL,
DateTo DATE NOT NULL,
PRIMARY KEY(WorkerID,DateFrom)
)
GO

IF OBJECT_ID('dbo.Part_Price', 'U') IS NOT NULL 
    DROP TABLE Part_Price
GO

CREATE TABLE Part_Price (
PartID INT ,
Price_From DATE NOT NULL,
Part_Price MONEY DEFAULT 0
)

GO

IF OBJECT_ID('dbo.Price_of_the_service', 'U') IS NOT NULL 
    DROP TABLE Price_of_the_service
GO

CREATE TABLE Price_of_the_service (
ServiceID INT ,
Price_From DATE NOT NULL,
Service_Price MONEY DEFAULT 0
)

GO

IF OBJECT_ID('dbo.List_of_Wholesalers_Supplying_Parts', 'U') IS NOT NULL 
    DROP TABLE List_of_Wholesalers_Supplying_Parts
GO

CREATE TABLE List_of_Wholesalers_Supplying_Parts (
WholesalerID INT PRIMARY KEY IDENTITY(1,1),
Wholesaler_Name NVARCHAR(50) NOT NULL,
Wholesaler_Address NVARCHAR(50) NOT NULL
)
GO

IF OBJECT_ID('dbo.Car_Brand', 'U') IS NOT NULL 
    DROP TABLE Car_Brand
GO

CREATE TABLE Car_Brand (
BrandID INT IDENTITY(1,1),
Brand_Name NVARCHAR(50) PRIMARY KEY NOT NULL,
Brand_Country NVARCHAR(50) NOT NULL
)
GO

IF OBJECT_ID('dbo.Class_of_vehicle', 'U') IS NOT NULL 
    DROP TABLE Class_of_vehicle
GO

CREATE TABLE Class_of_vehicle (
Vehicle_Brand NVARCHAR(50) NOT NULL,
ClassID INT,
CarDescription NVARCHAR(50)
)

IF OBJECT_ID('dbo.Repair_journal', 'U') IS NOT NULL 
    DROP TABLE Repair_journal
GO

CREATE TABLE Repair_journal (
RepairID INT PRIMARY KEY IDENTITY(1,1),
Order_Acceptance_Date DATE NOT NULL,
Repair_Status INT,
CarID INT,
Worker INT
)
GO

IF OBJECT_ID('dbo.Repair_details', 'U') IS NOT NULL 
    DROP TABLE Repair_details
GO
CREATE TABLE Repair_details (
RepairID INT,
ServiceID INT,
)
GO



IF OBJECT_ID('dbo.Services', 'U') IS NOT NULL 
    DROP TABLE Services
GO

 CREATE TABLE Services(
ServiceID INT PRIMARY KEY IDENTITY(1,1),
ServiceName NVARCHAR(50),
ServiceDescription NVARCHAR(500)
)
GO

IF OBJECT_ID('dbo.Order_Details', 'U') IS NOT NULL 
    DROP TABLE Order_Details
GO

CREATE TABLE Order_Details (
OrderID INT,
PartID INT,
Order_Description NVARCHAR(200)
)
GO
--KLUCZE OBCE

ALTER TABLE CustomersCars
ADD CONSTRAINT CustomersCars_FK FOREIGN KEY (CarOwner) REFERENCES Customers(CustomerID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Part_Price 
ADD CONSTRAINT Part_Price_FK FOREIGN KEY (PartID) REFERENCES Parts(PartID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Price_of_the_service
ADD CONSTRAINT ServicePrice_FK FOREIGN KEY (ServiceID) REFERENCES Services(ServiceID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Order_Details
ADD CONSTRAINT OrderDetails_FK FOREIGN KEY (OrderID) REFERENCES Orders(OrderID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Leaves
ADD CONSTRAINT Leaves_FK FOREIGN KEY (WorkerID) REFERENCES Workers(WorkerID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Class_of_vehicle
ADD CONSTRAINT Class_of_vehicle_FK FOREIGN KEY (Vehicle_Brand) REFERENCES Car_Brand(Brand_Name)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Orders
ADD CONSTRAINT Orders2_FK FOREIGN KEY (WholesalerID) REFERENCES List_of_Wholesalers_Supplying_Parts(WholesalerID)
ON DELETE CASCADE
ON UPDATE CASCADE 

ALTER TABLE Repair_journal
ADD CONSTRAINT RepairState_FK FOREIGN KEY (Repair_Status) REFERENCES RepairState(StateID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Repair_details
ADD CONSTRAINT RepairDetails_FK FOREIGN KEY (RepairID) REFERENCES Repair_journal(RepairID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Parts
ADD CONSTRAINT PartCategory_FK FOREIGN KEY (PartCategory) REFERENCES PartsCategories(CategoryID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Repair_details
ADD CONSTRAINT ServiceToRepair_FK FOREIGN KEY (ServiceID) REFERENCES Services(ServiceID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE CustomersCars
ADD CONSTRAINT CustomerBrand_FK FOREIGN KEY (Brand) REFERENCES Car_Brand(Brand_Name)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Repair_journal
ADD CONSTRAINT RepairCars_FK FOREIGN KEY (CarID) REFERENCES CustomersCars(CarID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Repair_journal
ADD CONSTRAINT RepairWorker_FK FOREIGN KEY (Worker) REFERENCES Workers(WorkerID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE Order_details
ADD CONSTRAINT OrderPart_FK FOREIGN KEY (PartID) REFERENCES Parts(PartID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE UsedParts
ADD CONSTRAINT UsedInRepair_FK FOREIGN KEY (RepairID) REFERENCES Repair_journal(RepairID)
ON DELETE CASCADE
ON UPDATE CASCADE

ALTER TABLE UsedParts
ADD CONSTRAINT WhatPartsUsed_FK FOREIGN KEY (PartID) REFERENCES Parts(PartID)
ON DELETE CASCADE
ON UPDATE CASCADE

--FUNKCJE I WIDOKI
--=============================================================================
--FUNKCJA LICZ¥CA KOSZT NAPRAWY O ID PODANYM ARGUMENTEM
IF OBJECT_ID('DBO.RepaircostFN','FN') IS NOT NULL
	DROP FUNCTION DBO.RepaircostFN
GO

CREATE FUNCTION RepaircostFN(@ID INT)
RETURNS INT
AS
BEGIN
IF @ID NOT IN (SELECT RepairID FROM Repair_journal)
	RETURN 'BRAK NAPRAWY O PODANYM ID'
ELSE
	DECLARE @RepairDate DATE, @CarClass INT, @Cost INT, @Adder INT
	DECLARE @SupportTable TABLE(Number INT)

	INSERT @SupportTable SELECT DISTINCT P.ServiceID FROM Price_of_the_service P JOIN Services S ON P.ServiceID = S.ServiceID 
	JOIN Repair_details RP ON S.ServiceID = RP.ServiceID JOIN Repair_journal RJ ON RP.RepairID = RJ.RepairID
	WHERE RP.RepairID = @ID


	--WYZNACZANIE KLASY POJAZDU, KTÓREGO DOTYCZY£A NAPRAWA O ZADANYM ID
	SET @CarClass = (SELECT C.ClassID FROM Class_of_vehicle C JOIN CustomersCars CC ON C.Vehicle_Brand = CC.Brand
	JOIN Repair_journal R ON CC.CarID = R.CarID
	WHERE R.RepairID = @ID)

	--WYZNACZANIE DATY, W KTÓREJ ROZPOCZÊTO NAPRAWÊ O ZADANYM ID
	SET @RepairDate = (SELECT R.Order_Acceptance_Date FROM Repair_journal R
	WHERE R.RepairID = @ID)
	--WYZNACZANIE SUMY KOSZTÓW ZA WSZYSTKIE US£UGI Z NAPRAWY O ZADANYM ID
		DECLARE @Iterator int = 0
	SET @Cost = 0
WHILE(1 = 1)
BEGIN
  SELECT @Iterator = MIN(Number)
  FROM @SupportTable WHERE Number > @Iterator
  IF @Iterator IS NULL BREAK

  SET @Adder = (SELECT TOP 1 P.Service_Price FROM Price_of_the_service P  	
	 WHERE (P.ServiceID = @Iterator AND P.Price_From <= @RepairDate)
	ORDER BY P.Price_From DESC)

  SET @Cost = @Cost + @Adder
END

	--WYNIK = SUMA KOSZTÓW POMNO¯ONA PRZEZ KLASÊ POJAZDU
	RETURN (@Cost * @CarClass)

END
GO

--=============================================================================
--FUNKCJA ZWRACAJ¥CA STAN NAPRAWY O ID PODANYM ARGUMENTEM
IF OBJECT_ID('DBO.RepairstateFN','FN') IS NOT NULL
DROP FUNCTION DBO.RepairstateFN
GO

CREATE FUNCTION DBO.RepairstateFN(@ID INT)
RETURNS NVARCHAR(50)
AS
BEGIN

IF @ID NOT IN (SELECT RepairID FROM Repair_journal)
	RETURN 'BRAK NAPRAWY O PODANYM ID'

DECLARE @state NVARCHAR(50)
SET @state = (SELECT RS.StateName FROM RepairState RS JOIN Repair_journal RJ ON 
RS.StateID = RJ.Repair_Status
WHERE RJ.RepairID = @ID)

RETURN @State
END
GO

--=============================================================================
--FUNKCJA ZWRACAJ¥CA LICZBÊ ZAMÓWIEÑ Z£O¯ONYCH W OKREŒLONYM ARGUMENTAMI PRZEDZIALE CZASOWYM
IF OBJECT_ID('DBO.OrderamountFN','FN') IS NOT NULL
DROP FUNCTION DBO.OrderamountFN
GO

CREATE FUNCTION DBO.OrderamountFN(@from DATE, @to DATE)
RETURNS INT
AS
BEGIN
DECLARE @res INT =  (SELECT COUNT(*) FROM Orders
WHERE Orders.OrderDate BETWEEN @from AND @to)

RETURN @res



END
GO

--=============================================================================
--FUNKCJA ZWRACAJ¥CA SUMÊ US£UG Z DANEGO DNIA /
IF OBJECT_ID('Order_In_Day','FN') IS NOT NULL
DROP FUNCTION Order_In_Day
GO

CREATE FUNCTION Order_In_Day(@day DATE)
RETURNS INT
AS
BEGIN
DECLARE @sum INT =  (SELECT SUM(Service_Price) FROM Repair_journal AS RJ JOIN Repair_details AS RD ON RJ.RepairID = RD.RepairID JOIN Price_of_the_service AS PS ON RD.ServiceID = PS.ServiceID
GROUP BY Order_Acceptance_Date
HAVING RJ.Order_Acceptance_Date = @day)

RETURN @sum

END
GO





--====================================================================================
--FUNKCJA LICZ¥CA ILOŒÆ AUT DANEJ MARKI /
IF OBJECT_ID('How_many_cars','FN') IS NOT NULL
DROP FUNCTION How_many_cars
GO

CREATE FUNCTION DBO.How_many_cars(@type nvarchar(50))
RETURNS INT
AS
BEGIN
DECLARE @res INT =  (SELECT COUNT(*) FROM CustomersCars
WHERE Brand = @type)

RETURN @res



END
GO


--====================================================================================
--WIDOK Z KLIENTAMI POSIADAJ¥CYMI NAJWIÊCEJ NAPRAW
IF OBJECT_ID ( 'Customer_with_most_repairs_view', 'v' ) IS NOT NULL   
    DROP VIEW Customer_with_most_repairs_view;  
GO
CREATE VIEW Customer_with_most_repairs_view
AS

SELECT TOP 1 WITH TIES C.*,COUNT(*) LiczbaNapraw FROM Repair_journal RJ JOIN
CustomersCars CC ON RJ.CarID = CC.CarID JOIN Customers C ON CC.CarOwner = C.CustomerID
GROUP BY C.CustomerID,C.PESEL,C.Name,C.Surname
ORDER BY LiczbaNapraw DESC
GO
--=============================================================================
--WIDOK MARKI SAMOCHODU, KTÓRA WYSTÊPUJE NAJCZÊŒCIEJ POŒRÓD SAMOCHODÓW KLIENTÓW
IF OBJECT_ID ( 'Most_common_car_brand_view', 'v' ) IS NOT NULL   
    DROP VIEW Most_common_car_brand_view;  
GO
CREATE VIEW Most_common_car_brand_view
AS

SELECT TOP 1 WITH TIES C.*,COUNT(*) LiczbaAut FROM Car_Brand C JOIN CustomersCars CC
ON C.Brand_Name = CC.Brand
GROUP BY C.BrandID,C.Brand_Name,C.Brand_Country
ORDER BY LiczbaAut DESC
GO
--=============================================================================
--WIDOK NAPRAW KTÓRE NIE ZOSTA£Y UKOÑCZONE /
IF OBJECT_ID ( 'Not_finished_repairs', 'v' ) IS NOT NULL   
    DROP VIEW Not_finished_repairs;  
GO
CREATE VIEW Not_finished_repairs
AS

SELECT RepairID, Repair_Status FROM Repair_journal WHERE Repair_Status != 1
GO


--=============================================================================
--WIDOK NAJCZÊŒCIEJ ŒWIADCZONEJ US£UGI /
IF OBJECT_ID ( 'Most_common_service', 'v' ) IS NOT NULL  
    DROP VIEW Most_common_service;
GO
CREATE VIEW Most_common_service
AS

SELECT TOP 1 WITH TIES t.ServiceName, t.IleRazyUsluga FROM
(
SELECT RD.ServiceID, S.ServiceName, Count(RJ.RepairID) AS IleRazyUsluga FROM Repair_journal AS RJ JOIN Repair_details AS RD ON RJ.RepairID = RD.RepairID 
JOIN Price_of_the_service AS PS ON RD.ServiceID = PS.ServiceID JOIN Services AS S ON RD.ServiceID = S.ServiceID
GROUP BY RD.ServiceID, S.ServiceName
) AS t
GROUP BY t.ServiceName, t.IleRazyUsluga, t.ServiceID
ORDER BY t.IleRazyUsluga DESC

GO

--=============================================================================
 --WIDOK NAJWIÊCEJ ZARABIAJ¥CEGO PRACOWNIKA
IF OBJECT_ID ( 'Most_expensive_service', 'v' ) IS NOT NULL   
    DROP VIEW Most_expensive_service;  
GO
CREATE VIEW Most_expensive_service
AS

SELECT TOP 1 WITH TIES WorkerID AS Pracownik, Salary AS Pensja FROM Workers
ORDER BY Salary DESC
GO
--=============================================================================
--PROCEDURY SK£ADOWANE I WYZWALACZE

--Procedura maj¹ca na celu dodanie nowej naprawy do dziennika napraw
IF OBJECT_ID('dbo.pAddRepair', 'P') IS NOT NULL
DROP PROCEDURE dbo.pAddRepair
GO

CREATE PROCEDURE dbo.pAddRepair (@acceptdate DATE, @repstatus INT, @CarId INT, @WorkerId INT)
AS
	BEGIN TRY
					DECLARE @tranCount INT = @@TRANCOUNT

					IF @tranCount = 0
						BEGIN TRAN pAddRepair
					ELSE
						SAVE TRAN pAddRepair


						IF NOT EXISTS (SELECT StateID FROM RepairState WHERE StateID = @repstatus)
						BEGIN						
							RAISERROR('Podano niepoprawny status naprawy',16,1)
						END
						IF NOT EXISTS (SELECT CarID FROM CustomersCars WHERE CarID = @CarID)
						BEGIN
							RAISERROR ('Nie istnieje samochód o zadanym ID',16,1)
						END
						IF  NOT EXISTS (SELECT WorkerID FROM Workers WHERE WorkerID = @WorkerId)
						BEGIN
							RAISERROR ('Brak pracownika o podanym ID',16,1)
						END

						INSERT INTO Repair_Journal VALUES(@acceptdate, @repstatus, @CarId, @WorkerID)				
									
						IF @tranCount = 0
							COMMIT TRAN pAddRepair
	END TRY
	BEGIN CATCH
					ROLLBACK TRAN pAddRepair
					SELECT ERROR_MESSAGE() AS ERROR				

	END CATCH
GO

--====================================================================================
--Procedura maj¹ca na celu aktualizacjê ceny us³ugi
IF OBJECT_ID('dbo.pUpdatePrice', 'P') IS NOT NULL
DROP PROCEDURE dbo.pUpdatePrice
GO

CREATE PROCEDURE dbo.pUpdatePrice (@ServiceId INT, @Price MONEY)
AS
	BEGIN TRY
					DECLARE @tranCount INT = @@TRANCOUNT

					IF @tranCount = 0
						BEGIN TRAN pUpdatePrice
					ELSE
						SAVE TRAN pUpdatePrice


						IF NOT EXISTS (SELECT ServiceID FROM Price_of_the_service WHERE ServiceID = @ServiceId)
						BEGIN						
							RAISERROR('Brak us³ugi o podanym numerze',16,1)
						END
						
						INSERT INTO Price_of_the_service VALUES(@ServiceId,GETDATE(),@Price)				
									
						IF @tranCount = 0
							COMMIT TRAN pUpdatePrice
	END TRY
	BEGIN CATCH
					ROLLBACK TRAN pUpdatePrice
					SELECT ERROR_MESSAGE() AS ERROR					

	END CATCH
GO

--====================================================================================
--Procedura maj¹ca na celu aktualizacjê statusu naprawy
IF OBJECT_ID('dbo.pUpdateState', 'P') IS NOT NULL
DROP PROCEDURE dbo.pUpdateState
GO

CREATE PROCEDURE dbo.pUpdateState (@Repairid INT, @State INT)
AS
	BEGIN TRY
					DECLARE @tranCount INT = @@TRANCOUNT

					IF @tranCount = 0
						BEGIN TRAN pUpdateState
					ELSE
						SAVE TRAN pUpdateState


						IF NOT EXISTS (SELECT RepairID FROM Repair_journal WHERE RepairID = @RepairId)
						BEGIN						
							RAISERROR('Brak naprawy o podanym numerze',16,1)
						END
						IF NOT EXISTS (SELECT StateID FROM RepairState WHERE StateID = @State)
						BEGIN						
							RAISERROR('Podano nieprawid³owy status naprawy',16,1)
						END
						
						UPDATE Repair_journal
						SET Repair_Status = @State
						WHERE RepairID = @Repairid			
									
						IF @tranCount = 0
							COMMIT TRAN pUpdateState
	END TRY
	BEGIN CATCH
					ROLLBACK TRAN pUpdateState
					SELECT ERROR_MESSAGE() AS ERROR					

	END CATCH
GO

--====================================================================================
--PROCEDURA DODAJ¥CA NOWEGO PRACOWNIKA /


IF OBJECT_ID('dbo.pAddWorker', 'P') IS NOT NULL
DROP PROCEDURE dbo.pAddWorker
GO

CREATE PROCEDURE dbo.pAddWorker (@pes char(11), @Name nvarchar(50), @Surname nvarchar(50), @Salary INT, @Birthdate DATE)
AS
	BEGIN TRY
					DECLARE @tranCount INT = @@TRANCOUNT

					IF @tranCount = 0
						BEGIN TRAN pAddWorker
					ELSE
						SAVE TRAN pAddWorker


						IF EXISTS (SELECT PESEL FROM Workers WHERE PESEL = @pes)
						BEGIN
							RAISERROR('Pracownik o podanym PESELu ju¿ znajduje siê w liœcie pracowników',16,1)
						END

						INSERT INTO Workers VALUES(@pes, @Name, @Surname, @Salary, @Birthdate)				
									
						IF @tranCount = 0
							COMMIT TRAN pAddWorker
	END TRY
	BEGIN CATCH
					ROLLBACK TRAN pAddWorker
					SELECT ERROR_MESSAGE() AS ERROR				

	END CATCH
GO


--====================================================================================
--PROCEDURA ZMIENIAJ¥CA OPIS US£UGI /


IF OBJECT_ID('dbo.pUpdateServiceDescription', 'P') IS NOT NULL
DROP PROCEDURE dbo.pUpdateServiceDescription
GO

CREATE PROCEDURE dbo.pUpdateServiceDescription (@ServID INT, @Desc nvarchar(500))
AS
	BEGIN TRY
					DECLARE @tranCount INT = @@TRANCOUNT

					IF @tranCount = 0
						BEGIN TRAN pUpdateServiceDescription
					ELSE
						SAVE TRAN pUpdateServiceDescription


						IF NOT EXISTS (SELECT ServiceID FROM Services WHERE ServiceID = @ServID)
						BEGIN						
							RAISERROR('Podano nieprawid³owy status naprawy',16,1)
						END
						
						UPDATE Services
						SET ServiceDescription = @Desc
						WHERE ServiceID = @ServID			
									
						IF @tranCount = 0
							COMMIT TRAN pUpdateServiceDescription
	END TRY
	BEGIN CATCH
					ROLLBACK TRAN pUpdateServiceDescription
					SELECT ERROR_MESSAGE() AS ERROR					

	END CATCH
GO
--====================================================================================
--TRIGGER WYSWIETLAJACY KOMUNIKAT O ZATRUDNIENIU NOWEGO PRACOWNIKA
IF OBJECT_ID('WorkerTr','TR') IS NOT NULL
	DROP TRIGGER WorkerTr
GO

CREATE TRIGGER WorkerTr ON Workers
AFTER INSERT
AS
PRINT 'Nowy pracownik zosta³ dodany'

GO
--====================================================================================
--TRIGGER WYSWIETLAJACY KOMUNIKAT O AKTUALIZACJI WYNAGRODZENIA
IF OBJECT_ID('SalaryTr','TR') IS NOT NULL
	DROP TRIGGER SalaryTr
GO

CREATE TRIGGER SalaryTr ON Workers
AFTER UPDATE
AS
PRINT 'Stawka zosta³a zaktualizowana'

GO

--====================================================================================
--TRIGGER WYSWIETLAJACY KOMUNIKAT O DODANIU NOWEJ NAPRAWY DO DZIENNIKA NAPRAW /
IF OBJECT_ID('RepairTr','TR') IS NOT NULL
	DROP TRIGGER RepairTr
GO

CREATE TRIGGER RepairTr ON Repair_journal
AFTER INSERT
AS
PRINT 'Nowa naprawa zosta³a dodana'

GO
--====================================================================================
--TRIGGER WYSWIETLAJACY KOMUNIKAT O ZMIANIE OPISU NAPRAWY /
IF OBJECT_ID('DescpritionTr','TR') IS NOT NULL
	DROP TRIGGER DescpritionTr
GO

CREATE TRIGGER DescpritionTr ON Order_Details
AFTER UPDATE
AS
PRINT 'Opis naprawy zosta³ zaktualizowany'

GO

--====================================================================================
--TRIGGER WYSWIETLAJACY KOMUNIKAT O ZMIANIE STANU NAPRAWY /
IF OBJECT_ID('StateTr','TR') IS NOT NULL
	DROP TRIGGER StateTr
GO

CREATE TRIGGER StateTr ON Repair_journal
AFTER UPDATE
AS
PRINT 'Stan naprawy zosta³ zaktualizowany'

GO

--====================================================================================