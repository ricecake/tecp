#include <stdint.h>

uint8_t parity(uint32_t val) {
	uint8_t parity = 0x0001u;

	while(val > 0) {
		parity ^= (val & 0x0001u);
		val >>= 1u;
	}

	return parity;
}

