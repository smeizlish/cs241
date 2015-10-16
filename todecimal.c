#include "getnum.h"

long num;
int ch;

int main( void ){
    while (ch != EOF)
    {
	//if ( !isspace( ch ) ) ungetc( ch, stdin );
	num = getnum();
	if (neg=='1'){
	    printf("-%ld\n", num);
	}
	else{
	    printf("%ld\n", num);
	}
	ch = getchar();
	
    }
}



