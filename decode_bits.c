#include "bits.h"

int main (void) 
{
    int c;
    while ( (c = getchar() ) != EOF ) 
    {
	//printf( "%d", c );
	decode_bits( c );	
    }
}
