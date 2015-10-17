#include "getnum.h"
//Sam Meizlish and Zack SHeldon 10/16/15
signed long num;
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
	    		printf( "-0x%lx\n", num );
	    		neg = '0';
		}
		else {
	    		printf( "0x%lx\n", num );
		}
	}
	ch = getchar();
    }
}
