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
 
bool check(const vector<int>& ns1, const vector<int>& ns2, int x, int m) {
    vector<int> ms1;
    for (auto num : ns1) {
        ms1.push_back((num + x) % m);
    }
    sort(ms1.begin(), ms1.end());
    return ms1 == ns2;
}
 
int main() {
    int n, m;
    input(n >> m);
 
    vector<int> ns1(n), ns2(n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns1[i]);
    }
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns2[i]);
    }
 
    sort(ns1.begin(), ns1.end());
    sort(ns2.begin(), ns2.end());
 
    int res = INF;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int v1 = ns1[0];
        int v2 = ns2[i];
        int x = ((v2 - v1) % m + m) % m;
        if (st.count(x) != 0) {
            continue;
        }
        st.insert(x);
        bool flag = true;
        for (int j = 0; j < n; j++) {
            int u1 = ns1[j];
            int u2 = ns2[(i + j) % n];
            int y = ((u2 - u1) % m + m) % m;
            if (x != y) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res = min(res, x);
        }
    }
    /*
    if (res < INF) {
        assert(check(ns1, ns2, res, m));
    }
    */
    print(res);
 
    return 0;
}
