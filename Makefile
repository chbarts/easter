CFLAGS = -O3 -g -Wall -ansi -pedantic -std=c99
CC = gcc

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c $<

OBJS = easter.o

SRCS = easter.c

all: easter

easter: $(OBJS)
	$(CC) $(OBJS) -o easter

clean:
	rm $(OBJS) easter
