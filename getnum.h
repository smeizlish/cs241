//getnum.h

#ifndef GETNUM_H
#define GETNUM_H

#include <limits.h>
#include <stdio.h>
#include <ctype.h>

long getnum(void);

//first input value is the base
//second input value is the number it is raised to
//ex: e^x
int expon(int e, int x);

//global flags
extern int neg;
//true when the next char in stdin is the start of a number
extern int start;

#endif
