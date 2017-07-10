CREATE TABLE Supplier
  (
     supplierID VARCHAR(10) CHARACTER SET ASCII,
     name_      VARCHAR(50) CHARACTER SET utf8mb4 NOT NULL,
     phone      VARCHAR(12) CHARACTER SET ASCII,
     address    VARCHAR(100) CHARACTER SET utf8mb4,
     country    CHAR(2) CHARACTER SET ASCII DEFAULT 'US',
     website    VARCHAR(50) CHARACTER SET utf8mb4,
     PRIMARY KEY(supplierID),
     CHECK (country REGEXP '^[A-Z]{2}$'),
     CHECK (phone REGEXP '^[0-9]{7,12}$')
  );

CREATE TABLE Designer
  (
     designerID  VARCHAR(10) CHARACTER SET ASCII,
     name_       VARCHAR(50) CHARACTER SET utf8mb4 NOT NULL,
     phone       VARCHAR(12) CHARACTER SET ASCII,
     address     VARCHAR(100) CHARACTER SET utf8mb4,
     country     CHAR(2) CHARACTER SET ASCII DEFAULT 'US',
     website     VARCHAR(50) CHARACTER SET utf8mb4,
     designFocus VARCHAR(100) CHARACTER SET utf8mb4,
     PRIMARY KEY(designerID),
     CHECK (country REGEXP '^[A-Z]{2}$'),
     CHECK (phone REGEXP '^[0-9]{7,12}$')
  );

CREATE TABLE Set_
  (
     setID         VARCHAR(10) CHARACTER SET ASCII,
     name_         VARCHAR(50) CHARACTER SET utf8mb4 NOT NULL,
     catalogYear   DECIMAL(4, 0) UNSIGNED,
     catalogNumber BIGINT UNSIGNED ZEROFILL NOT NULL,
     style_        VARCHAR(30) CHARACTER SET utf8mb4,
     PRIMARY KEY(setID)
  );

CREATE TABLE Model
  (
     modelNumber VARCHAR(10) CHARACTER SET ASCII,
     name_       VARCHAR(50) CHARACTER SET utf8mb4 NOT NULL,
     material    VARCHAR(30) CHARACTER SET utf8mb4,
     upholstery  VARCHAR(30) CHARACTER SET utf8mb4,
     durability  VARCHAR(30) CHARACTER SET utf8mb4,
     color       VARCHAR(30) CHARACTER SET utf8mb4,
     PRIMARY KEY(modelNumber)
  );

CREATE TABLE Item
  (
     sku         VARCHAR(10) CHARACTER SET ASCII,
     length_     DOUBLE UNSIGNED,
     width       DOUBLE UNSIGNED,
     height      DOUBLE UNSIGNED,
     condition_  VARCHAR(30) CHARACTER SET utf8mb4,
     weightLimit DOUBLE UNSIGNED,
     PRIMARY KEY(sku),
     CHECK (length_ > 0.0),
     CHECK (width > 0.0),
     CHECK (height > 0.0),
     CHECK (weightLimit > 0.0)
  );

CREATE TABLE DistributionCenter
  (
     centerID VARCHAR(10) CHARACTER SET ASCII,
     name_    VARCHAR(50) CHARACTER SET utf8mb4 NOT NULL,
     phone    VARCHAR(12) CHARACTER SET ASCII,
     address  VARCHAR(100) CHARACTER SET utf8mb4,
     country  CHAR(2) CHARACTER SET ASCII DEFAULT 'US',
     website  VARCHAR(50) CHARACTER SET utf8mb4,
     PRIMARY KEY(centerID),
     CHECK (country REGEXP '^[A-Z]{2}$'),
     CHECK (phone REGEXP '^[0-9]{7,12}$')
  );

CREATE TABLE make
  (
     supplierID VARCHAR(10) CHARACTER SET ASCII,
     designerID VARCHAR(10) CHARACTER SET ASCII,
     setID      VARCHAR(10) CHARACTER SET ASCII,
     PRIMARY KEY(supplierID, designerID, setID),
     FOREIGN KEY(supplierID) REFERENCES Supplier(supplierID),
     FOREIGN KEY(designerID) REFERENCES Designer(designerID),
     FOREIGN KEY(setID) REFERENCES Set_(setID)
  );

CREATE TABLE contains_
  (
     setID       VARCHAR(10) CHARACTER SET ASCII,
     modelNumber VARCHAR(10) CHARACTER SET ASCII,
     count_      TINYINT UNSIGNED DEFAULT 1,
     PRIMARY KEY(setID, modelNumber),
     FOREIGN KEY(setID) REFERENCES Set_(setID),
     FOREIGN KEY(modelNumber) REFERENCES Model(modelNumber),
     CHECK (count_ > 0)
  );

