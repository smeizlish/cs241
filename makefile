
encode_bits: bits.o
	gccx -o encode_bits encode_bits.c bits.o

bits.o: bits.c bits.h
	gccx -c bits.c 
