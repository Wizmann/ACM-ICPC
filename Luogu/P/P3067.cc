#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

void do_solve(const vector<int>& ns, int l, int r, map<llint, vector<int> >& mp) {
    int m = r - l;

    int s = 1;
    for (int i = 0; i < m; i++) {
        s *= 3;
    }

    for (int i = 0; i < s; i++) {
        int ss = i;
        llint v = 0;
        llint u = 0;
        int status = 0;
        for (int j = 0; j < m; j++) {
            int cur = ss % 3;
            ss /= 3;
            if (cur == 0) {
                // pass
            } else if (cur == 1) {
                v += ns[l + j];
                status |= 1 << (l + j);
            } else {
                u += ns[l + j];
                status |= 1 << (l + j);
            }
        }
        if (v - u < 0) {
            continue;
        }
        mp[v - u].push_back(status);
    }
}

int main() {
    int n;
    input(n);
    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    map<llint, vector<int> > mp1;
    map<llint, vector<int> > mp2;
    do_solve(ns, 0, n / 2, mp1);
    do_solve(ns, n / 2, n, mp2);

    /*
    for (auto p: mp1) {
        print(p.first << ' ' << p.second);
    }

    for (auto p: mp2) {
        print(p.first << ' ' << p.second);
    }
    */

    vector<bool> visited(1 << n, false);
    int tot = 0;
    for (auto p: mp1) {
        llint v = p.first;
        for (auto item1: mp2[v]) {
            for (auto item2: p.second) {
                int u = item1 | item2;
                if (!visited[u]) {
                    visited[u] = true;
                    tot++;
                }
            }
        }
    }
    print(tot - 1);

    return 0;
}
/*
^^TEST^^
2 
1 
1900000
---
0
$$TEST$$

^^TEST^^
2 
1 
1 
---
1
$$TEST$$

^^TEST^^
4 
1
1
200
1234 
---
1
$$TEST$$

^^TEST^^
3 
1
2 
1 
---
2
$$TEST$$

^^TEST^^
4 
1 
2 
3 
4 
---
3
$$TEST$$

^^TEST^^
4 
1 
1 
1 
1 
---
7
$$TEST$$
*/
