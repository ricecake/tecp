#include <stdint.h>

uint8_t parity(uint32_t val) {
	uint8_t parity = 0x01u;

	while(val > 0) {
		parity ^= (val & 0x00000001u);
		val >>= 1u;
	}

	return parity;
}

uint32_t nlfsr(uint32_t* reg, uint32_t* state, uint32_t mask, uint8_t (*filter)(uint32_t)) {
	*state ^= *reg;
	uint8_t lsb = filter(*state);
	*reg >>= 1;

	if(lsb == 1) {
		/* Apply toggle mask, value has 1 at bits corresponding
		 * to taps, 0 elsewhere. */
		*reg ^= mask;
	}

	return *reg;
}
