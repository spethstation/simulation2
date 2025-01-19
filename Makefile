# Simple Makefile for compiling the program
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
TARGET = program

all: $(TARGET)

$(TARGET): sim3.c
	$(CC) $(CFLAGS) -o $(TARGET) sim3.c

clean:
	rm -f $(TARGET)
