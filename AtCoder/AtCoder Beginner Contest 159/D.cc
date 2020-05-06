#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>

using namespace std;

typedef long long llint;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X& x, T... args) { cout << x << " "; print(args...); }

void input() { /* pass */ }

template <typename...T, typename X>
void input(X& x, T&... args) { cin >> x; input(args...); }

int main()
{
    int n;
    input(n);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    map<int, int> mp;
    for (auto num: ns) {
        mp[num]++;
    }

    llint tot = 0;
    for (auto kv: mp) {
        tot += 1LL * kv.second * (kv.second - 1) / 2;
    }

    for (int i = 0; i < n; i++) {
        llint u = tot;
        int cur = ns[i];
        int cnt = mp[cur];
        u -= 1LL * cnt * (cnt - 1) / 2;
        u += 1LL * (cnt - 1) * (cnt - 2) / 2;
        puts(to_string(u).c_str());
    }

    return 0;
}
