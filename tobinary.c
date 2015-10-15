#include "getnum.h"

long num;
long converted;

long bin(long x){
  int i = sizeof(x)*CHAR_BIT;
  
  while (i > 0) {
        --i;
        converted *= 10;
        converted |=  (x >>i)&1;
  }
  return x;
}

int main( void ){
  num = bin(getnum());
  printf("0b%ld", num);
}
