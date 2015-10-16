#include "getnum.h"
//Sam Meizlish and Zack SHeldon 10/16/15
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
	ch = getchar();
    }
}

