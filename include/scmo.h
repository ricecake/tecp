#ifndef _SCMO_H
#define _SCMO_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t* scmo_key;

typedef struct scmo_state* scmo_state;

scmo_state scmo_init(scmo_key);
void       scmo_free(scmo_state);

uint8_t* scmo_encrypt(uint8_t*, uint8_t*, size_t, scmo_key);
uint8_t* scmo_decrypt(uint8_t*, uint8_t*, size_t, scmo_key);

#endif
