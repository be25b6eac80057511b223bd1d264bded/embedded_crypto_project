#define YOUR_MICROCONTROLLER_MODEL

#include "../src/crypto.h"
#include <assert.h>
#include <string.h>

char hex[27] = "48656c6c6f2c20776f726c6421";
crypto_uint8_t text[14];

void main() {
    crypto_hex2b(hex, text, 13);
    assert(strcmp(text, "Hello, world!"));
}
