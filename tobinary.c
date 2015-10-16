#include "getnum.h"
//Sam Meizlish and Zack SHeldon 10/16/15
long num;
long converted;

long bin(long x){
    int i = sizeof(x)*CHAR_BIT;
    converted=0;
    while (i>0){
	--i;
	converted *= 10;
	converted |= (x >> i) & 1;
    }    
    return converted;
}

int main( void ){
    ch = getchar();
    while (ch != EOF)
    {
	if ( !isspace( ch ) ) {
	    ungetc( ch, stdin );
	    num = bin( getnum() );
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
