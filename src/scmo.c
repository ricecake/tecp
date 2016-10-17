#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "scmo.h"
#include "util.h"

#include <stdio.h>

uint8_t* scmo_cipher(uint8_t* data, uint8_t* buffer, size_t data_size, scmo_key key, uint8_t* cipherText) {
	uint8_t previous[8];
	memcpy((void*)previous, (void*)(key+8), 8);
	for(size_t i = 0; i < data_size; i++) {
		uint8_t j = i % 4;
		uint8_t c;

		if(!j) {
			nlfsr(((uint32_t*)key), ((uint32_t*)key)+1, 0x54d4d555u, parity);
		}

		c = key[j];

		buffer[i] = (c ^ data[i]) ^ previous[i%8];
		previous[i%8] = cipherText[i];
	}

	return buffer;
}
