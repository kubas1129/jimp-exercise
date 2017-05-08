//
// Created by kubas1129 on 26.04.17.
//

#include<iostream>
#include <list>
#include<time.h>
#include "Shape.h"

int main()
{
    srand(time(NULL));
    int n;

    Circle c;
    Triangle t;
    Square s;

    std::list <Shape*> lists;
    for (int i = 0; i<15; ++i)
    {
        n = rand() % 3;
        if (n == 0) lists.push_back(&c);
        else if (n == 1) lists.push_back(&t);
        else if (n == 2) lists.push_back(&s);
    }

    std::list<Shape*>::iterator it;

    for (it = lists.begin(); it != lists.end(); it++)
    {
        (*it)->Draw();
    }
    return 0;
}