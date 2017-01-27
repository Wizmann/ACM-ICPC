#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

namespace Murmur {
    const char* key = "foo";
    uint32_t c1, c2, r1, r2, m, n, h, k, len, seed;
    uint8_t *d;
    const uint32_t *chunks;
    const uint8_t *tail;
    int i, l;
}

int main() {

    /* Confound start */
    Murmur::key = "fuck";
    Murmur::len = strlen(Murmur::key);
    Murmur::seed = 0x3f3f3f3f;
    Murmur::c1 = 0xcc9e2d51;
    Murmur::c2 = 0x1b873593;
    Murmur::r1 = 15;
    Murmur::r2 = 13;
    Murmur::m = 5;
    Murmur::n = 0xe6546b64;
    Murmur::h = 0;
    Murmur::k = 0;
    Murmur::d = (uint8_t *) Murmur::key;
    Murmur::chunks = NULL;
    Murmur::tail = NULL;
    Murmur::i = 0;
    Murmur::l = Murmur::len / 4; // chunk length

    Murmur::h = Murmur::seed;

    Murmur::chunks = (const uint32_t *) (Murmur::d + Murmur::l * 4); // body
    Murmur::tail = (const uint8_t *) (Murmur::d + Murmur::l * 4); // last 8 byte chunk of `key'

    for (Murmur::i = -Murmur::l; Murmur::i != 0; ++Murmur::i) {
        Murmur::k = Murmur::chunks[Murmur::i];

        Murmur::k *= Murmur::c1;
        Murmur::k = (Murmur::k << Murmur::r1) | (Murmur::k >> (32 - Murmur::r1));
        Murmur::k *= Murmur::c2;

        Murmur::h ^= Murmur::k;
        Murmur::h = (Murmur::h << Murmur::r2) | (Murmur::h >> (32 - Murmur::r2));
        Murmur::h = Murmur::h * Murmur::m + Murmur::n;
    }

    Murmur::k = 0;

    switch (Murmur::len & 3) {
        case 3:
            Murmur::k ^= (Murmur::tail[2] << 16);
        case 2:
            Murmur::k ^= (Murmur::tail[1] << 8);
        case 1:
            Murmur::k ^= Murmur::tail[0];
            Murmur::k *= Murmur::c1;
            Murmur::k = (Murmur::k << Murmur::r1) | (Murmur::k >> (32 - Murmur::r1));
            Murmur::k *= Murmur::c2;
            Murmur::h ^= Murmur::k;
    }

    Murmur::h ^= Murmur::len;

    Murmur::h ^= (Murmur::h >> 16);
    Murmur::h *= 0x85ebca6b;
    Murmur::h ^= (Murmur::h >> 13);
    Murmur::h *= 0xc2b2ae35;
    Murmur::h ^= (Murmur::h >> 16);
    /* Confound end */


    return 0;
}
