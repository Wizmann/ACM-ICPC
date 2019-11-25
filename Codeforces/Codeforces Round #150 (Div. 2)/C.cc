#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int BIT = 20;

int main() {
    set<int> st[BIT];

    int n;
    input(n);

    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    for (int i = 0; i < BIT; i++) {
        for (int j = 0; j < n; j++) {
            if (ns[j] & (1 << i)) {
                st[i].insert(j);
            }
        }
    }

    unordered_set<int> res;

    for (int i = 0; i < n; i++) {
        res.insert(ns[i]);
    }

    for (int i = 0; i < n; i++) {
        map<int, vector<int> > mp;
        for (int j = 0; j < BIT; j++) {
            auto iter = st[j].lower_bound(i);
            if (iter != st[j].end()) {
                mp[*iter].push_back(j);
            }
        }

        int cur = 0;
        for (auto kv : mp) {
            for (auto b : kv.second) {
                cur |= 1 << b;
            }
            res.insert(cur);
        }
    }

    print(res.size());

    return 0;
}
