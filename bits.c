#include "bits.h"

void print_bits(int ch)
{
    for (int i = CHAR_BIT-1; i >= 0; i--) 
    {
	putchar( (ch & (1 << i)) ? '1' : '0' ); 
    }
}

void decode_bits (int ch)
{
    static int buff[ CHAR_BIT ];
    static int count = 0;

    if ( ch == '0' | ch == '1' )
    {
	buff[CHAR_BIT-1-count] = ch - '0';
	count++;
	if ( count == CHAR_BIT )
	{
	    int n = 0;	
	    int dec = CHAR_BIT-1;
 	    while (dec >= 0)
	    {
		n += ( buff[dec] << dec );
		dec--;
	    }
	    putchar( n );
	    count = 0;
	}
    }   
    else if ( isspace(ch) != 0 )
    {
	return;
    }
    else
    {
	printf("%s", "program encountered an invalid character");
	exit(1);
    }
}
