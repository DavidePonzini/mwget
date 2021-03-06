OBJ 		= Error.o Functions.o List.o Strings.o Main.o
EXEC		= mwget.exe
EXEC_NAME	= mwget
CC		= g++
C_FLAGS 	= -Wall -std=c++11


compile: $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $(EXEC)

install: compile
	ln $(EXEC) /usr/bin/$(EXEC_NAME)

run: compile
	./$(EXEC)

clean:
	rm -f $(EXEC) $(OBJ)

move: compile
	mv $(EXEC) ../../$(EXEC_NAME)



Error.o: Error.cpp Header.h
	$(CC) $(C_FLAGS) -c Error.cpp -o Error.o
Functions.o: Functions.cpp Header.h
	$(CC) $(C_FLAGS) -c Functions.cpp -o Functions.o
List.o: List.cpp Header.h
	$(CC) $(C_FLAGS) -c List.cpp -o List.o
Main.o: Main.cpp Header.h
	$(CC) $(C_FLAGS) -c Main.cpp -o Main.o
Strings.o: Strings.cpp Header.h
	$(CC) $(C_FLAGS) -c Strings.cpp -o Strings.o
