//
// Created by kubas1129 on 23.03.17.
//

#include "Name.h"


namespace name{

    Name::Name(std::string full_name)
    {
        int index = 0;
        int spaces = 0;

        for(;;)
        {
            if(full_name[index] == '\0') break;

            if(full_name[index] == ' ')
            {
                spaces++;
                continue;
            }

            if(spaces == 0)
            {
                First_Name += full_name[index];
            }
            if(spaces == 1)
            {
                Second_Name += full_name[index];
            }
            if(spaces == 2)
            {
                Third_Name += full_name[index];
            }
            if(spaces == 3)
            {
                SurName += full_name[index];
            }
            i++;
        }
    }


}