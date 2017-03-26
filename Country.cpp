// Implementation file for the CountryList class
#include <iostream>  // For cout and NULL
#include <iomanip>   // For setw()
#include <cstring>   // For strcmp()
#include "CountryList.h"
#include "Country.h"

using namespace std;

//**************************************************
// Constructor                                     *
//**************************************************
Country::Country()
{
    strcpy(code, "  ");
    name = " ";
    capital = " ";
    population = 0;
}

//**************************************************
// sets parameter to the private member, code,
// using strcpy
//**************************************************
void Country::setCode(char countryCode[COUNTRY_CODE_SIZE])
{
    strcpy(code, countryCode);
}

//**************************************************
// sets parameter to the private member, name.
//**************************************************
void Country::setName(string countryName)
{
    name = countryName;
}

//**************************************************
// sets parameter to the private member, capital.
//**************************************************
void Country::setCapital(string countryCapital)
{
    capital = countryCapital;

}

//**************************************************
// sets parameter to the private member, population.
//**************************************************
void Country::setPopulation(int countryPopulation)
{
    population = countryPopulation;

}

Country::~Country()
{

}

