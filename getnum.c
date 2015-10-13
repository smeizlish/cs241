#include "getnum.h"

int ch;
char neg;



long getnum(void) {
	long output;
	char input[] = malloc(sizeof(long)+2+1)

	input = scanf();


	while((ch=getchar()) != (EOF|' ')) {//avoid whitespace
		if ('-' == ch) {
			neg = 1;
			ch = getchar();
}
		if ('0' == ch) {
			ch = getchar();
			switch (ch) {
			case 'b'://number is binary
		
			case 'x'://number is hex
			case '1': case '2': case '3': case '4': case '5': 
			case '6': case '7':
				//do octal stuff
		else {
	//do decimal stuff
			

}
