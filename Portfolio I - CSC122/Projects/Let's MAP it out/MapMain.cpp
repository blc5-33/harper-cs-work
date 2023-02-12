//Base Level: 4, Selected first option (LVL 2)
//Total: lvl 4+2 = 6
#include "cityManager.h"
#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;
using sztp = vector<City>::size_type;

vector<City> cities{}, subCities{};
City newCity{}, city1{}, city2{};
string newName{};
double newX{0.0}, newY{0.0};
char menuSelection;

int main()
{
    cout << "\nWelcome to City Management Simulator!";
    do
    {
        cout << "\nWhat would you like to do?"
                "\n\t1) E|nter city Information"
                "\n\t2) C|alculate Distance between two cities"
                "\n\t3) P|rint All cities"
                "\n\t4) Q|uit" 
                "\nYour option (capitalized letter or #): ";
        cin >> menuSelection;
        cin.ignore(INT_MAX, '\n');

        switch (menuSelection)
        {
            case 'E': case 'e': case '1':
            {
                cout << "\nYou selected [1]";
                do
                {
                    cout << "\nPlease enter the name of your new city "
                            "(Max length = " << City::MAX_CITY_NAME <<
                            "): ";
                    getline(cin, newName);
                } while (newCity.set_name(newName) == false);

                cout << "\nPlease enter x-coord of your new city: ";
                cin >> newX;
                cout << "\nPlease enter y-coord of your new city: ";
                cin >> newY;
                newCity.set_location(newX, newY);
                
                cities.push_back(newCity);
                cout << "\nSuccess! New city created: "
                        "\"" << newCity.get_name() << "\""
                        " located at ";
                newCity.get_location().Output();
                break;
            }
            case 'C': case 'c': case '2':
            {
                cout << "\nYou selected [2]";
                if (cities.size() < 2 )
                {
                    cout << "\nInvalid! Need 2 or more entered cities "
                            "for a distance calculation.";
                }
                else if (cities.size() == 2)
                {
                    cout << "\nDistance between " 
                         << cities.at(0).get_name() << " and "
                         << cities.at(1).get_name() << " is "
                         << cities.at(0).distance(cities.at(1))
                         << ".";
                }
                else
                {
                    subCities = inputFindCities(
                        "\nPlease select the first city (name or #): ",
                        cities);
                    if (subCities.size() == 1)
                    {
                        city1 = subCities.at(0);
                    }
                    else if (subCities.size() > 1)
                    {   //               ^ Multiple cities of same name
                        cout << "\nMultiple cities of same name found! ";
                        city1 = inputFindCities(
                                "\nPlease select first city from the "
                                "list below with a numeric selection: ",
                                subCities, true).at(0);
                        //has to return a vector<City>
                        // with a single element
                    }

                    bool valid;
                    do
                    {
                        valid = true;
                        subCities = inputFindCities(
                            "\nPlease select the second city "
                            "(name or #):",
                            cities);
                        if (subCities.size() == 1)
                        {
                            city2 = subCities.at(0);
                        }
                        else if (subCities.size() > 1)
                        {   //             ^ Multiple cities of same name
                            cout << "\nMultiple cities of same name "
                                    "found! ";
                            city2 = inputFindCities(
                                    "\nPlease select second city from "
                                    "the list with a numeric selection: "
                                    , subCities, true).at(0);
                            //has to return a vector<City>
                            // with a single element
                        }
                        if (searchCityVector(city2, cities) == 
                            searchCityVector(city1, cities))
                        {
                            cout << "\nInvalid value! Second city must "
                                    "be different from first city. "
                                    "Try again.";
                            valid = false;
                        }
                    } while (valid == false);
                    cout << "\nDistance between \"" 
                            << city1.get_name() 
                            << "\" and \""
                            << city2.get_name()
                            << "\" is "
                            << city1.distance(city2) << ".";
                }
                break;
            }
            case 'P': case 'p': case '3':
            {
                cout << "\nYou selected [3]";
                printCityVector(cities);
                break;
            }
            case 'Q': case 'q': case '4':
            {
                cout << "\nYou selected [4]";
                cout << "\nThank you for using City Management "
                        "Simulator. Goodbye!";
                break;
            }
            default:
            {
                cout << "\nInvalid selection! Try again.";
                break;
            }
        }
    } while (menuSelection != 'Q' && menuSelection != 'q' &&
             menuSelection != '4');

    return 0;
}

