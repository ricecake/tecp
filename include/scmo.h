#ifndef _SCMO_H
#define _SCMO_H

#include <stdint.h>
#include <stddef.h>

//typedef uint64_t scmo_key;
typedef uint32_t* scmo_key;

typedef struct {
    scmo_key key,
    uint32_t state
} scmo_state;

uint8_t* scmo_cipher(uint8_t*, uint8_t*, size_t, scmo_key);
uint8_t* scmo_decrypt(uint8_t*, uint8_t*, size_t, scmo_key);

#endif
