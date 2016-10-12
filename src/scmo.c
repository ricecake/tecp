#include <stdio.h>
#include <stdint.h>

#include "scmo.h"

int main() {
	uint32_t state = 0xdeadbeefu;
	uint32_t reg = 0xcafebabeu;

	for(uint8_t i = 0; i < 255; i++)
		printf("val %08X -> %i\n", i, parity((uint32_t) i));


	uint16_t i = 0x00FF;
	do {
		uint32_t val = nlfsr(&reg, &state, 0x54d4d555u);
		printf("val %08X -> %08X -> %ip == %08X\n", val, state, parity(state), val ^ 0xCAFEBEEFu);
	} while(reg != 0x0u && i--);

}

uint8_t parity(uint32_t val) {
	uint8_t parity = 0x0001u;

	while(val > 0) {
		parity ^= (val & 0x0001u);
		val >>= 1u;
	}
	return parity;
}

uint32_t nlfsr(uint32_t* reg, uint32_t* state, uint32_t mask) {
	*state ^= *reg;
	uint8_t lsb = parity(*state);
	*reg >>= 1;                   /* Shift register */
	if (lsb == 1)                 /* Only apply toggle mask if output bit is 1. */
		*reg ^= mask;         /* Apply toggle mask, value has 1 at bits corresponding */
		                      /* to taps, 0 elsewhere. */
	return *reg;
}
