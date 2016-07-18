CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

JSON_SOURCE = JSON_generator.c
JSON_TARGET = JSON_generator
JSON_EXE = JSON_generator.exe


all: JSON

JSON:
	$(CC) $(CFLAGS) $(JSON_SOURCE) -o $(JSON_TARGET)

cleanJSON:
	rm $(JSON_EXE);
	rm -f *.json;