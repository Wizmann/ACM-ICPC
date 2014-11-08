#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;
const int INF = 0x3f3f3f3f;

int n;
llint l, x, y;
llint ns[SIZE];
unordered_set<llint> st;

bool judge(llint u, set<llint>& s)
{
    for (int i = 0; i < n; i++) {
        llint v;
        
        v = ns[i] + u;
        if (v <= l) {
            if (st.find(v) != st.end()) {
                return true;
            }
            s.insert(v);
        }
        // 
        v = ns[i] - u;
        if (v >= 0) {
            if (st.find(v) != st.end()) {
                return true;
            }
            s.insert(v);
        }
    }
    return false;
}

int main()
{
    llint u;
    input(n >> l >> x >> y);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &u);
        ns[i] = u;
        st.insert(u);
    }
    set<llint> stx, sty;
    bool bx = judge(x, stx);
    bool by = judge(y, sty);
    
    if (bx && by) {
        print(0);
    } else if (bx || by) {
        print(1);
        if (!bx) {
            while (stx.size() < 1) {}
            print(*stx.begin());
        }
        if (!by) {
            while (sty.size() < 1) {}
            print(*sty.begin());
        }
    } else {
        while (stx.size() < 1) {}
        while (sty.size() < 1) {}
        set<llint> stz;
        set_intersection(
                stx.begin(), 
                stx.end(), 
                sty.begin(), 
                sty.end(), 
                inserter(stz, stz.begin()));
        if (!stz.empty()) {
            print(1);
            print(*stz.begin());
        } else {
            print(2);
            print(*stx.begin() << ' ' << *sty.begin());
        }
    }
    return 0;
}
