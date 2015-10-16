#include "getnum.h"
//Sam Meizlish and Zack SHeldon 10/16/15
int ch;
int error = 0;
//input buffer
static int buff[ sizeof ( long ) - 1];
int* buffptr = buff;
signed long sign = 0;
int neg = 0;
//assume we have good input
int start = 1;

long getnum( void ) 
{
	long output = 0;
	ch = getchar();
	//printf( "got a char\n" );
	//if ( ( '0' < ch) || (ch printf( "got a zero\n" );
	if ( isspace( ch ) )
	{
		//consume whitespace
		while( isspace( ch = getchar() ) ) continue;
		printf( "consuming whitespace \n" );
		//put back the good char that broke the loop
		ungetc(ch, stdin);
		start = 1;
	}
		
	else if ( ch == '-' )
	{
		neg = '1';
		ch = getchar();
	}
	if ( ch == '0' ) {
		ch = getchar();
		switch (ch) {
//BINARY
			case 'b':
				while( ( ch = getchar() ) )
				{
					if ( ch == '1' || ch == '0' )
					{
				    		//read chars into array based on int value
				    		*buffptr = ch - '0';
				    		buffptr++;
					}
					else if ( isspace( ch ) || ( ch == EOF ) )
					{
						//read backwards until we're at the start of the array
						int i = 0;
						//buffptr--;
						while ( buffptr >= buff )
						{
							output = output | ( *buffptr << i );
							buffptr--;
							i++;
						}
						printf( "%d %d %d\n", i, *buffptr, output );
						break;
					}
					else
					{
				    		error = 1;
				    		break;
					} 
			    	}
			    break;
//HEXADECIMAL
			case 'x': 
				while ( ( ch = getchar() ) )
			    	{
					if ( '0' <= ch && ch <= '9' ) 
					{
					    //read chars into array based on int value
					    *buffptr = ch - '0';
					    buffptr++;
					}
					else if ('A' <= ch && ch <= 'F' )
					{
					    *buffptr = ch - 'A' + 10;
					    buffptr++;
					}
					else if ('a' <= ch && ch <= 'f' ){
 						*buffptr = ch - 'a' + 10;
						buffptr++;
					}
					else if ( isspace( ch ) || ( ch == EOF ) )
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
						//printf( "hex conversion done, contents of buff =  %d", *buffptr);
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
			        	else if ( isspace( ch ) || ( ch == EOF ) )
					{
						//read backwards until we're at the start of the array
						int i = 0;
						buffptr--;
						while( buffptr >= buff )
						{
							//octal conversion
							//printf( "i = %d, *buffptr = %d, output = %d\n", i, *buffptr, output );
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
	else if ( ( '1' <= ch ) && ( ch <= '9' ) ) 
	{
		ungetc( ch, stdin );
		while( ( ch = getchar() ) )
		{
			if ( ( '0' <= ch ) & ( ch <= '9' ) ) 
			{
		    		//read chars into array based on int value
		    		*buffptr = ch - '0';
		    		buffptr++;
			}
			else if ( isspace( ch ) || ( ch == EOF ) )
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
	
    if (error)
    {
	//print a relevant error message
	printf( "%s %ld %c \n", "ERROR" ,output, ch);

    }
    return output;
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

/*int main( void )
{
    long conv = getnum();
    printf( "%ld", conv );

}*/
