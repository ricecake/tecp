#ifndef _SCMO_H
#define _SCMO_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t* scmo_key;

typedef struct {
    scmo_key key;
    uint32_t state;
    uint32_t reg;
} scmo_state;

uint8_t* scmo_cipher(uint8_t*, uint8_t*, size_t, scmo_key, uint8_t*);

#endif
