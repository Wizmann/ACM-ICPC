#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 2000000;

char prime[SIZE + 10];

int main()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < sqrt(SIZE) + 1; i++) {
        if (prime[i]) continue;
        for (int j = 2; (long long)j * i <= SIZE; j++) {
            prime[i * j] = 1;
        }
    }
    unsigned long long sum = 0;
    for (int i = 2; i <= SIZE; i++) {
        if (!prime[i]) {
            sum += i;
        }
    }
    print(sum);
    return 0;
}


