// Sep 7, 2013 7:49:49 PM	Wizmann	 B - Xenia and Spies	 GNU C++	Accepted	374 ms	1676 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 100010;

struct watcher {
    int t;
    int l, r;

    watcher(){}
    watcher(int it, int il, int ir):
            t(it), l(il), r(ir){}

    inline bool is_watch(int x)
    {
        return (x >= l && x <= r);
    }
};

int n, m, s, f;
watcher watchers[SIZE];

string solve()
{
    int day = 1;
    int ptr = 0;
    string res;
    int dir = f - s > 0? 1 : -1;
    while (s != f) {
        bool w = true;
        if (watchers[ptr].t != day) {
            if (ptr + 1 == m) {
                w = false;
            } else {
                if (watchers[ptr+1].t == day) {
                    ptr++;
                } else {
                    w = false;
                }
            }
        }
        if (!w) {
            s += dir;
            res += dir > 0? 'R' : 'L';
        } else {
            int next = s + dir;
            if (watchers[ptr].is_watch(s) ||
                    watchers[ptr].is_watch(next)) {
                res += 'X';
            } else {
                s += dir;
                res += dir > 0? 'R' : 'L';
            }
        }
        day++;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b, c;
    input(n >> m >> s >> f);
    for (int i = 0; i < m; i++) {
        input(a >> b >> c);
        watchers[i] = watcher(a, b, c);
    }
    print(solve());
    return 0;
}



