CC=gcc
INC=-Iinclude
LDFLAGS=

CFLAGS=-Wall --std=gnu11 -O3 $(INC)

SOURCES=$(shell ls src/*.c)
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLES=bin/scmo

all: $(SOURCES) $(EXECUTABLES)
    
bin/scmo: src/scmo.o
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) $< -o $@

scmo.o: include/scmo.h
