//
// Created by kubas1129 on 01.06.17.
//

#include "ArabicRoman.h"


namespace arabicroman{


    std::string ArabicToRoman(int arabic) {
        if(arabic > 0 && arabic < 4000)
        {
            std::string value;
            std::string M[]={"","M","MM","MMM"};
            std::string C[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
            std::string X[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
            std::string I[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
            value = M[arabic/1000]+C[(arabic%1000)/100]+X[(arabic%100)/10]+I[arabic%10];
            return value;
        }
        else
        {
            return "";
        }
    }

    int RomanToArabic(std::string roman) {
        int value=0;
        if(roman != "")
        {
            for(char &v : roman){
                switch(v){
                    case 'I' : value += 1;break;
                    case 'V' : value += 5;break;
                    case 'X' : value += 10;break;
                    case 'L' : value += 50;break;
                    case 'C' : value += 100;break;
                    case 'D' : value += 500;break;
                    case 'M' : value += 1000;break;
                }
            }
            if(value > 3999) return 0;
            return value;
        }
        else
        {
            return 0;
        }
    }
}