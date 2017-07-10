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
  ofstream output;
  ofstream chairs_output;
  ofstream tables_output;
  ofstream desks_output;
  ofstream stools_output;
  ofstream cabinets_output;
  ofstream bedframes_output;
  string line;
  ifstream modelNumbers_file ("modelNumbers.txt");
  string name1[18];
  string name2[10];
  string name3[6];
  string material[25];
  string upholstery[12];
  string color[25];
  string durability[10];

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
  int current_item;

  //Write the modelNumbers into a file
  if (modelNumbers_file.is_open()){
    while (getline (modelNumbers_file,line)){
      //Hard reset for name3[0] because for some reason it was coming
      //up as "Aspen", which is material[25]???
      name3[0] = "Chair";

      current_item = rand()%6;

      preName = name1[rand()%18];
      postName = name2[rand()%18];
      current_material = material[rand()%25];
      current_upholstery = upholstery[rand()%12];
      current_durability = durability[rand()%10];
      current_color = color[rand()%25];
      item = name3[current_item];


      switch(current_item + 1){
        case 1:
          chairs_output << line << ",";
          chairs_output << preName << " " << postName << " " << item << ",";
          chairs_output << current_material << ",";
          chairs_output << current_upholstery << ",";
          chairs_output << current_durability << ",";
          chairs_output << current_color << endl; break;
        case 2:
          tables_output << line << ",";
          tables_output << preName << " " << postName << " " << item << ",";
          tables_output << current_material << ",";
          tables_output << current_upholstery << ",";
          tables_output << current_durability << ",";
          tables_output << current_color << endl; break;
        case 3:
          desks_output << line << ",";
          desks_output << preName << " " << postName << " " << item << ",";
          desks_output << current_material << ",";
          desks_output << current_upholstery << ",";
          desks_output << current_durability << ",";
          desks_output << current_color << endl; break;
        case 4:
          stools_output << line << ",";
          stools_output << preName << " " << postName << " " << item << ",";
          stools_output << current_material << ",";
          stools_output << current_upholstery << ",";
          stools_output << current_durability << ",";
          stools_output << current_color << endl; break;
        case 5:
          cabinets_output << line << ",";
          cabinets_output << preName << " " << postName << " " << item << ",";
          cabinets_output << current_material << ",";
          cabinets_output << current_upholstery << ",";
          cabinets_output << current_durability << ",";
          cabinets_output << current_color << endl; break;
        case 6:
          bedframes_output << line << ",";
          bedframes_output << preName << " " << postName << " " << item << ",";
          bedframes_output << current_material << ",";
          bedframes_output << current_upholstery << ",";
          bedframes_output << current_durability << ",";
          bedframes_output << current_color << endl; break;
        default: cout << "bad case in switch statement!!!" << endl;
      }

      output << line << ",";
      output << preName << " " << postName << " " << item << ",";
      output << current_material << ",";
      output << current_upholstery << ",";
      output << current_durability << ",";
      output << current_color << endl;
    }
    modelNumbers_file.close();
  }
  else cout << "Unable to open file";

  return 0;
}
