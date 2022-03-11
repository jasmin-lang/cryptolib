#ifndef JADE_STREAM_CHACHA_CHACHA20_AMD64_REF2P_API_H
#define JADE_STREAM_CHACHA_CHACHA20_AMD64_REF2P_API_H

#define JADE_STREAM_CHACHA_CHACHA20_AMD64_REF2P_KEYBYTES 32
#define JADE_STREAM_CHACHA_CHACHA20_AMD64_REF2P_NONCEBYTES 8
#define JADE_STREAM_CHACHA_CHACHA20_AMD64_REF2P_ALGNAME "ChaCha20"

#include <stdint.h>

int jade_stream_chacha_chacha20_amd64_ref2p_xor(
 uint8_t *ciphertext,
 uint8_t *plaintext,
 uint64_t length,
 uint8_t *nonce, /*NONCEBYTES*/
 uint8_t *key /*KEYBYTES*/
);

int jade_stream_chacha_chacha20_amd64_ref2p(
 uint8_t *stream,
 uint64_t length,
 uint8_t *nonce, /*NONCEBYTES*/
 uint8_t *key /*KEYBYTES*/
);

#endif
