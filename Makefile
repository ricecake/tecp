CC=gcc
INC=-Iinclude
LDFLAGS=

CFLAGS=-Wall --std=gnu11 -O3 $(INC)

SOURCES=$(shell ls src/*.c)
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLES=bin/stream

all: $(SOURCES) $(EXECUTABLES)

bin/stream: src/stream.o src/scmo.o src/util.o
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ -o $@

bin/%.o: include/%.h
