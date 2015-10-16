#include "getnum.h"
//Sam Meizlish and Zack SHeldon 10/16/15
long num;
int ch;

int main( void ){
 
    while (ch != EOF)
    {
	num = getnum();
	if (neg=='1'){
	    printf("-0%lo\n", num);
	}
	else{
	    printf("0%lo\n", num);
	}
	ch = getchar();
    }
}
