CC=gcc
INC=-Iinclude
LDFLAGS=

CFLAGS=-Wall --std=gnu11 -O3 $(INC)

SOURCES=$(shell ls src/*.c)
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLES=scmo

all: $(SOURCES) $(EXECUTABLE)
    
scmo: src/scmo.o 
	$(CC) $(LDFLAGS) $< -o $@

scmo.o: include/scmo.h
