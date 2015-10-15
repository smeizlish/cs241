//getnum.h
#include <limits.h>
#include <stdio.h>
#include <ctype.h>

#ifndef GETNUM_H
#define GETNUM_H

long getnum(void);

#endif

//first input value is the base
//second input value is the number it is raised to
//ex: e^x

long exp(int e, int x){
  int i;
  long ret=1;
  for (i=0; i < x; i++; ){
    ret = ret*e;
  }
  return ret;
}
