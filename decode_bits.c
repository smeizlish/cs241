#include "bits.h"
//Sam Meizlish and Zack SHeldon 10/16/15
int main (void) 
{
    int c;
    while ( (c = getchar() ) != EOF ) 
    {
	//printf( "%d", c );
	decode_bits( c );	
    }
}
