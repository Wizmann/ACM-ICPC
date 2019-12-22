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
 
const int INF = 0x3f3f3f3f;
 
map<int, int> collect(const vector<int>& jars) {
    int delta = 0;
    for (auto num : jars) {
        if (num == 1) {
            delta += 1;
        } else {
            delta -= 1;
        }
    }
 
    map<int, int> mp;
    mp[delta] = 0;
 
    int n = jars.size();
    for (int i = 0; i < n; i++) {
        if (jars[i] == 1) {
            delta -= 1;
        } else {
            delta += 1;
        }
        if (mp.count(delta) == 0) {
            mp[delta] = i + 1;
        }
    }
    return mp;
}
 
int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        input(n);
 
        vector<int> left(n);
        vector<int> right(n);
 
        for (int i = 0; i < n; i++) {
            scanf("%d", &left[i]);
        }
 
        for (int i = 0; i < n; i++) {
            scanf("%d", &right[i]);
        }
 
        reverse(left.begin(), left.end());
 
        map<int, int> ml = collect(left);
        map<int, int> mr = collect(right);
 
        int res = INF;
        for (auto kv : ml) {
            int delta = kv.first;
            int cnt = kv.second;
 
            if (mr.count(-delta) == 0) {
                continue;
            }
            res = min(res, cnt + mr[-delta]);
        }
        printf("%d\n", res);
    }
    return 0;
}
