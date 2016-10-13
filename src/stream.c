#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "scmo.h"
#include "util.h"

int main(int argc, char* argv[]) {
	//FILE* fp = fopen("/tmp/test.txt", "w+");

	uint8_t* buffer = (uint8_t*)malloc(strlen(argv[1]) + 1);

	puts(argv[1]);

	scmo_cipher((uint8_t*)argv[1], buffer, strlen(argv[1]) + 1, 0xdeadbeefcafebabe);

	for(uint8_t i = 0; i < strlen(argv[1]) + 1; i++) {
		printf("%02X", buffer[i]);
	}

	puts("");

	scmo_cipher(buffer, buffer, strlen(argv[1]) + 1, 0xdeadbeefcafebabe);
	puts((char*)buffer);
}
