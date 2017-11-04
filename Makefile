# exemplo (muito simples) de Makefile

# igual indica atribuição de variável
CPP = g++
CPPFLAGS = -Wall

OBJ = main.o acamp.o item.o

# dois pontos indica dependência
main: $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o main

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp -o main.o

acampamento.o: acamp.cpp acamp.hpp
	$(CPP) $(CPPFLAGS) -c acamp.cpp -o acamp.o

item.o: item.cpp item.hpp
	$(CPP) $(CPPFLAGS) -c item.cpp -o item.o

all: main

clean:
	rm -f *.o
