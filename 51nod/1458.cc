#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 111111;
const int MOD = 1000000007;

int father[SIZE * 2];

int n, m;

inline int opp(int x) {
    return x + SIZE;
}

void init() {
    for (int i = 0; i < SIZE * 2; i++) {
        father[i] = i;
    }
}

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

void make_union(int a, int b) {
    int fa = find_father(a);
    int fb = find_father(b);
    father[fb] = fa;
}

bool check(int x) {
    return find_father(x) != find_father(opp(x));
}

llint pow2(int x) {
    llint res = 1;
    for (int i = 0; i < x; i++) {
        res = (res * 2) % MOD;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b, c;
    input(n >> m);
    init();
    
    bool flag = true;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (c == 0) {
            make_union(a, opp(b));
            make_union(b, opp(a));
        } else {
            make_union(a, b);
            make_union(opp(a), opp(b));
        }
        flag &= check(a) && check(b);
    }
    
    if (flag == false) {
        print(0);
        exit(0);
    }
    
    unordered_set<int> st;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        a = find_father(i);
        b = find_father(opp(i));
        
        if (st.find(a) != st.end() || st.find(b) != st.end()) {
            continue;
        }
        
        // print(a << ' ' << b);
        
        cnt++;
        st.insert(a);
        st.insert(b);
    }
    
    print(pow2(cnt - 1));
    return 0;
}
