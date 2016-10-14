#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "scmo.h"
#include "util.h"

uint8_t* scmo_cipher(uint8_t* data, uint8_t* buffer, size_t data_size, scmo_key key) {
	uint8_t previous[8];
	memcpy((void*)previous, (void*)(key+2), 8);
	//= (uint8_t*)(key+2);
	for(size_t i = 0; i < data_size; i++) {
		uint8_t j = i % 4;
		uint8_t c;

		if(!j) {
			nlfsr(&key[0], &key[1], 0x54d4d555u, parity);
		}

		c = ((uint8_t*)key)[j];

		buffer[i] = previous[(i+1)%8] ^ (c ^ data[i]);
		previous[i%8] = buffer[i];
	}

	return buffer;
}
