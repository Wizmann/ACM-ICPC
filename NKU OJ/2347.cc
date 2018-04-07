#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 234567 * 2;

int n, m;
vector<int> father;
map<string, int> mp;

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

int main() {
    input(m >> n);

    father.resize(SIZE);
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }

    int idx = 0;
    string sa, sb, sc;
    for (int i = 0; i < m; i++) {
        input(sa >> sb >> sc);

        if (mp.count(sa) == 0) {
            mp[sa] = idx++;
        }

        if (mp.count(sc) == 0) {
            mp[sc] = idx++;
        }

        assert(sb == "is");
        
        int a = mp[sa];
        int b = mp[sc];

        father[find_father(a)] = find_father(b);
    }

    for (int i = 0; i < n; i++) {
        input(sa >> sb >> sc);

        assert(sb == "is");

        if (mp.count(sa) == 0 || mp.count(sc) == 0) {
            puts("yattaze");
            continue;
        }
        
        int a = mp[sa];
        int b = mp[sc];

        if (find_father(a) == find_father(b)) {
            puts("Q.E.D");
        } else {
            puts("yattaze");
        }
    }
    return 0;
}
