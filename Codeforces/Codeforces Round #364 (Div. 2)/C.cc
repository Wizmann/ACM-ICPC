#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 64;
unordered_map<char, int> mp;

void init() {
    int idx = 0;
    for (int i = 0; i < 26; i++) {
        mp['a' + i] = idx++;
    }
    for (int i = 0; i < 26; i++) {
        mp['A' + i] = idx++;
    }
}

int main() {
    freopen("C.txt", "r", stdin);
    init();

    int n;
    string flats;
    input(n >> flats);

    llint all = 0;
    for (auto flat: flats) {
        llint x = mp[flat];
        all |= 1LL << x;
    }

    llint cur = 0;
    int idx = 0;
    int ans = n;
    unordered_map<int, int> cnt;

    int p = 0;
    int q = 0;
    while (p < n && q < n) {
        char flat = flats[q];
        llint x = mp[flat];
        cur |= 1LL << x;
        
        while (cur == all && p <= q) {
            ans = min(ans, q - p + 1);
            char c = flats[p];
            llint y = mp[c];
            cnt[y]--;
            if (cnt[y] == 0) {
                cur ^= (1LL << y);
            }
            p++;
        }
        cnt[x]++;
        q++;
    }
    print(ans);

    return 0;
}
