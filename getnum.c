#include "getnum.h"

int ch;
char neg;



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
				ch = getchar();
				while (ch == '1'|'0') {
					output = output*2 + ch;
					ch = getchar();
}
				
				if (ch != '1'|'0') {
					printf("%s", "ERROR");
					break;
				return output;
}
			case 'x'://number is hex
				ch = getchar();
				while (isxdigit(ch)) {
					output = output*16 + ch;\
					ch = getchar();
}
				
				if (!isxdigit(ch)) {
					break;
}
				return output;
			default:
				ch = getchar();
				if (ch != '1'|'2'|'3'|'4'|'5'|'6'|'7'){
					break;//also print error
				}

				while (ch == '1'|'2'|'3'|'4'|'5'|'6'|'7'){
					output = output*8 + ch;
					ch = getchar();
				}
				return output;
				
}//ends switch
}
			else if (ch == 	'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9') {
				output = output*10 + ch;
}		

}//ends the while loop
}//ends the function definition
