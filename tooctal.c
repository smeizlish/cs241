#include "getnum.h"

//Sam Meizlish and Zack SHeldon 10/16/15
long num;
int ch;

int main( void ){
    ch = getchar();
    while (ch != EOF)
    {
	if ( !isspace( ch ) ) {
	    ungetc( ch, stdin );
	    num = getnum();
	}
	if (!error) {
		if (neg== '1' ) {
	    		printf( "-0%lo\n", num );
	    		neg = '0';
		}
		else {
	    		printf( "0%lo\n", num );
		}
	}
	ch = getchar();
    }
}
