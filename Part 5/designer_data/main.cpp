#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  srand (time(NULL));

  int i = 0;

  ofstream output_file;

  string line;

  ifstream designerIDs_file("designerIDs.txt");
  ifstream firstNames_file("firstNames.txt");
  ifstream lastNames_file("lastNames.txt");
  ifstream phones_file("phones.txt");
  ifstream designerAddresses_file("designerAddresses.txt");
  ifstream countries_file("countries.txt");
  ifstream designFocuses_file("designFocuses.txt");

  string designerIDs[50];
  string firstNames[50];
  string lastNames[50];
  string phones[50];
  string designerAddresses[50];
  string countries[249];
  string websites[50];
  string designFocuses[11];
  string domainSuffix[5];

  domainSuffix[0] = ".com";
  domainSuffix[1] = ".net";
  domainSuffix[2] = ".org";
  domainSuffix[3] = ".biz";
  domainSuffix[4] = ".info";

  //Read "designerIDs.txt" into string array

  if(designerIDs_file.is_open()){
    while (getline (designerIDs_file,line)){
      designerIDs[i] = line;
      i++;
    }
    designerIDs_file.close();
  }
  else cout << "Unable to open ID file" << endl;

  i = 0;

  //Read "firstNames.txt" into string array

  if(firstNames_file.is_open()){
    while(getline (firstNames_file,line)){
      firstNames[i] = line;
      i++;
    }
    firstNames_file.close();
  }
  else cout << "Unable to open firstNames file" << endl;

  i = 0;

  //Read "lastNames.txt" into string array

  if(lastNames_file.is_open()){
    while(getline (lastNames_file,line)){
      lastNames[i] = line;
      i++;
    }
    lastNames_file.close();
  }
  else cout << "Unable to open lastNames file" << endl;

  i = 0;

  //Read "phones.txt" into string array

  if(phones_file.is_open()){
    while(getline (phones_file,line)){
      phones[i] = line;
      i++;
    }
    phones_file.close();
  }
  else cout << "Unable to open phones file" << endl;

  i = 0;

  //Read "designerAddresses.txt into string array

  if(designerAddresses_file.is_open()){
    while (getline (designerAddresses_file,line)){
      designerAddresses[i] = line;
      i++;
    }
    designerAddresses_file.close();
  }
  else cout << "Unable to open Addresses file" << endl;

  i = 0;

  //Read "countries.txt" into string array

  if(countries_file.is_open()){
    while(getline (countries_file,line)){
      countries[i] = line;
      i++;
    }
    countries_file.close();
  }
  else cout << "Unable to open countries file" << endl;

  i = 0;

  //Create website addresses based on names, save them into websites array
  while (i < 50){
    websites[i] = "www." + firstNames[i] + lastNames[i] + domainSuffix[rand()%5];
    i++;
  }

  i = 0;

  //Read "designFocuses.txt" into string array

  if(designFocuses_file.is_open()){
    while(getline (designFocuses_file,line)){
      designFocuses[i] = line;
      i++;
    }
    designFocuses_file.close();
  }
  else cout << "Unable to open designFocuses file" << endl;

  i = 0;

  //Write to output file
  //use a loop to write output to a file
    //SUBTASKS
      //write designerID on a line, end line
      //write a first name then a last name on a line, end line
      //write a phone number on a line, end line
      //write an address on a line, end line
      //write a random country on a line, end line
      //write a website on a line, end line
      //write a random design focus on a line, end line
      //end line for spacing
  output_file.open("designer_data.csv");

  while(i < 50){
    output_file << designerIDs[i] << ",";
    output_file << firstNames[i] << " " << lastNames[i] << ",";
    output_file << phones[i] << ",";
    output_file << "\"" << designerAddresses[i] << "\"" << ",";
    output_file << countries[rand()%249] << ",";
    output_file << websites[i] << ",";
    output_file << designFocuses[rand()%11] << endl;
    i++;
  }

  return 0;
}
