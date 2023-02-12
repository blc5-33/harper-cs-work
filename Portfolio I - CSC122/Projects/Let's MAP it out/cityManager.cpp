#include "cityManager.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
using sztp = vector<City>::size_type;

void printCityVector (const vector<City> & cityVector)
{
    sztp vecSize{cityVector.size()};
    cout << "\nCity List: ";
    for (sztp i{0}; i != vecSize; ++i)
    {
        cout << "\n\t[" << i + 1 << "] \"" << cityVector.at(i).get_name()
        << "\" located at ";
        cityVector.at(i).get_location().Output();
    }
    cout << '\n';
    return;
}

sztp searchCityVector (const string & cityName,
                       const vector<City> & cityVector,
                       const sztp & start)
{
    sztp size{cityVector.size()};
    for (sztp i = start; i != size; ++i)
    {
        if (cityVector.at(i).get_name() == cityName)
        {
            return i;
        }
    }
    return -1;
}

sztp
searchCityVector (const City & city,
                  const vector<City> & cityVector,
                  const sztp & start)
{
    string cityName{city.get_name()},
           cVecName{};
    double cityX{city.get_location().get_x()},
           cityY{city.get_location().get_y()},
           cVecX, cVecY;
    sztp size{cityVector.size()};
    for (sztp i = start; i != size; ++i)
    {
        cVecName = cityVector.at(i).get_name();
        cVecX = cityVector.at(i).get_location().get_x();
        cVecY = cityVector.at(i).get_location().get_y();

        if (cVecName == cityName &&
            fabs(cityX - cVecX) <= 1e-6 && fabs(cityY - cVecY) <= 1e-6)
        {
            return i;
        }
    }
    return -1;
}

//prompts the user for city selection, finds cities in main
//vector that have the same name as user input
//detects if user wishes to input just a position from the list
//instead of a name
vector<City> inputFindCities(const string & prompt,
                             const vector<City> & cityVector,
                             const bool & numericSel)
{                               // ^ default value = false
    vector<City> subCities{};
    string input{};
    sztp cityIndex{0}, atollResult;

    printCityVector(cityVector);
    do
    {
        cout << prompt;
        getline(cin, input);

        //atoll() returns a long long int, sztp is usually unsigned
        //long long int, both are 64 bits usually
        //if atoll() returns negative, index will underflow, but it is
        //an invalid position 99% of the time with the sztp datatype
        atollResult = atoll(input.c_str());
        cityIndex = atollResult - 1;

        if (numericSel == true || atollResult != 0)
        {
            if (cityIndex >= cityVector.size())
            {
                cout << "\nInvalid selection! Try again.";
            }
            else if (cityIndex < cityVector.size())
            {
                subCities.push_back(cityVector.at(cityIndex));
                return subCities;
            }
        }
    } while (cityIndex >= cityVector.size() && numericSel == true);
    //if numeric selection requested and invalid conversion, then ask
    //user again until it is a valid value for cityIndex (> 1)
    
    do
    {
        cityIndex = 0;
        do
        {
            cityIndex = searchCityVector(input, cityVector, cityIndex);
            if (cityIndex != static_cast<sztp>(-1))
            {            //   ^ CPP was complaining about old-style casts
                subCities.push_back(cityVector.at(cityIndex));
                ++cityIndex;
            }
        } while (cityIndex != static_cast<sztp>(-1));
                        //    ^ CPP was complaining about old-style casts
        if (subCities.size() == 0)
        {
            cout << "\nNo city with that name found! Try again.";
            cout << prompt;
            getline(cin, input);
        }
    } while (subCities.size() == 0);
    //if input string is valid num -> stored in cityIndex
    
    return subCities;
}