#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "scmo.h"
#include "hash.h"
#include "util.h"

md5_state_t state;
uint8_t digest[2][16];

int main(int argc, char* argv[]) {
	//FILE* fp = fopen("/tmp/test.txt", "w+");

	uint8_t* buffer  = (uint8_t*)malloc(strlen(argv[2]) + 1);
	uint8_t* buffer2 = (uint8_t*)malloc(strlen(argv[2]) + 1);

	md5_init(&state);
	md5_append(&state, (uint8_t*)argv[1], strlen(argv[1]));
	md5_finish(&state, digest[0]);

	strncpy((char*)digest[1], (char*)digest[0], 16);

	puts(argv[2]);

	scmo_cipher((uint8_t*)argv[2], buffer, strlen(argv[2]) + 1, (scmo_key)digest[0], buffer);

	for(uint8_t i = 0; i < strlen(argv[2]) + 1; i++) {
		printf("%02X", buffer[i]);
	}

	puts("");

	for(uint8_t i = 0; i < strlen(argv[2]) + 1; i++) {
		printf("(%c)%02X -> %02X\n", argv[2][i], ((uint8_t*)argv[2])[i], buffer[i]);
	}

	puts("");

	buffer[4] ^= 0xFF;
	scmo_cipher(buffer, buffer2, strlen(argv[2]) + 1, (scmo_key)digest[1], buffer);
	puts((char*)buffer2);

	return 0;
}
