#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int w, h, n;
multiset<llint> st[2];
multiset<llint> pq[2];

llint add(int A, int B, int u) {
    auto p = st[B].equal_range(u);
    llint l = *(--p.first);
    llint r = *p.second;
    
    st[B].insert(u);
    llint diff = r - l;
    auto iter = pq[B].find(diff);
    pq[B].erase(iter);
    pq[B].insert(u - l);
    pq[B].insert(r - u);
    return (*pq[A].rbegin()) * (*pq[B].rbegin());
}

llint addH(int u) {
    return add(0, 1, u);
}

llint addV(int u) {
    return add(1, 0, u);
}

int main() {
    char cmd[10];
    int u;
    
    input(w >> h >> n);
    
    st[0].insert(0);
    st[0].insert(w);
    st[1].insert(0);
    st[1].insert(h);
    pq[0].insert(w);
    pq[1].insert(h);
    
    while (n--) {
        input(cmd >> u);
        if (*cmd == 'H') {
            print(addH(u));
        } else {
            print(addV(u));
        }
    }
    return 0;
}
