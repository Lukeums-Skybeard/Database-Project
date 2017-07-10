create table Supplier(supplierID  varchar(10) character set ascii,
                      name_       varchar(50) character set utf8mb4
                                  not null,
                      phone       varchar(12) character set ascii,
                      address     varchar(100) character set utf8mb4,
                      country     char(2) character set ascii,
                      website     varchar(50) character set utf8mb4,
                      primary key (supplierID));

create table Designer(designerID  varchar(10) character set ascii,
                      name_       varchar(50) character set utf8mb4
                                  not null,
                      phone       varchar(12) character set ascii,
                      address     varchar(100) character set utf8mb4,
                      country     char(2) character set ascii,
                      website     varchar(50) character set utf8mb4,
                      designFocus varchar(100) character set utf8mb4,
                      primary key (designerID));

create table Set_(setID         varchar(10) character set ascii,
                  name_         varchar(50) character set utf8mb4
                                not null,
                  catalogYear   numeric(4,0),
                  catalogNumber integer
                                not null,
                  style_        varchar(30) character set utf8mb4,
                  primary key   (setID));

create table Model(modelNumber varchar(10) character set ascii,
                   name_       varchar(50) character set utf8mb4
                               not null,
                   material    varchar(30) character set utf8mb4,
                   upholstery  varchar(30) character set utf8mb4,
                   durability  varchar(30) character set utf8mb4,
                   color       varchar(30) character set utf8mb4,
                   primary key (modelNumber));

create table Item(sku          varchar(10) character set ascii,
                  length_      double, -- in inches
                  width        double, -- in inches
                  height       double, -- in inches
                  condition_   varchar(30) character set utf8mb4,
                  weightLimit  double, -- in pounds of weight
                  primary key  (sku));

create table DistributionCenter(centerID    varchar(10) character set ascii,
                                name_       varchar(50) character set utf8mb4
                                            not null,
                                phone       varchar(12) character set ascii,
                                address     varchar(100) character set utf8mb4,
                                country     char(2) character set ascii,
                                website     varchar(50) character set utf8mb4,
                                primary key (centerID));

create table make(supplierID  varchar(10) character set ascii,
                  designerID  varchar(10) character set ascii,
                  setID       varchar(10) character set ascii,
                  primary key (supplierID,
                               designerID,
                               setID),
                  foreign key (supplierID)
                              references Supplier (supplierID),
                  foreign key (designerID)
                              references Designer (designerID),
                  foreign key (setID)
                              references Set_ (setID));

create table contains_(setID       varchar(10) character set ascii,
                       modelNumber varchar(10) character set ascii,
                       count_      integer,
                       primary key (setID,
                                    modelNumber),
                       foreign key (setID)
                                   references Set_ (setID),
                       foreign key (modelNumber)
                                   references Model (modelNumber));

create table describes(modelNumber varchar(10) character set ascii
                                   not null,
                       sku         varchar(10) character set ascii,
                       primary key (sku),
                       foreign key (modelNumber)
                                   references Model (modelNumber),
                       foreign key (sku)
                                   references Item (sku));

create table canOrderFrom(centerID    varchar(10) character set ascii,
                          supplierID  varchar(10) character set ascii,
                          leadTime    double, -- in days
                          primary key (centerID,
                                       supplierID),
                          foreign key (centerID)
                                      references DistributionCenter (centerID),
                          foreign key (supplierID)
                                      references Supplier (supplierID));

create table stocks(centerID    varchar(10) character set ascii
                                not null,
                    sku         varchar(10) character set ascii,
                    primary key (sku),
                    foreign key (centerID)
                                references DistributionCenter (centerID),
                    foreign key (sku)
                                references Item (sku));

create table Chair(sku          varchar(10) character set ascii,
                   numberOfLegs integer,
                   hasCushion   boolean,
                   hasArms      boolean,
                   backHeight   double, -- in inches
                   seatHeight   double, -- in inches
                   primary key  (sku),
                   foreign key  (sku)
                                references Item (sku));

create table Table_(sku           varchar(10) character set ascii,
                    numberOfLegs  integer,
                    numberOfSeats integer,
                    shape         varchar(30) character set utf8mb4,
                    primary key   (sku),
                    foreign key   (sku)
                                  references Item (sku));

create table Desk(sku             varchar(10) character set ascii,
                  angle           double, -- in degrees, possibly negative
                  numberOfDrawers integer,
                  primary key     (sku),
                  foreign key     (sku)
                                  references Item (sku));

create table Stool(sku          varchar(10) character set ascii,
                   numberOfLegs integer,
                   hasCushion   boolean,
                   hasSwivel    boolean,
                   primary key  (sku),
                   foreign key  (sku)
                                references Item (sku));

create table Cabinet(sku                  varchar(10) character set ascii,
                     numberOfCompartments integer,
                     capacity             varchar(30) character set utf8mb4,
                     primary key          (sku),
                     foreign key          (sku)
                                          references Item (sku));

create table Bedframe(sku         varchar(10) character set ascii,
                      size_       varchar(30) character set utf8mb4,
                      depth_      double, -- in inches, possibly negative
                      primary key (sku),
                      foreign key (sku)
                                  references Item (sku));

create table features_Feature(modelNumber varchar(10) character set ascii,
                              description varchar(50) character set utf8mb4,
                              count_      integer,
                              primary key (modelNumber,
                                           description),
                              foreign key (modelNumber)
                                          references Model (modelNumber));
