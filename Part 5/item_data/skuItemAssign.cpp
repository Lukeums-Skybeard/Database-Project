#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string line;
  int i = 0;
  srand(time(NULL));
  ifstream modelNumber_file("modelNumbers.txt");
  ifstream skuList_file("skuList.txt");
  
  ofstream modelNumberToSku_file;
  ofstream item_file;
  
  string sku[1000];
  string modelNumber[1000];
  
  //Take in "skuList.txt" and put into array
  
  if(skuList_file.is_open()){
    while(getline (skuList_file,line)){
      sku[i] = line;
      i++;
    }
    skuList_file.close();
  }
  else cout << "Unable to open skuList file" << endl;
  
  i = 0;
  
  //Take in "modelNumbers.txt" and put into array
  
  if(modelNumber_file.is_open()){
    while(getline (modelNumber_file, line)){
      modelNumber[i] = line;
      i++;
    }
    modelNumber_file.close();
  } else cout << "Unable to open modelNumber file" << endl;
    
  i = 0;
  //output a file that assigns each modelNumber an sku
  
  modelNumberToSku_file.open("modelNumberToSku.csv");
  
  while(i <= 1000){
    modelNumberToSku_file << modelNumber[i] << "," << sku[i] << endl;
    i++;
  }
  i = 0;
  
  //output "item_data.csv"
  
  item_file.open("item_data.csv");
  
  while(i <= 1000){
    item_file << sku[i] << "," << rand()%24+48 << "," << rand()%24+48 << "," << rand()%24+48 << "," << "New" << "," << rand()%200+300 << endl;
    i++;
  }
  
  return 0;
}
