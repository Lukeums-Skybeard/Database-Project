#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  srand((unsigned int)time(NULL));

  int i = 0;

  string sku[2000];

  ifstream skuList_file("skuList.txt");

  ifstream setIDs_file("setIDs.txt");

  ofstream set_data;
  ofstream output;
  ofstream contains_file;
  ofstream chairs_output;
  ofstream tables_output;
  ofstream desks_output;
  ofstream stools_output;
  ofstream cabinets_output;
  ofstream bedframes_output;
  ofstream make_file;
  ofstream canOrderFrom_file;
  string line;
  ifstream modelNumbers_file("modelNumbers.txt");
  string name1[18];
  string name2[18];
  string name3[6];
  string material[26];
  string upholstery[13];
  string color[25];
  string durability[10];
  string modelNumbers[1000];

  ifstream styles_file("styles.txt");

  string setIDs[100];
  string styles[100];

  if (styles_file.is_open()) {
    while (getline(styles_file, line)) {
      styles[i] = line;
      i++;
      // cout << line << endl;
    }
    styles_file.close();
  } else
    cerr << "Unable to open styles file" << endl;

  name1[0] = "Timeless";
  name1[1] = "Futuristic";
  name1[2] = "Contemporary";
  name1[3] = "Homely";
  name1[4] = "Ancient";
  name1[5] = "Stylish";
  name1[6] = "Eccentric";
  name1[7] = "Large";
  name1[8] = "Aged";
  name1[9] = "Strong";
  name1[10] = "Eclectic";
  name1[11] = "Rustic";
  name1[12] = "Modern";
  name1[13] = "Revolutionary";
  name1[14] = "Indian";
  name1[15] = "German";
  name1[16] = "Italian";
  name1[17] = "Norwegian";

  name2[0] = "Angular";
  name2[1] = "Rounded";
  name2[2] = "Jagged";
  name2[3] = "Hefty";
  name2[4] = "Light";
  name2[5] = "Chunky";
  name2[6] = "Macho";
  name2[7] = "Thin";
  name2[8] = "Badass";
  name2[9] = "Ladylike";
  name2[10] = "Slender";
  name2[11] = "Wimpy";
  name2[12] = "Oblique";
  name2[13] = "Bowed";
  name2[14] = "Gaunt";
  name2[15] = "Meager";
  name2[16] = "Fat";
  name2[17] = "Genteel";

  name3[0] = "Chair";
  name3[1] = "Table";
  name3[2] = "Desk";
  name3[3] = "Stool";
  name3[4] = "Cabinet";
  name3[5] = "Bedframe";

  material[0] = "Ash";
  material[1] = "Cherry";
  material[2] = "Maple";
  material[3] = "Birch";
  material[4] = "Teak";
  material[5] = "Hickory";
  material[6] = "Oak";
  material[7] = "Walnut";
  material[8] = "Aluminum";
  material[9] = "Steel";
  material[10] = "Beech";
  material[11] = "Alder";
  material[12] = "Elm";
  material[13] = "Pine";
  material[14] = "Cottonwood";
  material[15] = "Hemlock";
  material[16] = "Fir";
  material[17] = "Cedar";
  material[18] = "Balsa";
  material[19] = "Magnesium Alloy";
  material[20] = "Coast Redwood";
  material[21] = "Afzelia";
  material[22] = "Ebony";
  material[23] = "Lindens";
  material[24] = "Purpleheart";
  material[25] = "Aspen";

  upholstery[0] = "Linen";
  upholstery[1] = "Leather";
  upholstery[2] = "Cotton";
  upholstery[3] = "Wool";
  upholstery[4] = "Cotton Blend";
  upholstery[5] = "Vinyl";
  upholstery[6] = "Silk";
  upholstery[7] = "Acetate";
  upholstery[8] = "Acrylic";
  upholstery[9] = "Nylon";
  upholstery[10] = "Olefin";
  upholstery[11] = "Polyester";
  upholstery[12] = "Rayon";

  color[0] = "Blue";
  color[1] = "Green";
  color[2] = "Red";
  color[3] = "White";
  color[4] = "Black";
  color[5] = "Yellow";
  color[6] = "Grey";
  color[7] = "Orange";
  color[8] = "Purple";
  color[9] = "Pink";
  color[10] = "Violet";
  color[11] = "Magenta";
  color[12] = "Gold";
  color[13] = "Cyan";
  color[14] = "Turquoise";
  color[15] = "Lavender";
  color[16] = "Maroon";
  color[17] = "Olive";
  color[18] = "Indigo";
  color[19] = "Tan";
  color[20] = "Salmon";
  color[21] = "Sky Blue";
  color[22] = "Teal";
  color[23] = "Coral";
  color[24] = "Silver";

  durability[0] = "Very Strong";
  durability[1] = "Strong";
  durability[2] = "Somewhat Strong";
  durability[3] = "Very Sturdy";
  durability[4] = "Sturdy";
  durability[5] = "Somewhat Sturdy";
  durability[6] = "Wobbly";
  durability[7] = "Somewhat Wobbly";
  durability[8] = "Very Wobbly";
  durability[9] = "Indestructable";

  output.open("model_data.csv");

  chairs_output.open("chairs.csv");
  tables_output.open("tables.csv");
  desks_output.open("desks.csv");
  stools_output.open("stools.csv");
  cabinets_output.open("cabinets.csv");
  bedframes_output.open("bedframes.csv");

  string item;
  string preName;
  string postName;
  string current_material;
  string current_upholstery;
  string current_durability;
  string current_color;

  i = 0;

  if (skuList_file.is_open()) {
    while (getline(skuList_file, line)) {
      sku[i] = line;
      i++;
    }
    skuList_file.close();
  } else
    cerr << "Unable to open skuList file" << endl;

  i = 0;
  // Write the modelNumbers into a file
  if (modelNumbers_file.is_open()) {
    while (getline(modelNumbers_file, line)) {
      modelNumbers[i] = line;

      int current_item = rand() % 6;

      preName = name1[rand() % 18];
      postName = name2[rand() % 18];
      current_material = material[rand() % 25];
      current_upholstery = upholstery[rand() % 12];
      current_durability = durability[rand() % 10];
      current_color = color[rand() % 25];
      item = name3[current_item];

      switch (current_item + 1) {
      case 1:
        chairs_output << line << ",";
        chairs_output << sku[i] << ",";
        i++;
        chairs_output << rand() % 3 + 3 << ",";
        chairs_output << rand() % 2 << ",";
        chairs_output << rand() % 2 << ",";
        chairs_output << rand() % 12 + 24 << ",";
        chairs_output << rand() % 24 + 24 << endl;
        break;
      case 2:
        tables_output << line << ",";
        tables_output << sku[i] << ",";
        i++;
        tables_output << rand() % 6 + 4 << ",";
        tables_output << rand() % 8 + 4 << ",";
        if (rand() % 2 == 1) {
          tables_output << "Round" << endl;
        } else {
          tables_output << "Rectangular" << endl;
        }
        break;
      case 3:
        desks_output << line << ",";
        desks_output << sku[i];
        i++;
        desks_output << rand() % 45 + 0 << ",";
        desks_output << rand() % 6 + 1 << endl;
        break;
      case 4:
        stools_output << line << ",";
        stools_output << sku[i] << ",";
        i++;
        stools_output << rand() % 3 + 3 << ",";
        stools_output << rand() % 2 << ",";
        stools_output << rand() % 2 << endl;
        break;
      case 5:
        cabinets_output << line << ",";
        cabinets_output << sku[i] << ",";
        i++;
        cabinets_output << rand() % 6 + 1 << ",";
        cabinets_output << rand() % 10 + 1 << endl;
        break;
      case 6:
        bedframes_output << line << ",";
        bedframes_output << sku[i] << ",";
        switch (rand() % 6 + 1) {
        case 1:
          bedframes_output << "Twin"
                           << ",";
          break;
        case 2:
          bedframes_output << "Twin XL"
                           << ",";
          break;
        case 3:
          bedframes_output << "Full"
                           << ",";
          break;
        case 4:
          bedframes_output << "Queen"
                           << ",";
          break;
        case 5:
          bedframes_output << "King"
                           << ",";
          break;
        case 6:
          bedframes_output << "California King"
                           << ",";
          break;
        default:
          cerr << "bad case in switch statement!!!" << endl;
        }
        bedframes_output << rand() % 24 + 24 << endl;
        break;
      default:
        cerr << "bad case in switch statement!!!" << endl;
      }

      output << line << ",";
      output << preName << " " << postName << " " << item << ",";
      output << current_material << ",";
      output << current_upholstery << ",";
      output << current_durability << ",";
      output << current_color << endl;
    }
    modelNumbers_file.close();
  } else
    cerr << "Unable to open modelNumbers file";

  ofstream output_file;

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

  i = 0;

  // Read "designerIDs.txt" into string array

  if (designerIDs_file.is_open()) {
    while (getline(designerIDs_file, line)) {
      designerIDs[i] = line;
      i++;
    }
    designerIDs_file.close();
  } else
    cerr << "Unable to open ID file" << endl;

  i = 0;

  // Read "firstNames.txt" into string array

  if (firstNames_file.is_open()) {
    while (getline(firstNames_file, line)) {
      firstNames[i] = line;
      i++;
    }
    firstNames_file.close();
  } else
    cerr << "Unable to open firstNames file" << endl;

  i = 0;

  // Read "lastNames.txt" into string array

  if (lastNames_file.is_open()) {
    while (getline(lastNames_file, line)) {
      lastNames[i] = line;
      i++;
    }
    lastNames_file.close();
  } else
    cerr << "Unable to open lastNames file" << endl;

  i = 0;

  // Read "phones.txt" into string array

  if (phones_file.is_open()) {
    while (getline(phones_file, line)) {
      phones[i] = line;
      i++;
    }
    phones_file.close();
  } else
    cerr << "Unable to open phones file" << endl;

  i = 0;

  // Read "designerAddresses.txt into string array

  if (designerAddresses_file.is_open()) {
    while (getline(designerAddresses_file, line)) {
      designerAddresses[i] = line;
      i++;
    }
    designerAddresses_file.close();
  } else
    cerr << "Unable to open Addresses file" << endl;

  i = 0;

  // Read "countries.txt" into string array
  if (countries_file.is_open()) {
    while (getline(countries_file, line)) {
      countries[i] = line;
      i++;
    }
    countries_file.close();
  } else
    cerr << "Unable to open countries file" << endl;

  i = 0;

  // Create website addresses based on names, save them into websites array
  while (i < 50) {
    websites[i] =
        "www." + firstNames[i] + lastNames[i] + domainSuffix[rand() % 5];
    i++;
  }

  i = 0;

  // Read "designFocuses.txt" into string array

  if (designFocuses_file.is_open()) {
    while (getline(designFocuses_file, line)) {
      designFocuses[i] = line;
      i++;
    }
    designFocuses_file.close();
  } else
    cerr << "Unable to open designFocuses file" << endl;

  i = 0;
  // Write to output file
  // use a loop to write output to a file
  // SUBTASKS
  // write designerID on a line, end line
  // write a first name then a last name on a line, end line
  // write a phone number on a line, end line
  // write an address on a line, end line
  // write a random country on a line, end line
  // write a website on a line, end line
  // write a random design focus on a line, end line
  // end line for spacing
  output_file.open("designer_data.csv");

  while (i < 50) {
    output_file << designerIDs[i] << ",";
    output_file << firstNames[i] << " " << lastNames[i] << ",";
    output_file << phones[i] << ",";
    output_file << "\"" << designerAddresses[i] << "\""
                << ",";
    output_file << countries[rand() % 249] << ",";
    output_file << websites[i] << ",";
    output_file << designFocuses[rand() % 11] << endl;
    i++;
  }
  output_file.close();

  i = 0;

  string supplierIDs[50];
  string supplierNames[50];
  string supplierWebsiteNames[50];
  string addresses[50];

  // supplierIDs.txt
  ifstream supplierIDs_file("supplierIDs.txt");
  // names.txt
  ifstream supplierNames_file("supplierNames.txt");
  // supplierWebsiteNames.txt
  ifstream supplierWebsiteNames_file("supplierWebsiteNames.txt");
  // addresses.txt
  ifstream addresses_file("addresses.txt");

  // Read "supplierIDs.txt" into an array

  if (supplierIDs_file.is_open()) {
    while (getline(supplierIDs_file, line)) {
      supplierIDs[i] = line;
      i++;
    }
    supplierIDs_file.close();
  } else
    cerr << "Unable to open supplierIDs file" << endl;

  i = 0;

  // Read "supplierNames.txt" to names array

  if (supplierNames_file.is_open()) {
    while (getline(supplierNames_file, line)) {
      supplierNames[i] = line;
      i++;
    }
    supplierNames_file.close();
  } else
    cerr << "Unable to open names file" << endl;

  i = 0;

  // read "supplierWebsiteNames.txt" into an array

  if (supplierWebsiteNames_file.is_open()) {
    while (getline(supplierWebsiteNames_file, line)) {
      supplierWebsiteNames[i] = line;
      i++;
    }
    supplierWebsiteNames_file.close();
  } else
    cerr << "Unable to open supplierWebsiteNames file" << endl;

  i = 0;

  // Read "addresses.txt" to addresses array

  if (addresses_file.is_open()) {
    while (getline(addresses_file, line)) {
      addresses[i] = line;
      i++;
    }
    addresses_file.close();
  } else
    cerr << "Unable to open addresses file" << endl;

  i = 0;

  // output data to supplier_data.txt
  // supplierIDs
  // name
  // phone
  // address
  // country
  // website
  output_file.open("supplier_data.csv");
  while (i < 50) {
    output_file << supplierIDs[i] << ",";
    output_file << supplierNames[i] << ",";
    output_file << phones[i] << ",";
    output_file << "\"" << addresses[i] << "\""
                << ",";
    output_file << countries[rand() % 249] << ",";
    output_file << "www." << supplierWebsiteNames[i]
                << domainSuffix[rand() % 5];
    output_file << endl;
    i++;
  }
  output_file.close();

  i = 0;

  string centerIDs[50];
  string centerNames[50];
  string centerWebsiteNames[50];

  // centerIDs.txt
  ifstream centerIDs_file("centerIDs.txt");
  // names.txt
  ifstream centerNames_file("centerNames.txt");
  // centerWebsiteNames.txt
  ifstream centerWebsiteNames_file("centerWebsiteNames.txt");

  // Read "centerIDs.txt" into an array

  if (centerIDs_file.is_open()) {
    while (getline(centerIDs_file, line)) {
      centerIDs[i] = line;
      i++;
    }
    centerIDs_file.close();
  } else
    cerr << "Unable to open centerIDs file" << endl;

  i = 0;

  // Read "centerNames.txt" to names array

  if (centerNames_file.is_open()) {
    while (getline(centerNames_file, line)) {
      centerNames[i] = line;
      i++;
    }
    centerNames_file.close();
  } else
    cerr << "Unable to open names file" << endl;

  i = 0;

  // read "centerWebsiteNames.txt" into an array

  if (centerWebsiteNames_file.is_open()) {
    while (getline(centerWebsiteNames_file, line)) {
      centerWebsiteNames[i] = line;
      i++;
    }
    centerWebsiteNames_file.close();
  } else
    cerr << "Unable to open centerWebsiteNames file" << endl;

  i = 0;

  // output data to center_data.txt
  // centerIDs
  // name
  // phone
  // address
  // country
  // website
  output_file.open("center_data.csv");
  while (i < 50) {
    output_file << centerIDs[i] << ",";
    output_file << centerNames[i] << ",";
    output_file << phones[i] << ",";
    output_file << "\"" << addresses[i] << "\""
                << ",";
    output_file << countries[rand() % 249] << ",";
    output_file << "www." << centerWebsiteNames[i] << domainSuffix[rand() % 5];
    output_file << endl;
    i++;
  }
  output_file.close();

  ifstream modelNumber_file("modelNumbers.txt");

  ofstream modelNumberToSku_file;
  ofstream item_file;

  i = 0;

  // Take in "modelNumbers.txt" and put into array

  if (modelNumber_file.is_open()) {
    while (getline(modelNumber_file, line)) {
      modelNumbers[i] = line;
      i++;
    }
    modelNumber_file.close();
  } else
    cerr << "Unable to open modelNumber file" << endl;

  i = 0;
  // output a file that assigns each modelNumber an sku

  modelNumberToSku_file.open("modelNumberToSku.csv");

  while (i < 1000) {
    modelNumberToSku_file << modelNumbers[i] << "," << sku[i] << endl;
    i++;
  }
  i = 0;

  // output "item_data.csv"

  item_file.open("item_data.csv");

  while (i < 1000) {
    item_file << sku[i] << "," << rand() % 24 + 48 << "," << rand() % 24 + 48
              << "," << rand() % 24 + 48 << ","
              << "New"
              << "," << rand() % 200 + 300 << endl;
    i++;
  }
  i = 0;

  if (setIDs_file.is_open()) {
    while (getline(setIDs_file, line)) {
      setIDs[i] = line;
      i++;
    }
    setIDs_file.close();
  } else
    cerr << "Unable to open setIDs file" << endl;

  i = 0;

  set_data.open("set_data.csv");

  while (i < 100) {
    set_data << setIDs[i] << ",";
    set_data << styles[i] << " set"
             << ",";
    set_data << rand() % 33 + 1985 << ",";
    set_data << i << ",";
    set_data << styles[i] << endl;
    i++;
  }

  contains_file.open("contains_data.csv");
  i = 0;
  while (i < 1000) {
    contains_file << setIDs[rand() % 100] << ",";
    contains_file << modelNumbers[rand() % 1000] << ",";
    contains_file << (rand() % 6 + 1) << endl;
    i++;
  }
  contains_file.close();

  i = 0;

  make_file.open("make_data.csv");

  while (i < 1000) {
    make_file << supplierIDs[rand() % 50] << ",";
    make_file << designerIDs[rand() % 50] << ",";
    make_file << setIDs[rand() % 100] << endl;
    i++;
  }

  make_file.close();

  i = 0;

  canOrderFrom_file.open("canOrderFrom_data.csv");

  while (i < 1000) {
    canOrderFrom_file << centerIDs[rand() % 50] << ",";
    canOrderFrom_file << supplierIDs[rand() % 50] << ",";
    canOrderFrom_file << (rand() % 30 + 1) << endl;

    i++;
  }
  canOrderFrom_file.close();

  ofstream stocks_file;

  stocks_file.open("stocks_data.csv");

  for (int l = 0; l < 50; l++) {
    int count = rand() % 15 + 1;
    for (int x = 1; x < count; x++) {
      stocks_file << centerIDs[l] << "," << sku[rand() % 1000] << endl;
    }
  }
  stocks_file.close();

  string features[10];

  features[0] = "Fancy Knobs";
  features[1] = "Carved Inlays";
  features[2] = "Ivory Handles";
  features[3] = "Claw Feet";
  features[4] = "Gold Inlaid Designs";
  features[5] = "Fancy Molding";
  features[6] = "Gold Hinges";
  features[7] = "Padded Feet";
  features[8] = "Studded Corners";
  features[9] = "Textured";
  ofstream features_file;

  features_file.open("features_data.csv");

  for (int l = 0; l < 1000; l++) {
    for (int x = 0; x < 10; x++) {
      int count = rand() % 6;
      if (count > 0) {
        features_file << modelNumbers[l] << "," << features[x] << "," << count
                      << endl;
      }
    }
  }

  features_file.close();

  return 0;
}
