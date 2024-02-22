CFLAGS = -Wall -g
CC = gcc
AR = ar
FP = -fPIC

.PHONY: all clean

all: StrList

StrList: Main.o Lib_StrList.a
	$(CC) -o StrList Main.o Lib_StrList.a $(CFLAGS)

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) $(FP) -c StrList.c -o StrList.o

Main.o: Main.c
	$(CC) $(CFLAGS) $(FP) -c Main.c -o Main.o

Lib_StrList.a: StrList.o
	$(AR) -rcs Lib_StrList.a StrList.o 

clean: 
	rm -f *.o *.a StrList