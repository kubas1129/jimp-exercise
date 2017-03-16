//
// Created by Student on 16/03/17.
//
#include <sstream>
#include <regex>
#include <cmath>

#include "MinimalTimeDifference.h"

namespace minimaltimedifference
{



unsigned int MinimalTimeDifference(std::vector<std::string> times)
{

    std::vector<unsigned int> times_minutes;

    for(std::string v : times)
    {
        times_minutes.push_back(ToMinutes(v));
    }

    unsigned int smaller=0;

    for(unsigned int t1 : times_minutes)
    {
        for(unsigned int t2: times_minutes)
        {
            {
                unsigned int m=abs(t1 - t2);

                    if(m> smaller) smaller = m;

            }
        }
    }

    return smaller;
}

unsigned int ToMinutes(std::string time_HH_MM)
{

    std::regex searching{R"((\d{1,2}):(\d{2}))"};
    std::smatch matches;
    std::string str_minutes, str_hours;

    if (regex_match(time_HH_MM, matches, searching))
    {
        str_minutes = matches[2];
        str_hours = matches[1];
    }


    unsigned int minutes=0;
    std::istringstream ism(str_minutes);
    ism >> minutes;

    unsigned int hours=0;
    std::istringstream ish(str_hours);
    ish >> hours;

    if(hours == 0)
    {
        minutes += (24*60);
    }
    else
    {
        minutes += (hours*60);
    }

    return minutes;

    return 0;
}

}