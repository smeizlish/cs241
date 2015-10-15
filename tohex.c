#include "getnum.c"

long num;

void main(){
  num = getnum();
  printf("0x%lx", num);
}
