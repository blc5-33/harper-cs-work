// implementation file for the find functions
#include "strextra.h"
#include <string>
#include <cctype>

using namespace std;
using sz_tp = string::size_type;

sz_tp find(const string & base, const char & input, 
           const bool & caseSensitive)
{
    sz_tp baseLength{base.length()},
          foundIndex{string::npos};
    bool found{false};

    for (sz_tp i = 0; i < baseLength && !found; i++)
    {
        if (  (caseSensitive && base[i] == input)
           || (!caseSensitive && 
               tolower(base[i]) == tolower(input))  )
        {
            found = true;
            foundIndex = i;
        }
    }
    return foundIndex; 
    // npos is esentially the unsigned version of -1 or invalid index
}

sz_tp find(const string & base, const string & input, 
           const bool & caseSensitive)
{
    sz_tp baseLength{base.length()},
          inputLength{input.length()},
          substringIndex{0}, foundIndex{string::npos};
    bool done{false},found{false};
    string subBase{""};

    for (sz_tp i = 0; i < baseLength && !found; ++i)
    {
        substringIndex = i;
        done = false;

        for (sz_tp k = 0; k < inputLength && !done; ++k)
        {
            // escape sequence detection
            if (input[k] != '/')
            {
                if (input[k] == '*')
                {
                    if (k == inputLength - 1)
                    {
                        done = true;
                        found = true;
                        foundIndex = i;
                    }
                    // if * at the end of input string
                    // who cares what the rest of the base string is?

                    // if char after * is ?
                    // then it's 0 chars until next valid char
                    while ( ( 
                           (caseSensitive 
                               && input[k+1] != base[substringIndex])
                        || (!caseSensitive 
                            && tolower(input[k+1])
                               != tolower(base[substringIndex])) ) 
                        && input[k+1] != '?' && !done)
                    {
                        if (substringIndex == baseLength - 1)
                        { // substringIndex is at end of base
                            done = true;
                            // found = false;
                        }
                        
                        ++substringIndex;
                        // keep iterating until it does find next 
                        // char after wildcard in base string
                    }
                }
                else if ( ( (caseSensitive 
                            && input[k] == base[substringIndex])
                    || (!caseSensitive 
                        && tolower(input[k]) 
                           == tolower(base[substringIndex])) )
                    || input[k] == '?')
                { 
                    // if valid match and at end of string, it is found!
                    if (k == inputLength - 1)
                    {
                        done = true;
                        found = true;
                        foundIndex = i;
                    }

                    // if any of these matches are valid, go to next base
                    // string char
                    ++substringIndex;
                }
                else
                { // if no valid matches, stop
                    done = true;
                    // found = false;
                }
            }
            else {
                if (k == inputLength - 1)
                {  // if escape char at end of inputString,that's invalid
                    done = true;
                    // found = false;
                }

                ++k; // skip to char after '/' escape sequence char
                if (input[k] == base[substringIndex])
                { // valid match
                    if (k == inputLength - 1)
                    {
                        done = true;
                        found = true;
                        foundIndex = i;
                    }
                    ++substringIndex;
                }
                else
                { // if next char does not match
                    done = true;
                    // found = false;
                }
            }
        }
    }
    return foundIndex;
}
