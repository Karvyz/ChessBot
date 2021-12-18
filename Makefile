GCC=g++
ARGS=-lsfml-graphics -lsfml-window -lsfml-system
RULES=main board position move rook


default: compile
	./exec
	
clean:
	rm objects/*

compile: $(RULES)
	$(GCC) $(ARGS) objects/* -o exec

main: main.cpp
	$(GCC) main.cpp -c -o objects/main.o

board: board.cpp
	$(GCC) board.cpp -c -o objects/board.o

position: logic/position.cpp
	$(GCC) logic/position.cpp -c -o objects/position.o

move: logic/move.cpp
	$(GCC) logic/move.cpp -c -o objects/move.o

rook: pieces/rook.cpp
	$(GCC) pieces/rook.cpp -c -o objects/rook.o