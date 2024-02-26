CFLAGS = -Wall -g -Wextra -std=gnu99
CC = gcc
AR = ar
FP = -fPIC

.PHONY: all clean

all: StrList

StrList: Main.o StrList.o
	$(CC) -o StrList Main.o StrList.o $(CFLAGS)

Main.o: Main.c
	$(CC) $(CFLAGS) $(FP) -c Main.c -o Main.o

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) $(FP) -c StrList.c -o StrList.o

clean: 
	rm -f *.o *.a StrList 