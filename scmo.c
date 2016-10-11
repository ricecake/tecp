#include <stdio.h>
#include <stdint.h>


uint8_t parity(uint32_t);

int main() {
	uint32_t state = 0xdeadbeefu;
	uint32_t reg = 0;

	for(uint8_t i = 0; i < 255; i++)
		printf("val %08X -> %i\n", i, parity((uint32_t) i));


	uint8_t i = 0xFF;
	do {
		state ^= reg;
		uint8_t lsb = parity(state);
		reg >>= 1;                   /* Shift register */
		if (lsb == 1)                /* Only apply toggle mask if output bit is 1. */
			reg ^= 0x54d4d555u;  /* Apply toggle mask, value has 1 at bits corresponding */
                                             /* to taps, 0 elsewhere. */

		printf("val %08X -> %08X\n", reg, state);
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
