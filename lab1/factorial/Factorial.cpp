//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

long long int factorial(long long int value)
{
  if(value  == 0) return 1;
  if(value >= 13) return 0;

  if(value > 0)
  {
    for(int i = (value-1); i > 0;i--)
    {
      value = value * i;
    }
  }
  else
  {
    for(int i = (value+1); i < 0;i++)
    {
      value = value * i;
    }
  }

  return value;
}
