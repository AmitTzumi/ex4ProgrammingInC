frequency.o: frequency.c
	gcc -Wall -g -c frequency.c -o frequency.o
	
libfrequency.a: frequency.o
	ar -rcs libfrequency.a frequency.o
	
frequency: frequency.o libfrequency.a
	gcc -Wall -g -o frequency frequency.o libfrequency.a
	
.PHONY: clean all frequency myfrequency

myfrequency: libfrequency.a

all: libfrequency.a frequency frequency.o

clean:
	rm -f *.o *.a *.so frequency					
