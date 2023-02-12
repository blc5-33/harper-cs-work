#include "strextra.h"
#include <string>
#include <cctype>

using namespace std;
using sztp = std::string::size_type;

int strcmp_ncase(const string & s1, const string & s2)
{
    sztp smallerLen{min(s1.length(), s2.length())};
    int rValue{0};
    bool done{false};

    for (sztp i{0}; i <= smallerLen && !done; ++i)
    {
        if (tolower(s1[i]) != tolower(s2[i]))
        {
            done = true;
            rValue = static_cast<int>(tolower(s1[i]) - tolower(s2[i]));
        }
    }
    return rValue;
}
