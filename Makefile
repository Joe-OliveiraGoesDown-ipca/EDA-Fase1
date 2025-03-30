# Nome do executável
all: prog

# Compilar o programa
prog: main.o funcoes.o
	gcc main.o funcoes.o -o prog

# Compilar main.c
main.o: main.c funcoes.h 
	gcc -c main.c -o main.o

# Compilar funcoes.c
funcoes.o: funcoes.c dados.h
	gcc -c funcoes.c -o funcoes.o

# Limpar arquivos compilados
clean:
	rm -f *.o prog

