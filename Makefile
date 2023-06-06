.PHONY: all aplicacao teste doc clean

all: aplicacao teste

aplicacao: src/matrizes.o src/main.o
	@gcc -o programa src/matrizes.o src/main.o

src/matrizes.o: src/matrizes/matrizes.c 
	@gcc -o src/matrizes.o -c src/matrizes/matrizes.c -W -Wall -pedantic

src/main.o: src/main.c
	@gcc -o src/main.o -c src/main.c -W -Wall -pedantic

teste: aplicacao
	@./programa

doc:
	doxygen doc/Doxyfile

clean:
	rm -f programa src/matrizes.o src/main.o
