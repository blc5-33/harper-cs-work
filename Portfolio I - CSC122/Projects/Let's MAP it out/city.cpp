#include "city.h"

void City::set_location(const Point & newLoc) 
{
    location.set_x(newLoc.get_x());
    location.set_y(newLoc.get_y());
}

void City::set_location(const double & x, const double & y) 
{
    location.set_x(x);
    location.set_y(y);
}

bool City::set_name(const std::string & newName)
{
    bool okay{false};
    if (newName.size() <= MAX_CITY_NAME)
    {
        name = newName;
        okay = true;
    }
    return okay;
}
