#include "getnum.h"

//Sam Meizlish and Zack Sheldon 10/16/15
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
	if (neg== '1' ) {
	    printf( "-%ld\n", num );
	    neg = '0';
	}
	else {
	    printf( "%ld\n", num );
	}
	ch = getchar();
    }
}
