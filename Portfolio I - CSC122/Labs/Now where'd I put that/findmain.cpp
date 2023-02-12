// Driver program for strextra library
#include "strextra.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    enum option{CHAR=1, STRING};
    string baseString{""},
                inputString{""};
    int selection{0};
    char inputChar{'a'};
    string::size_type findResult{0};

    cout << "\nWelcome! Please enter a base string to search."
                 "\nString: ";
    getline(cin, baseString);

    cout << "\nString accepted! What would you like"
                 " to search for in this string?"
                 "\n [1] CHAR"
                 "\n [2] STRING"
                 "\nYour choice: ";
    cin >> selection;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (selection)
    {
        case CHAR:
            cout << "\nYou selected: CHAR."
                         "\nPlease enter the CHAR to search for (type `"
                         " for space character): ";
                         // the ` substituting space is for 
                         // testing purposes only
            cin >> inputChar;
            inputChar = (inputChar == '`') ? ' ' : inputChar;

            //default arg: caseSensitive = true
            findResult = find(baseString, inputChar); 
            cout << "\nResult from |find| function was: " 
                      << findResult << ".";

            findResult = find(baseString, inputChar, false);
            cout << "\nResult from case-insensitive "
                         "|find| function was: " << findResult << ".";

            break;

        case STRING:
            cout << "\nYou selected: STRING."
                         "\nPlease enter the STRING to search for: ";
            getline(cin, inputString);

            //default arg: caseSensitive = true
            findResult = find(baseString, inputString);
            cout << "\nResult from |find| function was: " 
                      << findResult << ".";

            findResult = find(baseString, inputString, false);
            cout << "\nResult from case-insensitive "
                         "|find| function was: " << findResult << ".";
            
            break;

        default:
            cout << "\nInvalid input!";
            break;
    }
    cout << "\nEnd of program. Thank you for using.\n\n";
    return 0;
}
