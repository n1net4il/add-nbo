SHELL := /bin/bash

all: add-nbo

add-nbo: main.o util.o
	g++ -o add-nbo main.o util.o

main.o: util.h main.cpp

util.o: util.h util.cpp

test:
	echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
	echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
	./add-nbo thousand.bin five-hundred.bin
	rm -f *.bin

clean:
	rm -f add-nbo
	rm -f *.o