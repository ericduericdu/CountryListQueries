// Specification file for the CountryList class
#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <cstring>
#include "CountryList.h"
using namespace std;

const int COUNTRY_CODE_SIZE = 3; // 2 + \0

class Country
{
private:
   char code[COUNTRY_CODE_SIZE];
   string name;
   string capital;
   int population;

public:
    Country();

    ~Country();



    void setCode(char countryCode[COUNTRY_CODE_SIZE]);
    void setName(string);
    void setCapital(string);
    void setPopulation(int);

    char* getCode()
        { return code; }
    string getName()
        { return name; }
    string getCapital()
        { return capital; }
    int getPopulation()
        { return population; }

};
#endif
