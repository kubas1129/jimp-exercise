//
// Created by kubas1129 on 26.04.17.
//

#include "Shape.h"
#include <iostream>
using namespace std;

void Circle::Draw() const {

    cout << "  **  " << endl;
    cout << "*    *" << endl;
    cout << "*    *" << endl;
    cout << "  **  " << endl;

}

void Triangle::Draw() const {

    const int n = 5;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n - i; ++j)
        {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

}

void Square::Draw() const {

    const int s = 5;
    for (int i = 0; i < s; ++i)
    {
        for (int j = s; j>0; --j)
        {
            cout << "*";
        }
        cout << endl;
    }
}