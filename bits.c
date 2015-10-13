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
	buff[count] = ch;
	count++;
	if ( count == CHAR_BIT )
	{
	    //convert binary in buff to decimal and print it
	    int n = 0;	
	    int dec = 0;
 	    while (count >= 0){
		if (buff[count] == 1){
			dec += 1<<n;
			count--;
			n++;
			printf('%i \n', dec);
			putchar(dec);
	    		count = 0;
	}		    
    }
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
