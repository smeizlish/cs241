#include "getnum.h"
//Sam Meizlish and Zack SHeldon 10/16/15
long num;
int ch;

void bin( long x ){
    long dig = x;
    int MSB = 0;
    
    for ( int i = 0; i < sizeof (x) * CHAR_BIT; i++ ) {
	if (dig && 1) {
	    MSB = i;
	}
	dig >>= 1;
    }
    dig = x;
    for ( int i = MSB; i >= 0; i-- ) {
	
	if ( x	& ( 1 << i ) ){
	    printf("1");
	}
	else printf("0");	
    }
    printf("\n");
}    

int main( void ){
    ch = getchar();
    while (ch != EOF)
    {
	if ( !isspace( ch ) ) {
	    ungetc( ch, stdin );
	    num = getnum();
	}
	if (!error) {
		if (neg== '1' ) printf("-");
		printf("0b");
		bin( num );	
	}
	ch = getchar();
    }
}

