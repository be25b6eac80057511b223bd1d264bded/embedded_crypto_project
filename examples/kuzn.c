#define YOUR_MICROCONTROLLER_MODEL

#include "../src/crypto.h"
#include <assert.h>

char key_hex[65] = "8899aabbccddeeff0011223344556677fedcba98765432100123456789abcdef";
char block_hex[33] = "1122334455667700ffeeddccbbaa9988";
crypto_uint8_t key[33];
crypto_uint8_t block[17];
crypto_uint8_t enc[17];
crypto_res_t res;

void main() {
    kuzn_ecb_ctx ctx;
    kuzn_ecb_init_ctx(ctx);

    crypto_hex2b(key_hex, key, 32);
    crypto_hex2b(block_hex, block, 16);

    res = kuzn_ecb_set_key(ctx, key);

    if (res != CRYPTO_OK) {
        crypto_debug_send(res);
        crypto_debug_halt();
    }

    kuzn_ecb_encrypt_block(ctx, block, enc);

    kuzn_b2hex(enc, enc_hex, 16);
    assert(strcmp(enc_hex, "7f679d90bebc24305a468d42b9d4edcd"));
}
