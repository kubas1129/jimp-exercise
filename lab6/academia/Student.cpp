//
// Created by kubas1129 on 06.04.17.
//

#include "Student.h"


namespace academia {

    bool operator==(const Student &L,const Student &R) {
        if(L.Id() == R.Id() && L.FirstName() == R.FirstName() && L.Program() == R.Program() && L.LastName() == R.LastName() && L.Year() == R.Year())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}