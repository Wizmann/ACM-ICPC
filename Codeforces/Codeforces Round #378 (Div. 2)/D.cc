#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
map<pair<int, int>, set<pair<int, int>> > mp;

int min3(int a, int b, int c) {
    return min( min(a, b), c );
}

void add(int a, int b, pair<int, int> c) {
    pair<int, int> p = {a, b};
    if (mp.find(p) == mp.end()) {
        mp[p] = set<pair<int, int> >();
    }

    mp[p].insert(c);

    while (mp[p].size() > 2) {
        mp[p].erase(mp[p].begin());
    }
}

int main() {
    int a, b, c;

    input(n);
    for (int i = 0; i < n; i++) {
        input(a >> b >> c);

        add(min(a, b), max(a, b), {c, i + 1});
        add(min(a, c), max(a, c), {b, i + 1});
        add(min(b, c), max(b, c), {a, i + 1});
    }

    int ans = 0;
    vector<int> result;

    for (const auto& kvpair: mp) {
        const auto& key = kvpair.first;
        const auto& value = kvpair.second;

        int a = key.first;
        int b = key.second;

        if (value.size() == 1) {
            int v = min3(a, b, value.begin()->first);

            if (v > ans) {
                ans = v;
                result = vector<int>{value.begin()->second};
            }
        }

        if (value.size() == 2) {
            int v = min3(
                    a, b, 
                    value.begin()->first + value.rbegin()->first);

            if (v > ans) {
                ans = v;
                result = vector<int>{value.begin()->second, value.rbegin()->second};
            }
        }
    }

    print(result.size());
    for (auto item: result) {
        printf("%d ", item);
    }
    return 0;
}
