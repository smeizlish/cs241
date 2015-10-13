
#include "bits.h"

int main (void) 
{
    int c;
    while ( (c = getchar() ) != EOF ) 
    {
	decode_bits( c );	
    }
}
