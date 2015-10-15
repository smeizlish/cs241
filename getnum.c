#include "getnum.h"

int ch;
int neg;
int error = 0;
//input buffer
static int buff[ sizeof ( long ) - 1];
int* buffptr = buff;
signed long sign = 0;


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
	else if ( ch == '-' )
	{
		neg = 1;
		ch = getchar();
	}
	if ( ch == '0' ) {
		ch = getchar();
		switch (ch) {
			case 'b':
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
						while ( buffptr >= buff )
						{
							output = output | ( *buffptr << i );
							//printf( "%d %d %d\n", i, *buffptr, output );
							buffptr--;
							i++;
						}
						break;
					}
					else
					{
				    		error = 1;
				    		break;
					} 
			    	}
			    break;
			    
			case 'x': 
				while ( ch = getchar() )
			    	{
					if ( '0' <= ch & ch <= '9' ) 
					{
					    //read chars into array based on int value
					    *buffptr = ch - '0';
					    buffptr++;
					}
					else if ('A' <= ch & ch <= 'F' )
					{
					    *buffptr = ch - 'A' + 10;
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
						break;
					}
					else
					{
				    		error = 1;
				    		break;
					} 
			    	}
			    break;
			    
			default:
				ungetc( ch, stdin );
				while ( ( ch = getchar() ) )
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
							printf( "i = %d, *buffptr = %d, output = %d\n", i, *buffptr, output );
							output = output | ( *buffptr << ( 3*i ) ) ;
							i++;
							buffptr--;
						}
						break;
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
		ungetc( ch, stdin );
		while( ch = getchar() )
		{
			if ( ( '0' <= ch ) & ( ch <= '9' ) ) 
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
					output += *buffptr * expon( 10, i );
					buffptr--;
					i++;
				}
				break;	
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
    if ( neg ) sign = ~output + 1;
    else sign |= output;
    return sign;
}

int expon( int e, int x )
{
  int i;
  int ret=1;
  for (i=0; i < x; i++){
    ret = ret*e;
  }
  return ret;
}

int main( void )
{
    long conv = getnum();
    printf( "%ld", conv );

}
