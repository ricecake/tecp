#ifndef _UTIL_H
#define _UTIL_H

#include <stdint.h>

uint8_t parity(uint32_t);
uint32_t nlfsr(uint32_t*, uint32_t*, uint32_t, uint8_t(*)(uint32_t));

#endif
