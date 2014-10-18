#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int MOD = 1000000007;

llint a, b;

int main()
{
    llint sum = 0;
    input(a >> b);
    for (int i = 1; i < b; i++) {
        sum += (((1 + a) * a / 2) % MOD) * ((i * b) % MOD) + a * i;
        sum %= MOD;
    }
    print(sum);
    return 0;
}
