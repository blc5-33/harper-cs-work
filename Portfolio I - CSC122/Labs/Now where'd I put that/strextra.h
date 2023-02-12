// Header file for find function
#pragma once
#include <string>

//This variant of the find function will work with |char| inputs
std::string::size_type 
find(const std::string & base, const char & input, 
     const bool & caseSensitive = true);

//This variant of the find function will work with |string| inputs
std::string::size_type
find(const std::string & base, const std::string & input,
     const bool & caseSensitive = true);

