GCC=g++
ARGS=
RULES=main board position move rook


default: compile
	./exec

clean:
	rm objects/*

compile: $(RULES)
	$(GCC) $(ARGS) objects/* -o exec

main: main.cpp
	$(GCC) $(ARGS) main.cpp -c -o objects/main.o

board: board.cpp
	$(GCC) $(ARGS) board.cpp -c -o objects/board.o

position: logic/position.cpp
	$(GCC) $(ARGS) logic/position.cpp -c -o objects/position.o

move: logic/move.cpp
	$(GCC) $(ARGS) logic/move.cpp -c -o objects/move.o

rook: pieces/rook.cpp
	$(GCC) $(ARGS) pieces/rook.cpp -c -o objects/rook.o