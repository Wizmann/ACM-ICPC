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

const int ALPHA = 256;
const string UNSOLVABLE = "UNSOLVABLE";
string a, b, c;
int mp[ALPHA];

llint string_to_int(const string& s) {
    int n = s.size();
    llint res = 0;
    if (mp[s[0]] == 0) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        res = res * 10 + mp[s[i]];
    }

    return res;
}

bool check() {
    llint aa = string_to_int(a);
    if (aa == -1) {
        return false;
    }
    llint bb = string_to_int(b);
    if (bb == -1) {
        return false;
    }
    llint cc = string_to_int(c);
    if (cc == -1) {
        return false;
    }
    return aa + bb == cc;
}

int main() {
    input(a, b, c);

    string charset = a + b + c;
    sort(charset.begin(), charset.end());

    charset.erase(std::unique(charset.begin(), charset.end()), charset.end());

    if (charset.size() > 10) {
        puts(UNSOLVABLE.c_str());
        return 0;
    }

    vector<int> ns;
    for (int i = 0; i < 10; i++) {
        ns.push_back(i);
    }

    bool flag = false;
    do {
        memset(mp, -1, sizeof(mp));
        for (int i = 0; i < charset.size(); i++) {
            mp[charset[i]] = ns[i];
        }

        if (check()) {
            flag = true;
            break;
        }
    } while (next_permutation(ns.begin(), ns.end()));


    if (flag) {
        llint aa = string_to_int(a);
        llint bb = string_to_int(b);
        llint cc = string_to_int(c);

        printf("%lld\n", aa);
        printf("%lld\n", bb);
        printf("%lld\n", cc);
    } else {
        puts(UNSOLVABLE.c_str());
    }

    return 0;
}

/*

^^^TEST^^^
a
b
c
-----
1
2
3
$$$TEST$$$

^^^TEST^^^
x
x
y
----
1
1
2
$$$TEST$$$


^^^TEST^^^
p
q
p
---
UNSOLVABLE
$$$TEST$$$

^^^TEST^^^
abcd
efgh
ijkl
---
UNSOLVABLE
$$$TEST$$$

^^^TEST^^^
send
more
money
----
9567
1085
10652
$$$TEST$$$


*/
