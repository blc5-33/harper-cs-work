#pragma once

#include "point.h"
#include <string>

class City
{
    Point location;
    std::string name;

public:

    static const std::string::size_type MAX_CITY_NAME{20};

    City(void)
        : location{},
          name{"New City"}
    {}

    City(const std::string & newName, const Point & newLoc = Point() )
        : City{}
    {
        set_name(newName);
        set_location(newLoc);
    }

    City(const std::string & newName, const double & newX,
                                      const double & newY )
        : City{}
    {
        set_name(newName);
        set_location(newX, newY);
    }

    City(const City & c) = default;

    //member functions

    inline
    double distance(const City & other) const
    { return location.distance(other.location); }

    inline
    Point get_location(void) const { return location; }

    void set_location(const Point & newLoc);

    void set_location(const double & x, const double & y);

    inline
    std::string get_name(void) const { return name; }

    bool set_name(const std::string & newName);
};
