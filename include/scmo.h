#ifndef _SCMO_H
#define _SCMO_H

#include <stdint.h>

uint8_t parity(uint32_t);
uint32_t nlfsr(uint32_t*, uint32_t*, uint32_t);

#endif
