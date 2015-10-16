all: encode_bits decode_bits todecimal tohex tooctal tobinary
encode_bits: bits.o
	gccx -o encode_bits encode_bits.c bits.o
decode_bits: bits.o
	gccx -o decode_bits decode_bits.c bits.o
bits.o: bits.c bits.h
	gccx -c bits.c 
todecimal: todecimal.c getnum.c getnum.h
	gccx -o todecimal todecimal.c getnum.c
tohex: tohex.c getnum.c getnum.h
	gccx -o tohex tohex.c getnum.c
tooctal: tooctal.c getnum.c getnum.h
	gccx -o tooctal tooctal.c getnum.c
tobinary: tobinary.c getnum.c getnum.h
	gccx -o tobinary tobinary.c getnum.c
clean:
	rm  bits.o decode_bits encode_bits todecimal tohex tooctal tobinary
