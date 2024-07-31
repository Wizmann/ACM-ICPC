#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int ALPHA = 32;

deque<int> dq[ALPHA];

int main() {
    int n;
    input(n);
    
    string s;
    input(s);

    int p;
    input(p);

    string a = s;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int c = a[i] - 'a';
        dq[c].push_back(i);
    }

    char first = s[p - 1];
    int ptr = dq[first - 'a'][0];

    string res;
    for (int i = 0; i < n; i++) {
        char c = s[ptr];
        res.push_back(c);
        int qtr = dq[c - 'a'].back();
        dq[c - 'a'].pop_back();
        ptr = qtr;
    }

    reverse(res.begin(), res.end());
    print(res);

    return 0;
}

/*

^^^TEST^^^
7
xelpame
7
-----
example
$$$TEST$$$

*/
