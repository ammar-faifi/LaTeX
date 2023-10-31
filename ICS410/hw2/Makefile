# Makefile for compiling and running a C program

CC = gcc
CFLAGS = -Wall
SRC = code.c
TARGET = out

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
