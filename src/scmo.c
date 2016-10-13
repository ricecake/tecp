#include <stdint.h>
#include <stddef.h>

#include "scmo.h"
#include "util.h"

uint8_t* scmo_encrypt(uint8_t* data, uint8_t* buffer, size_t data_size, scmo_key key) {
	for(size_t i = 0; i < data_size; i++) {
		uint8_t j = i % 4;
		uint8_t c;
		if (!j) {
			nlfsr(((uint32_t*)&key), ((uint32_t*)&key)+1, 0x54d4d555u, parity);
		}
		c = ((uint8_t*)&key)[j];

		buffer[i] = c ^ data[i];
	}

	return data;
}
