#include "bits.h"
//Sam Meizlish and Zack SHeldon 10/16/15
int main (void) 
{
    int c;
    while ((c = getchar()) != EOF) 
    {
	print_bits(c);
    }
    printf("\n");
}
