#include "getnum.h"

signed long num;
int ch;

int main( void ){
    /*extern char negative;
    num = getnum();
    if (neg == '1'){
	printf("-0x%lx\n", num);
    }
    else{
	printf("0x%lx\n", num);
    }
    ch = getchar();
    */
    while (ch != EOF)
    {
	num = getnum();
	//if statement for negative flag??
	if (neg=='1'){
	    printf("-0x%lx\n", num);
	}
	else{
	    printf("0x%lx\n", num);
	}

    }
}

