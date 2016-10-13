#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "scmo.h"
#include "util.h"

int main() {
	//FILE* fp = fopen("/tmp/test.txt", "w+");

	const char* string = "This is an example string";

	puts(string);

	uint8_t buffer[26];
	scmo_cipher((uint8_t*)string, buffer, strlen(string) + 1, 0xdeadbeefcafebabe);

	for(uint8_t i = 0; i < 26; i++) {
		printf("%02X", buffer[i]);
	}

	puts("");

	scmo_cipher(buffer, buffer, strlen(string) + 1, 0xdeadbeefcafebabe);
	puts((char*)buffer);
}