CREATE TABLE describes
  (
     modelNumber VARCHAR(10) CHARACTER SET ASCII NOT NULL,
     sku         VARCHAR(10) CHARACTER SET ASCII,
     PRIMARY KEY(sku),
     FOREIGN KEY(modelNumber) REFERENCES Model(modelNumber),
     FOREIGN KEY(sku) REFERENCES Item(sku)
  );

CREATE TABLE canOrderFrom
  (
     centerID   VARCHAR(10) CHARACTER SET ASCII,
     supplierID VARCHAR(10) CHARACTER SET ASCII,
     leadTime   DOUBLE UNSIGNED,
     PRIMARY KEY(centerID, supplierID),
     FOREIGN KEY(centerID) REFERENCES DistributionCenter(centerID),
     FOREIGN KEY(supplierID) REFERENCES Supplier(supplierID)
  );

CREATE TABLE stocks
  (
     centerID VARCHAR(10) CHARACTER SET ASCII NOT NULL,
     sku      VARCHAR(10) CHARACTER SET ASCII,
     PRIMARY KEY(sku),
     FOREIGN KEY(centerID) REFERENCES DistributionCenter(centerID),
     FOREIGN KEY(sku) REFERENCES Item(sku)
  );

CREATE TABLE Chair
  (
     sku          VARCHAR(10) CHARACTER SET ASCII,
     numberOfLegs TINYINT UNSIGNED DEFAULT 4,
     hasCushion   BOOL DEFAULT false,
     hasArms      BOOL,
     backHeight   DOUBLE UNSIGNED,
     seatHeight   DOUBLE UNSIGNED,
     PRIMARY KEY(sku),
     FOREIGN KEY(sku) REFERENCES Item(sku),
     CHECK (numberOfLegs > 0),
     CHECK (backHeight > 0.0),
     CHECK (seatHeight > 0.0)
  );

CREATE TABLE Table_
  (
     sku           VARCHAR(10) CHARACTER SET ASCII,
     numberOfLegs  TINYINT UNSIGNED DEFAULT 4,
     numberOfSeats TINYINT UNSIGNED,
     shape         VARCHAR(30) CHARACTER SET utf8mb4,
     PRIMARY KEY(sku),
     FOREIGN KEY(sku) REFERENCES Item(sku),
     CHECK (numberOfLegs > 0),
     CHECK (numberOfSeats > 0)
  );

CREATE TABLE Desk
  (
     sku             VARCHAR(10) CHARACTER SET ASCII,
     angle           DOUBLE DEFAULT 0.0,
     numberOfDrawers TINYINT UNSIGNED,
     PRIMARY KEY(sku),
     FOREIGN KEY(sku) REFERENCES Item(sku),
     CHECK (angle > -360.0 AND angle < 360.0),
     CHECK (numberOfDrawers > 0)
  );

CREATE TABLE Stool
  (
     sku          VARCHAR(10) CHARACTER SET ASCII,
     numberOfLegs TINYINT UNSIGNED,
     hasCushion   BOOL,
     hasSwivel    BOOL,
     PRIMARY KEY(sku),
     FOREIGN KEY(sku) REFERENCES Item(sku),
     CHECK (numberOfLegs > 0)
  );

CREATE TABLE Cabinet
  (
     sku                  VARCHAR(10) CHARACTER SET ASCII,
     numberOfCompartments TINYINT UNSIGNED,
     capacity             VARCHAR(30) CHARACTER SET utf8mb4,
     PRIMARY KEY(sku),
     FOREIGN KEY(sku) REFERENCES Item(sku),
     CHECK (numberOfCompartments > 0)
  );

CREATE TABLE Bedframe
  (
     sku    VARCHAR(10) CHARACTER SET ASCII,
     size_  VARCHAR(30) CHARACTER SET utf8mb4,
     depth_ DOUBLE,
     PRIMARY KEY(sku),
     FOREIGN KEY(sku) REFERENCES Item(sku)
  );

CREATE TABLE features_Feature
  (
     modelNumber VARCHAR(10) CHARACTER SET ASCII,
     description VARCHAR(50) CHARACTER SET utf8mb4,
     count_      TINYINT UNSIGNED DEFAULT 1,
     PRIMARY KEY(modelNumber, description),
     FOREIGN KEY(modelNumber) REFERENCES Model(modelNumber),
     CHECK (count_ > 0)
  );
