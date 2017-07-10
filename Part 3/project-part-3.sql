create domain posreal as double precision
check         (value > 0.0);

create domain posint as integer
check         (value > 0);

-- all measures in this type are in inches
create type dimensions as (length_ posreal,
                           width   posreal,
                           height  posreal);

create table Supplier(supplierID  varchar(10),
                      name_       nchar varying(50)
                                  not null,
                      phone       varchar(12),
                      address     nchar varying(100),
                      country     char(2),
                      website     nchar varying(50),
                      primary key (supplierID));

create table Designer(designerID  varchar(10),
                      name_       nchar varying(50)
                                  not null,
                      phone       varchar(12),
                      address     nchar varying(100),
                      country     char(2),
                      website     nchar varying(50),
                      designFocus nchar varying(100),
                      primary key (designerID));

create table Set_(setID         varchar(10),
                  name_         nchar varying(50)
                                not null,
                  catalogYear   numeric(4,0),
                  catalogNumber integer
                                not null,
                  style_        nchar varying(30),
                  primary key   (setID));

create table Model(modelNumber varchar(10),
                   name_       nchar varying(50)
                               not null,
                   material    nchar varying(30),
                   upholstery  nchar varying(30),
                   durability  nchar varying(30),
                   color       nchar varying(30),
                   primary key (modelNumber));

create table Item(sku         varchar(10),
                  dimensions  dimensions
                              not null, -- anti-redundancy constraint
                  condition   nchar varying(30),
                  weightLimit posreal, -- in pounds of weight
                  primary key (sku));

create table DistributionCenter(centerID    varchar(10),
                                name_       nchar varying(50)
                                            not null,
                                phone       varchar(12),
                                address     nchar varying(100),
                                country     char(2),
                                website     nchar varying(50),
                                primary key (centerID));

create table make(supplierID  varchar(10),
                  designerID  varchar(10),
                  setID       varchar(10),
                  primary key (supplierID,
                               designerID,
                               setID),
                  foreign key (supplierID)
                              references Supplier,
                  foreign key (designerID)
                              references Designer,
                  foreign key (setID)
                              references Set_);

create table contains_(setID       varchar(10),
                       modelNumber varchar(10),
                       count_      posint,
                       primary key (setID,
                                    modelNumber),
                       foreign key (setID)
                                   references Set_,
                       foreign key (modelNumber)
                                   references Model);

create table describes(modelNumber varchar(10)
                                   not null,
                       sku         varchar(10),
                       primary key (sku),
                       foreign key (modelNumber)
                                   references Model,
                       foreign key (sku)
                                   references Item);

create table canOrderFrom(centerID    varchar(10),
                          supplierID  varchar(10),
                          leadTime    double precision, -- in days
                          primary key (centerID,
                                       supplierID),
                          foreign key (centerID)
                                      references DistributionCenter,
                          foreign key (supplierID)
                                      references Supplier,
                          check       (leadTime >= 0.0));

create table stocks(centerID    varchar(10)
                                not null,
                    sku         varchar(10),
                    primary key (sku),
                    foreign key (centerID)
                                references DistributionCenter,
                    foreign key (sku)
                                references Item);

create table Chair(sku          varchar(10),
                   numberOfLegs posint,
                   hasCushion   boolean,
                   hasArms      boolean,
                   backHeight   posreal, -- in inches
                   seatHeight   posreal, -- in inches
                   primary key  (sku),
                   foreign key  (sku)
                                references Item);

create table Table_(sku           varchar(10),
                    numberOfLegs  posint,
                    numberOfSeats posint,
                    shape         nchar varying(30),
                    primary key   (sku),
                    foreign key   (sku)
                                  references Item);

create table Desk(sku             varchar(10),
                  angle           double precision, -- in degrees, possibly negative
                  numberOfDrawers posint,
                  primary key     (sku),
                  foreign key     (sku)
                                  references Item,
                  check              (angle > -360.0
                                  and angle < 360.0));

create table Stool(sku          varchar(10),
                   numberOfLegs posint,
                   hasCushion   boolean,
                   hasSwivel    boolean,
                   primary key  (sku),
                   foreign key  (sku)
                                references Item);

create table Cabinet(sku                  varchar(10),
                     numberOfCompartments posint,
                     capacity             nchar varying(30),
                     primary key          (sku),
                     foreign key          (sku)
                                          references Item);

create table Bedframe(sku         varchar(10),
                      size_       nchar varying(30),
                      depth_      double precision, -- in inches, possibly negative
                      primary key (sku),
                      foreign key (sku)
                                  references Item);

create table features_Feature(modelNumber varchar(10),
                              description nchar varying(50),
                              count_      posint,
                              primary key (modelNumber,
                                           description),
                              foreign key (modelNumber)
                                          references Model);
