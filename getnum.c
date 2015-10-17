#include "getnum.h"

//Sam Meizlish and Zack SHeldon 10/16/15
static int buff[ sizeof ( long ) - 1];
int neg = 0;
int *buffptr = buff;
int error = 0;

long getnum( void ) 
{
	int ch;
	int count = 0; 
	long output = 0;
	int error = 0;
	
	ch = getchar();
	if ( ch == '-' )
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
				    		buff[count] = ch - '0';
						count++;
					}
					else if ( isspace( ch ) || ( ch == EOF ) )
					{
						//read backwards until we're at the start of the array
						count--;
						int i = 0;
						while ( count >= 0 )
						{
							output |= (buff[count] << i) ;
							i++;
							count--;
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
//HEXADECIMAL
			case 'x': 
				while ( ( ch = getchar() ) )
			    	{
					if ( '0' <= ch && ch <= '9' ) 
					{
						buff[count] = ch - '0';
						count++;
					}
					else if ('A' <= ch && ch <= 'F' )
					{
						buff[count]= ch - 'A' + 10;
						count++;
					}
					else if ('a' <= ch && ch <= 'f' ){
						buff[count] = ch - 'a' + 10;
						count++;
					}
					else if ( isspace( ch ) || ( ch == EOF ) )
					{
						count--;
						int i = 0;
						while ( count >= 0 )
						{
							output |= (buff[count] << 4*i) ;
							i++;
							count--;
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
//OCTAL
			default:
				ungetc( ch, stdin );
				while ( ( ch = getchar() ) )
			    	{ 
					if ('0' <= ch & ch <= '7' )
					{   
			    			buff[count] = ch - '0';
						count++;
			        	}
			        	else if ( isspace( ch ) || ( ch == EOF ) )
					{
						int i = 0;
						count--;
						while( count >= 0 )
						{
							output |= (buff[count] << 3*i) ;
							i++;
							count--;
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
		} //ends switch
	}
//DECIMAL
	else if ( ( '1' <= ch ) && ( ch <= '9' ) ) 
	{
		ungetc( ch, stdin );
		while( ( ch = getchar() ) )
		{
			if ( ( '0' <= ch ) && ( ch <= '9' ) ) 
			{
		    		buff[count] = ch - '0';
				count++;
			}
			else if ( isspace( ch ) || ( ch == EOF ) )
			{
				int i = 0;
				count--;
				while( count >= 0 )
				{
					output += buff[count] * expon( 10, i );
					i++;
					count--;
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
	printf( "ERROR\n");
	while ( !isspace( ch = getchar() ) );
	ungetc(ch, stdin);
    }
    else return output;
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
