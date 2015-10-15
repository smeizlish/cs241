#include "getnum.c"

long num;

void main(){
  num = getnum();
  printf("0%lx",num);
}
