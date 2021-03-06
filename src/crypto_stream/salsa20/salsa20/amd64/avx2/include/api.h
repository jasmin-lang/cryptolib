#ifndef JADE_STREAM_SALSA20_SALSA20_AMD64_AVX2_API_H
#define JADE_STREAM_SALSA20_SALSA20_AMD64_AVX2_API_H

#define JADE_STREAM_SALSA20_SALSA20_AMD64_AVX2_KEYBYTES 32
#define JADE_STREAM_SALSA20_SALSA20_AMD64_AVX2_NONCEBYTES 8
#define JADE_STREAM_SALSA20_SALSA20_AMD64_AVX2_ALGNAME "Salsa20/20"

#include <stdint.h>

int jade_stream_salsa20_salsa20_amd64_avx2_xor(
 uint8_t *ciphertext,
 uint8_t *plaintext,
 uint64_t length,
 uint8_t *nonce, /*NONCEBYTES*/
 uint8_t *key /*KEYBYTES*/
);

int jade_stream_salsa20_salsa20_amd64_avx2(
 uint8_t *stream,
 uint64_t length,
 uint8_t *nonce, /*NONCEBYTES*/
 uint8_t *key /*KEYBYTES*/
);

#endif
