#include "getnum.h"

signed long num;

int main( void ){
  num = getnum();
  printf("0x%lx", num);
}
