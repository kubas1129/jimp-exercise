//
// Created by Student on 16/03/17.
//
#include <sstream>
#include <regex>

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

    unsigned int smaller = 1440;

    for(unsigned int t1 : times_minutes)
    {
        for(unsigned int t2: times_minutes)
        {
            {
                if(t1 != t2)
                {
                    //normal count with abs
                    int m1 = abs(t1 - t2);


                    //second count
                    int m2, m3, m4;

                    if(t1 > 720) {
                        m2 = abs(1440 - t1);
                    }else{
                        m2 = t1;
                    }
                    if(t2 > 720){
                        m3 = abs(1440 - t2);
                    }else{
                        m3 = t2;
                    }

                    m4 = m2 + m3;

                    //Check which time is less than smaller
                    if(m1 > m4) {
                        if(m4 < smaller) smaller = m4;
                    }else {
                        if(m1 < smaller) smaller = m1;
                    }
                }


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
}

}