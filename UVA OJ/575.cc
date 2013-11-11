// Result: 575  Skew Binary Accepted    C++ 0.019   2013-11-11 15:24:52
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const size_t SIZE = 1024;

char num[SIZE];

int main()
{
    freopen("input.txt", "r", stdin);
    while(input(num)) {
        int n = strlen(num);
        long long ans = 0;
        long long t = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans += ((1LL << t) - 1) * (num[i] - '0');
            t++;
        }
        if (!ans) break;
        print(ans);
    }
    return 0;
}

