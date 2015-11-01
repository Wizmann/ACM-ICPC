#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5000555;

vector<int> sieve;

void init() {
    sieve.resize(SIZE);
    for (int i = 2; i < SIZE; i++) {
        if (sieve[i] != 0) {
            continue;
        }
        for (int j = 1; i * j < SIZE; j++) {
            int u = i * j;
            while (u % i == 0) {
                sieve[i * j]++;
                u /= i;
            }
        }
    }

    for (int i = 2; i < SIZE; i++) {
        sieve[i] += sieve[i - 1];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int a, b;
    input(T);
    init();
    while (T--) {
        input(a >> b);
        print(sieve[a] - sieve[b]);
    }
    return 0;
}
