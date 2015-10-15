#include "getnum.c"

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

void main(){
  num = bin(getnum());
  printf("0b%ld", num);
}
