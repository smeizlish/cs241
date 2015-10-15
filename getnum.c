#include "getnum.h"

int ch;
int neg;
int error = 0;
//input buffer
static int buff[ sizeof ( long )];
int* buffptr = buff;


long getnum( void ) 
{
	long output = 0;
	ch = getchar();
	
	if ( isspace( ch ) )
	{
		//consume whitespace
		while( isspace( ch = getchar() ) ) continue;
		//put back the good char that broke the while
		ungetc(ch, stdin);
	}
	else if ( '-' == ch )
	{
		neg = 1;
		ch = getchar();
	}
	else if ( ch == '0' ) {
		ch = getchar();
		switch (ch) {
			case 'b'://number is binary
//				ch = getchar();
//				while (ch == '1'|'0') {
//					output = output*2 + ch;
//					ch = getchar();
//}
//				
//				if (ch != '1'|'0') {
//					printf("%s", "ERROR");
//					break;
//				return output;

				//infinite loop with break conditions
				while( ch = getchar() )
				{
					if ( ch == '1' | ch == '0' )
					{
				    		//read chars into array based on int value
				    		*buffptr = ch - '0';
				    		buffptr++;
					}
					else if ( isspace( ch ) | ( ch == EOF ) )
					{
						printf( "%d %d\n", buffptr, buff );
						//read backwards until we're at the start of the array
						int i = 0;
						buffptr--;
						while ( buffptr >= buff )
						{
							output = output | ( *buffptr << i );
							//printf( "%d %d %d\n", i, *buffptr, output );
							buffptr--;
							i++;
						}
						return output;
					}
					else
					{
				    		error = 1;
				    		break;
					} 
			    	}
			    break;
			    
			case 'x': //number is hex
//				ch = getchar();
//				while (isxdigit(ch)) {
//					output = output*16 + ch;\
//					ch = getchar();
//}
//				if (!isxdigit(ch)) {
//					break;
//}
//				return output;
			    
				while ( ch = getchar() )
			    	{
					if ( isxdigit( ch ) )
					{
				    		//read chars into array based on int value
				    		*buffptr = ch - '0';
				    		buffptr++;
					}
					else if ( isspace( ch ) | ( ch == EOF ) )
					{
						//read backwards until we're at the start of the array
						int i = 0;
						buffptr--;
						while ( buffptr >= buff )
						{
							output |= (*buffptr << 4*i) ;
							buffptr--;
							i++;
						}
						return output;
					}
					else
					{
				    		error = 1;
				    		break;
					} 
			    	}
			    break;
			    
			default:
				while ( ( ch = getchar() ) | 1 )
			    	{ 
					if ('0' <= ch & ch <= '7' )
					{   
			    			*buffptr = ch - '0';
				    		buffptr++;
			        	}
			        	else if ( isspace( ch ) | ( ch == EOF ) )
					{
						//read backwards until we're at the start of the array
						int i = 0;
						buffptr--;
						while( buffptr >= buff )
						{
							//octal conversion
							printf( "%d %d %d\n", i, *buffptr, output );
							buffptr--;
							output |= (*buffptr << 3*i) ;
							i++;
							buffptr--;
						}
						return output;
					}
			        	else
					{
				    	error = 1;
				    	break;
					}
			    }
			    break;
				
		}//ends switch
	}
	else if ( ( '1' <= ch ) & ( ch <= '9' ) ) 
	{
		while( ch = getchar() )
		{
			if ( ch == '1' | ch == '0' )
			{
		    		//read chars into array based on int value
		    		*buffptr = ch - '0';
		    		buffptr++;
			}
			else if ( isspace( ch ) | ( ch == EOF ) )
			{
				//read backwards until we're at the start of the array
				int i = 0;
				buffptr--;
				while( buffptr >= buff )
				{
					//output (*buffptr * 10^i //need method for integer exponentiation
					buffptr--;
					i++;
				}
				return output;
			}
			else
			{
		    		error = 1;
		    		break;
			} 
	    	}
	}		

    //error handling
    if (error)
    {
	//print a relevant error message
	
	//eat non-whitespace characters
	while ( getchar() != EOF ) continue;

	//let's try again
	getnum();
    }
}

int main( void )
{
    long conv = getnum();
    printf( "%ld", conv );
}
