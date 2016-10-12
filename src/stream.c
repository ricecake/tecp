#include <stdio.h>
#include <stdint.h>

#include "scmo.h"
#include "util.h"

int main() {
	FILE *fp = fopen("/tmp/test.txt", "w+");

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
