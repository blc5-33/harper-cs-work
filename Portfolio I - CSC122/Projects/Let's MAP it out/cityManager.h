#pragma once

#include "city.h"
#include <vector>
#include <string>

void printCityVector (const std::vector<City> & cityVector);

std::vector<City>::size_type
searchCityVector (const std::string & cityName,
                  const std::vector<City> & cityVector,
                  const std::vector<City>::size_type & start = 0);

std::vector<City>::size_type
searchCityVector (const City & city,
                  const std::vector<City> & cityVector,
                  const std::vector<City>::size_type & start = 0);

std::vector<City>
inputFindCities(const std::string & prompt,
                const std::vector<City> & cityVector,
                const bool & numericSel = false);