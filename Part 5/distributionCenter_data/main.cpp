//Code has been copied directly from supplier_data\main.cpp
//file names for input files have been altered to fit new data
//ouput performed as desired

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

  srand (time(NULL));
  string line;
  int i = 0;

  //output file
  ofstream output_file;

  //Suffixes for websites
  string domainSuffix[5];
  domainSuffix[0] = ".com";
  domainSuffix[1] = ".net";
  domainSuffix[2] = ".org";
  domainSuffix[3] = ".biz";
  domainSuffix[4] = ".info";

  string supplierIDs[50];
  string names[50];
  string countries[249];
  string phones[50];
  string websiteNames[50];
  string addresses[50];

  //supplierIDs.txt
  ifstream supplierIDs_file("centerIDs.txt");
  //names.txt
  ifstream names_file("names.txt");
  //countries.txt
  ifstream countries_file("countries.txt");
  //phones.txt
  ifstream phones_file("phones.txt");
  //websiteNames.txt
  ifstream websiteNames_file("websites.txt");
  //addresses.txt
  ifstream addresses_file("addresses.txt");

  //Read "supplierIDs.txt" into an array

  if(supplierIDs_file.is_open()){
    while(getline (supplierIDs_file,line)){
      supplierIDs[i] = line;
      i++;
    }
    supplierIDs_file.close();
  }
  else cout << "Unable to open supplierIDs file" << endl;

  i = 0;

  //Read "names.txt" to names array

  if(names_file.is_open()){
    while(getline (names_file,line)){
      names[i] = line;
      i++;
    }
    names_file.close();
  }
  else cout << "Unable to open names file" << endl;

  i = 0;

  //Read "countries.txt" to countries array

  if(countries_file.is_open()){
    while(getline (countries_file,line)){
      countries[i] = line;
      i++;
    }
    countries_file.close();
  }
  else cout << "Unable to open countries file" << endl;

  i = 0;

  //Read "phones.txt" to phones array

  if(phones_file.is_open()){
    while(getline (phones_file,line)){
      phones[i] = line;
      i++;
    }
    phones_file.close();
  }
  else cout << "Unable to open phones file" << endl;

  i = 0;

  //read "websiteNames.txt" into an array

  if(websiteNames_file.is_open()){
    while(getline (websiteNames_file,line)){
      websiteNames[i] = line;
      i++;
    }
    websiteNames_file.close();
  }
  else cout << "Unable to open websiteNames file" << endl;

  i = 0;

  //Read "addresses.txt" to addresses array

  if(addresses_file.is_open()){
    while(getline (addresses_file,line)){
      addresses[i] = line;
      i++;
    }
    addresses_file.close();
  }
  else cout << "Unable to open addresses file" << endl;

  i = 0;

  //output data to supplier_data.txt
  //supplierIDs
  //name
  //phone
  //address
  //country
  //website
  output_file.open("distributionCenter_data.csv");
  while(i < 50){
    output_file << supplierIDs[i] << ",";
    output_file << names[i] << ",";
    output_file << phones[i] << ",";
    output_file << "\"" << addresses[i] << "\"" << ",";
    output_file << countries[rand()%249] << ",";
    output_file << "www." << websiteNames[i] << domainSuffix[rand()%5];
    output_file << endl;
    i++;
  }


  return 0;
}
