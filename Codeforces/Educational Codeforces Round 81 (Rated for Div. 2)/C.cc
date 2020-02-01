#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
const int SIZE = 123456;
const int ALPHA = 32;
 
char buffer[SIZE];
vector<int> g[ALPHA];
 
int solve(const string& s, const string& t) {
    for (int i = 0; i < ALPHA; i++) {
        g[i].clear();
    }
 
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        g[c].push_back(i);
    }
 
    int m = t.size();
    for (int i = 0; i < m; i++) {
        int c = t[i] - 'a';
        if (g[c].empty()) {
            return -1;
        }
    }
 
    int p = 0;
    int q = 0;
    int step = 1;
 
    while (q < m) {
        if (p == n) {
            step += 1;
            p = 0;
            continue;
        }
        int cur = t[q] - 'a';
        auto iter = lower_bound(g[cur].begin(), g[cur].end(), p);
 
        if (iter == g[cur].end()) {
            step += 1;
            p = 0;
            continue;
        }
 
        p = *iter + 1;
        q += 1;
    }
    return step;
}
 
int main() {
    int T;
    input(T);
 
    assert(solve("ty", "yyt") == 3);
 
    while (T--) {
        scanf("%s", buffer);
        string s(buffer);
 
        scanf("%s", buffer);
        string t(buffer);
 
        printf("%d\n", solve(s, t));
    }
    return 0;
}
