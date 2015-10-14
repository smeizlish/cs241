#include "getnum.h"

int ch;
char neg;
int error


long getnum(void) {
	long output = 0;

	ch = getchar();
	while((ch) != (EOF)) {//avoid whitespace
		if (isspace(ch)){
		break
}
		else if ('-' == ch) {
			neg = 1;
			ch = getchar();
}
		else if ('0' == ch) {
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

			    while( ( ch = getchar() ) | 1 )
			    {
				if ( ch == '1' | '0' )
				{
				    //binary conversion
				}
				else if ( isspace( ch ) | ch = EOF ) return output;
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
//				
//				if (!isxdigit(ch)) {
//					break;
//}
//				return output;
			    
			    while ( ( ch = getchar() ) | 1 )
			    {
				if ( isxdigit( ch ) )
				{
				    //hex conversion
				}
				else if ( isspace( ch ) | ch = EOF ) return output;
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
				if ('0' <= ch <= '7' )
				{   
			    	//octal conversion
			        }
			        if ( isspace( ch ) | ch == EOF ) return output;
			        else
				{
				    error = 1;
				    break;
				} 
				
			    }
			    break;
				
		    }//ends switch
}
			else if (ch == 	'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9') {
				output = output*10 + ch;
}		

}//ends the while loop

    //error handling
    if (error)
    {
	//print a relevant error message
	
	//eat non-whitespace characters
	while ( getchar() != EOF ) continue;

	//let's try again
	getnum();
    }

}//ends the function definition
