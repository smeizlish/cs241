#include "getnum.h"

long num;
long converted;

long bin(long x){
    int i = sizeof(x)*CHAR_BIT;
    converted=0;
    while (i>0){
	--i;
	converted *= 10;
	converted |= (x >> i) & 1;
    }    
    return converted;
}

int main( void ){
  num = bin(getnum());
  printf("0b%ld", num);
}
