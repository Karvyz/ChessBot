GCC=g++
ARGS=-lsfml-graphics -lsfml-window -lsfml-system
RULES=main board position move rook queen


default: compile
	./exec
	
clean:
	rm build -r

init:
	mkdir build
	mkdir build/objects

compile: $(RULES)
	$(GCC) $(ARGS) build/objects/* -o exec

main:
	$(GCC) src/main.cpp -c -o build/objects/main.o

board:
	$(GCC) src/board.cpp -c -o build/objects/board.o

position:
	$(GCC) src/logic/position.cpp -c -o build/objects/position.o

move:
	$(GCC) src/logic/move.cpp -c -o build/objects/move.o

rook:
	$(GCC) src/pieces/rook.cpp -c -o build/objects/rook.o

queen:
	$(GCC) src/pieces/queen.cpp -c -o build/objects/queen.o