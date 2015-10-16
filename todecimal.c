#include "getnum.h"
//Sam Meizlish and Zack SHeldon 10/16/15
long num;
int ch;

int main( void ){
    while (ch != EOF)
    {
	if ( !isspace( ch ) ) {
	    ungetc( ch, stdin );
	    num = getnum();
	}
	if (neg=='1'){
	    printf("-%ld\n", num);
	}
	else{
	    printf("%ld\n", num);
	}
	ch = getchar();
	
    }
}



