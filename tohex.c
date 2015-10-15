#include "getnum.h"

signed long num;

int main( void ){
    num = getnum();
    if ( num & ( 1 << ( sizeof ( long ) -1 ) ) ) printf ("%s\n" "negative");
    printf("0x%lx", num);
}
