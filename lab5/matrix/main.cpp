//
// Created by kubas1129 on 03.04.17.
//

#include <iostream>
#include "Matrix.h"

int main()
{
    algebra::Matrix m1{{1. + 3.0i, 2. + 2.0i}, {3. + 1.0i, 4. + 6.0i}, {5. + 5.i, 6. + 4.0i}};
    algebra::Matrix m2{{7. + 1.0i, 12. + 1.3i, 1.5 + 3.7i, 1.0i}, {15. + 2.0i, 2. + 4.6i, 2.1 + 3.8i, 1.4 + 0.2i}};
    std::cout << m1.Print() << std::endl;
    std::cout << m2.Print() << std::endl;
    algebra::Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};

    std::cout << pauli.Pow(2).Print() << std::endl;

    return 0;
}
