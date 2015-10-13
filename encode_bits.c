#include "bits.h"

int main (void) 
{
    int c;
    while ((c = getchar()) != EOF) 
    {
	print_bits(c);
    }
    printf("\n");
}
