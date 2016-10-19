#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "scmo.h"
#include "util.h"


uint8_t* scmo_cipher(uint8_t* data, uint8_t* buffer, size_t data_size, scmo_key key, uint8_t* cipherText) {
	uint8_t previous = 0x00;
	for (uint8_t k = 0; k < 8; k++) {
		previous ^= ((uint8_t*)key)[k];
	}

	for(size_t i = 0; i < data_size; i++) {
		uint8_t j = i % 4;
		uint8_t c;

		if(!j) {
			nlfsr(((uint32_t*)key)+0, ((uint32_t*)key)+1, 0x54D4D555u, parity);
			//nlfsr(((uint32_t*)key)+2, ((uint32_t*)key)+3, 0xA3000000u, parity);
			//nlfsr(((uint32_t*)key)+2, ((uint32_t*)key)+3, 0x54D4D555u, parity);
			nlfsr(((uint32_t*)key)+2, ((uint32_t*)key)+3, 0xB4BCD35Cu, parity);
		}

		c = key[j] ^ key[j+8] ^ previous;

		buffer[i] = c ^ data[i];
		previous = cipherText[i];
	}

	return buffer;
}
