#include "strextra.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s1, s2;
    cout << "\nWelcome! Please enter the first string: ";
    getline(cin, s1);
    
    cout << "\nPlease enter the second string: ";
    getline(cin, s2);

    cout << "\nAnd the result from case-insensitive comparison is: "
         << strcmp_ncase(s1, s2) << "\n\n";
    return 0;
}
