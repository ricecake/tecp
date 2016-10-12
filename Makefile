CC=gcc
INC=-Iinclude
LDFLAGS=-Llib -Wl,--gc-sections

CFLAGS=-Wall --std=gnu11 -O3 -fdata-sections -ffunction-sections $(INC)

EXECUTABLES=bin/stream

all: $(EXECUTABLES)

clean:
	rm src/*.o
	rm bin/*

bin/stream: src/stream.o src/scmo.o src/util.o
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ -o $@

bin/%.o: include/%.h
