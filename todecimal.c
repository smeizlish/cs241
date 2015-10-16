#include "getnum.h"

signed long num;
int ch;

int main( void ){
    extern char negative;
    num = getnum();
    if (neg tive== '1'){
	printf("-%ld\n", num);
    }
    else{
	printf("%ld\n", num);
    }
    ch = getchar();
    while (ch != EOF){
	if (isspace(ch)){
	    while (isspace(ch)){
		ch = getchar();
		printf("%d",ch);
		    }
		}
	printf("%s", "test");
	num = getnum();
	//if statement for negative flag??
	if (negative=='1'){
	    printf("-%ld\n", num);
	}
	else{
	    printf("%ld\n", num);
	}

    }
}



