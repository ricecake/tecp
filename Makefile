CC=gcc
INC=-Iinclude
LDFLAGS=-Llib -Wl,--gc-sections

CFLAGS=-Wall -Werror --std=gnu11 -O3 -fdata-sections -ffunction-sections $(INC)

EXECUTABLES=bin/stream

all: $(EXECUTABLES)

clean:
	rm src/*.o
	rm bin/*

bin/stream: src/stream.o src/scmo.o src/hash.o src/util.o

bin/%:
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ -o $@

#src/%.c: include/%.h
#	ls -lah $@

tidy:
	astyle -tyjnfpUr -k1 -A14 *.c *.h
