//
// Created by kubas1129 on 27.04.17.
//

#include "Pesel.h"

namespace academia{


    Pesel::Pesel(std::string pesel) {


        if(pesel.length() != 11) throw InvalidPeselLength(pesel, pesel.length());


        for(auto &v : pesel)
        {
            if(v < '0'  || v > '9') throw InvalidPeselCharacter(pesel);
        }

        int sum=0;
        int last_number = ((int)pesel[10] - 48);

        sum = (((int)pesel[0]-48)*9) + (((int)pesel[1]-48)*7) + (((int)pesel[2]-48)*3) + (((int)pesel[3]-48)*1) + (((int)pesel[4]-48)*9) + (((int)pesel[5]-48)*7) + (((int)pesel[6]-48)*3) + (((int)pesel[7]-48)*1) + (((int)pesel[8]-48)*9) + (((int)pesel[9]-48)*7);

        if((sum % 10) != last_number) throw InvalidPeselChecksum(pesel, sum%10);

    }
}