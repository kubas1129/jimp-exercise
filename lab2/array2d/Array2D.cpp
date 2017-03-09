//
// Created by kubas1129 on 09.03.17.
//

#include "Array2D.h"
#include <iostream>

int **Array2D(int n_rows, int n_columns)
{
    if(n_rows <= 0 || n_columns <= 0) return nullptr;
    int counter{0};
    int **array = new int*[n_rows];
    for(int i = 0; i < n_rows;i++)
    {
        array[i] = new int[n_columns];
        for(int j = 0; j < n_columns;j++)
        {
            array[i][j] = ++counter;
        }
    }
    return array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i = 0; i < n_rows;i++)
    {
        delete []array[i];
    }
    delete []array;
}

int **NewArray2D(int n_rows, int n_columns)
{
    int **array = new int*[n_rows];
    for(int i = 0; i < n_rows;i++)
    {
        array[i] = new int[n_columns];
    }
    return array;
}

int **FillArray2D(int n_rows, int n_columns, int **to_fill)
{
    int counter{0};
    for(int i = 0; i < n_rows;i++)
    {
        for(int j = 0; j < n_columns;j++)
        {
            to_fill[i][j] = ++counter;
        }
    }
    return to_fill;
}
