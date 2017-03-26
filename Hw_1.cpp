/**
 YOUR TASK is to read and understand this program. Then do the following:
 --> create and use a sentinel (or dummy) node
       // a sentinel node is an empty data node placed in the beginning of the list
       // insert/delete are shorter, simpler, and more eficient
 --> Display the number of countries in the list
 --> Create a second linked list
 --> Display the second linked list

 Name: Eric Du
 IDE: Codeblocks
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "CountryList.h"
#include "Country.h"

using namespace std;

bool readCountries(CountryList *list);
void searchManager(CountryList *list);
void deleteManager(CountryList *list);
void deleteCapitals(CountryList *list);
void displayCountry(Country showCountry);
string removeTrailingWhiteSpace(string str);

int main()
{
   // Define a CountryList object.
   CountryList *list = new CountryList;


   // Read Country information and creating link list nodes for country.
   if (!readCountries(list))
      return 1;

   // Display link list in CountryList object.
   list->displayList();

   // Search for country in CountryList object.
   searchManager(list);

   // Delete countries in CountryList object.
   deleteManager(list);


   list->displayList();

   // YOUR TASK ==================================
   // call more functions below
   //// Delete countries with "A" in capital.
    deleteCapitals(list);
    list->displayList();
   // ================================================
   delete list;

   return 0;
}

//**************************************************
// Definition of function displayCountry.
// This function displays the country information in
// showCountry.
//**************************************************
void displayCountry(Country showCountry)
{
   // Display Country Data
   cout << showCountry.getCode() << "; "
        << showCountry.getName() << "; "
        << showCountry.getCapital() << "; "
        << showCountry.getPopulation();
}

//**************************************************
// Definition of function readCountries.
// This function will read all the country info from
// the file Countries.txt and insert them into a
// list, a reference parameter. This function returns
// true if read successfully, and false if it did
// not read successfully or read no country.
// ASSUMPTIONS: about Countries.txt
//  1) Each country's data member is on a separate line.
//  2) Each country is immediately after one another.
//  3) There is nothing after the last country's data.
//**************************************************
bool readCountries(CountryList *list)
{
   ifstream inFile;
   Country readCountry;
   string readStr;
   bool empty = true;

   // Open file to read, if couldn't open, display error
   // and exit with false
   inFile.open("Countries.txt");
   if (!inFile)
   {
      cout << "Error opening countries.txt!\n";
      return false;
   }

   while (getline(inFile, readStr))  // get Country's Code
   {
        // finish processing Country's Code
        char temp[COUNTRY_CODE_SIZE];
        strcpy(temp, removeTrailingWhiteSpace(readStr).c_str());
        readCountry.setCode(temp);



        // read and process Country's name
        getline(inFile, readStr);
        readCountry.setName(removeTrailingWhiteSpace(readStr));

        // read and process Country's capital
        getline(inFile, readStr);
        readCountry.setCapital(removeTrailingWhiteSpace(readStr));

        // read and process Country's population
        getline(inFile, readStr);
        readCountry.setPopulation(atoi(readStr.c_str()));

        list->insertNode(readCountry);
        empty = false;
   }

   inFile.close();

   if (empty)
      return false;

   return true;
}

//**************************************************
// Definition of function removeTrailingWhiteSpace.
// This function removes trailing white spaces at
// the back of the string, str, and returns the new
// string. Removes trailing tabs, line feeds,
// spaces, and carriage returns.
//**************************************************
string removeTrailingWhiteSpace(string str)
{
   int i = str.length() - 1;  // zero based
   while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r')
   {
      str.erase(i, 1);
      i--;
   }
   return str;
}

//**************************************************
// Definition of function searchManager.
// This function will search for the country based
// upon the code entered by the user. If the country
// is found, the country data is returned in list, a
// reference parameter. Otherwise search not found
// will be displayed. This will cycle until the user
// enters QUIT.
//**************************************************
void searchManager(CountryList *list)
{
   Country searchCountry;
   string input;
   const string search_prompt = "[SEARCH COUNTRY] Please enter a code for a country:\n";

   while (cout << search_prompt, cin >> input, input != "QUIT")
   {
       char temp[COUNTRY_CODE_SIZE];
       strcpy(temp, input.c_str());
       searchCountry.setCode(temp);

       if (!list->searchNode(searchCountry))
          cout << "Search for " << searchCountry.getCode() << " not found.\n";
       else
       {
          cout << "\nCountry found: ";
          displayCountry(searchCountry);
          cout << ".\n";
       }
   }
}

//**************************************************
// Definition of function deleteManager.
// This function cycles, asking the user for a
// country to delete. The user enter a Code of the
// country to be deleted. If the Code is not found
// in the list, a reference parameter, then a
// message telling the user that country not found.
// If the Code was found, the node data that is
// deleted is shown. This function keeps going in a
// cycle until the user enter QUIT.
//**************************************************
void deleteManager(CountryList *list)
{
   string input;
   Country delCountry;
   const string delete_prompt = "\n[DELETE COUNTRY] Please enter a code for a country [QUIT to stop]:\n";

   while(cout << delete_prompt, cin >> input, input != "QUIT")
   {
       char temp[COUNTRY_CODE_SIZE];
       strcpy(temp, input.c_str());
       delCountry.setCode(temp);

      if (!list->deleteNode(delCountry))
         cout << "\n\nUSASCountry, " << delCountry.getCode() << ", was not deleted because it was not found!\n";
      else
      {
         cout << "Country Info that was deleted: ";
         displayCountry(delCountry);
         cout << ".\n";
      }
   }
}


//**************************************************
// Definition of function deleteCapitals.
// The purpose of this function is to inform the
// user that it will delete all capitals with
// a particular letter, then it calls, the deleteCapitals
// implementation and deletes it from the linked list
//**************************************************
void deleteCapitals(CountryList *list)
{
    cout << "\n**********************************************************************"
         << "\nAlong with the countries you decided to delete, I have also deleted "
         << "\nthe remaining countries that contain the letter \""<< DELETELETTER << "\" in the capital\n"
         << "**********************************************************************\n\n" ;

    list->deleteCapitals();

}

/**
CODE  COUNTRY_NAME        CAPITAL             POPULATION
AU    Australia           Canberra              20090437
BR    Brazil              Brasilia             186112794
BU    Bulgaria            Sofia                  7262675
CA    Canada              Ottawa                32805041
CN    China               Beijing             1306313812
DO    Dominican Republic  Santo Domingo          8950034
EG    Egypt               Cairo                 77505756
ES    Spain               Madrid                40341462
FJ    Figi                Suva                    893354
FR    France              Paris                 60656178
GR    Greece              Athens                10668354
HU    Hungary             Budapest              10006835
IR    Iran                Tehran                68017860
JA    Japan               Tokyo                127288419
LI    Liechtenstein       Vaduz                    33717
MC    Monaco              Monaco                   32409
MU    Mauritius           Port Louis             1230602
MX    Mexico              Mexico City          106202903
NP    Nepal               Kathmandu             27676547
RU    Russia              Moscow               143420309
TW    Taiwan              Taipei                22894384
US    United States       Washington, DC       295734134

Total Number of Listed Countries: 22

[SEARCH COUNTRY] Please enter a code for a country:
AU

Country found: AU; Australia; Canberra; 20090437.
[SEARCH COUNTRY] Please enter a code for a country:
US

Country found: US; United States; Washington, DC; 295734134.
[SEARCH COUNTRY] Please enter a code for a country:
EG

Country found: EG; Egypt; Cairo; 77505756.
[SEARCH COUNTRY] Please enter a code for a country:
QUIT

[DELETE COUNTRY] Please enter a code for a country [QUIT to stop]:
AU
Country Info that was deleted: AU; Australia; Canberra; 20090437.

[DELETE COUNTRY] Please enter a code for a country [QUIT to stop]:
US
Country Info that was deleted: US; United States; Washington, DC; 295734134

[DELETE COUNTRY] Please enter a code for a country [QUIT to stop]:
MX
Country Info that was deleted: MX; Mexico; Mexico City; 106202903.

[DELETE COUNTRY] Please enter a code for a country [QUIT to stop]:
QUIT
CODE  COUNTRY_NAME        CAPITAL             POPULATION
BR    Brazil              Brasilia             186112794
BU    Bulgaria            Sofia                  7262675
CA    Canada              Ottawa                32805041
CN    China               Beijing             1306313812
DO    Dominican Republic  Santo Domingo          8950034
EG    Egypt               Cairo                 77505756
ES    Spain               Madrid                40341462
FJ    Figi                Suva                    893354
FR    France              Paris                 60656178
GR    Greece              Athens                10668354
HU    Hungary             Budapest              10006835
IR    Iran                Tehran                68017860
JA    Japan               Tokyo                127288419
LI    Liechtenstein       Vaduz                    33717
MC    Monaco              Monaco                   32409
MU    Mauritius           Port Louis             1230602
NP    Nepal               Kathmandu             27676547
RU    Russia              Moscow               143420309
TW    Taiwan              Taipei                22894384

Total Number of Listed Countries: 19


**********************************************************************
Along with the countries you decided to delete, I have also deleted
the remaining countries that contain the letter "a" in the capital
**********************************************************************

CODE  COUNTRY_NAME        CAPITAL             POPULATION
CN    China               Beijing             1306313812
JA    Japan               Tokyo                127288419
MU    Mauritius           Port Louis             1230602
RU    Russia              Moscow               143420309

Total Number of Listed Countries: 4
**/
