#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MOD = 1000000000 + 7;
const int N = 234567;

int n;
vector<int> ns;
vector<int> v;
vector<int> prefix;

llint fastpow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        input(n);
        ns = vector<int>(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        sort(ns.begin(), ns.end());
        prefix = vector<int>(N, 0);
        v = vector<int>(N, 0);

        for (int i = 0; i < n; i++) {
            prefix[ns[i]]++;
        }
        
        for (int i = 1; i < N; i++) {
            prefix[i] += prefix[i - 1];
        }

        llint ans = 0;
        for (int i = 2; i <= ns[0]; i++) {
            if (v[i] != 1) {
                int d = 1 - v[i];
                llint cur = 1;
                int pre = 1;
                for (int j = 1; j <= ns[n - 1] / i; j++) {
                    int x = j * i;
                    v[x] += d;
                    cur = cur * fastpow(j, prefix[x + i - 1] - prefix[pre - 1]) % MOD;
                    pre = x + i;
                }
                ans = ((ans + cur * d) % MOD + MOD) % MOD;
            }
        }
        printf("Case #%d: ", case_ + 1);
        print(ans);
    }

    return 0;
}
