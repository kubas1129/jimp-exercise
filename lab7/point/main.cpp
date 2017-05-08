//
// Created by kubas1129 on 24.04.17.
//

#include <iostream>
#include "Point.h"

int main()
{
    Point punkt(2,3);
    Point3D punkt3d(2,5,7);
    /* Pierwszy jest wywolywany kontruktor klasy bazowej a nastepnie dzieci ktore dziedzicza po danej klasie,
     * natomiast w przypadku destruktorow kolejnosc jest odwrotna, najlpierw wywolywany jest kontruktor klasy najbardziej
     * potomnej a nastepnie kolejne coraz wyzej w hierarchi az do klasy bazowej*/

    std::cout << "Distance: " << punkt.Distance(punkt3d) << std::endl;
    /* Wywolywana jest wersja funkcji Distance z klasy Point nie z Point3D*/

    Point3D p3d(1,2,3);
    std::cout << p3d << std::endl;
    /* Wywolywane jest przeladowanie operatora << dla klasy Point z klasy Point3D, ponieważ klasa ta dziedziczy z Point
     * wiec ma takze prywatne pola odziedziczone z Point*/
    return 0;
}