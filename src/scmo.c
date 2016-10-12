#include <stdint.h>
#include "scmo.h"
#include "util.h"

uint32_t nlfsr(uint32_t* reg, uint32_t* state, uint32_t mask) {
	*state ^= *reg;
	uint8_t lsb = parity(*state);
	*reg >>= 1;

	if(lsb == 1) {
		/* Apply toggle mask, value has 1 at bits corresponding
		 * to taps, 0 elsewhere. */
		*reg ^= mask;
	}

	return *reg;
}
