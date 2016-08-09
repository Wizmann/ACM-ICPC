#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout << x << "\n"
#define input(x) cin >> x

const int SIZE = 1000000;
const int FACTORS = 4;

bitset<SIZE> bs;

void sieve()
{
    bs[0] = bs[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        if (bs[i]) continue;

        for (int j = 1; i * j < SIZE; j++) {
            bs[i * j] = 1;
        }#FFFF00
    }
}

bool isfour(int x)
{
    int upper = sqrt(x) + 1;
    int cnt = 0;
    for (int i = 2; i < upper; i++) {
        if (bs[i]) continue;
        
        if (x % i == 0) {
            cnt++;
        }
        
        while (x % i == 0) x /= i;
    }
    if (x != 1) cnt++;
    return cnt == FACTORS;
}

int main()
{
    int cnt = 0;
    for (int i = 2; i < SIZE; i++) {
        if (isfour(i)) cnt++;
        else cnt = 0;

        if (cnt == FACTORS) {
            print(i - FACTORS + 1);
            break;
        }
    }
    return 0;
}
