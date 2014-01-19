// Result: Jan 14, 2014 6:55:09 PM  Wizmann  C - Sereja and Prefixes     GNU C++0x  Accepted    483 ms  11040 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 100010;

struct node {
    llint st, end;
    llint prefix, rep;

    node(llint ist, llint pre, llint r) {
        st = ist;
        end = st + pre * r - 1;
        prefix = pre;
        rep = r;
    }

    node(llint ist, llint v) {
        st = end = ist;
        prefix = v;
        rep = -1;
    }

    node(){}

    bool is_value() {
        return rep == -1;
    }

    llint value() {
        return prefix;
    }
    
    bool contains(llint v) {
        return st <= v && v <= end;
    }
};

struct query {
    llint v, q;
    query(){}
    query(llint iv, llint iq): v(iv), q(iq){}
    
    friend bool operator < (const query& a, const query& b) {
        return a.v < b.v;
    }
};

priority_queue<query> pq;
int n, m;
vector<node> vec;
map<llint, llint> mp;
llint ask[SIZE];

void solve()
{
    int ptr = vec.size() - 1;
    while (!pq.empty()) {
        query nn = pq.top();
        llint now = nn.v;
        llint q = nn.q;
        pq.pop();

        while (!vec[ptr].contains(now)) {
            ptr--;
        }

        if (vec[ptr].is_value()) {
            mp[q] = vec[ptr].value();
        } else {
            llint delta = now - vec[ptr].st;
            delta %= vec[ptr].prefix;
            pq.push(query(delta + 1, q));
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    llint a, b, c;
    input(n);
    llint st = 1;
    for (int i = 0; i < n; i++) {
        input(a);
        if (a == 1) {
            input(b);
            vec.push_back(node(st, b));
            st++;
        } else {
            input(b >> c);
            vec.push_back(node(st, b, c));
            st = (--vec.end()) -> end + 1;
        }
    }
    input(m);
    for (int i = 0; i < m; i++) {
        input(a);
        ask[i] = a;
        pq.push(query(a, a));
    }
    solve();
    for (int i = 0; i < m; i++) {
        if (i) printf(" ");
        printf("%lld", mp[ask[i]]);
    }
    puts("");

    return 0;
}
