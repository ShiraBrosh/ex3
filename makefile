CFLAGS = -Wall -g -Wextra -std=gnu99
CC = gcc
AR = ar
FP = -fPIC

.PHONY: all clean

all: StrList

StrList: main.o StrList.o
	$(CC) -o StrList main.o StrList.o $(CFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) $(FP) -c main.c -o main.o

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) $(FP) -c StrList.c -o StrList.o

clean: 
	rm -f *.o *.a StrList 