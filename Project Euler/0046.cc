#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << "\n"

const int SIZE = 100000;

bitset<SIZE> bs;

void sieve() 
{
    bs.reset();
    bs[0] = bs[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        if (bs[i]) {
            continue;
        }
        for (int j = 2; i * j < SIZE; j++) {
            bs[i * j] = 1;
        }
    }
}

int main() 
{
    sieve();
    for (int i = 3; i < SIZE; i+=2) {
        if (!bs[i]) continue;
        int v = i;
        bool flag = false;
        for (int j = 1; 2 * j * j < v; j++) {
            int u = v - 2 * j * j;
            if (!bs[u]) {
                flag = true;
                break;
            }
        }
        if (!flag) print(i);
    }
    return 0;
}
