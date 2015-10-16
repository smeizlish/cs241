#include "getnum.h"

signed long num;
int ch;

int main( void ){
    while (ch != EOF)
    {
	num = getnum();
	if (neg=='1'){
	    printf("-0x%lx\n", num);
	}
	else{
	    printf("0x%lx\n", num);
	}
    }
}

