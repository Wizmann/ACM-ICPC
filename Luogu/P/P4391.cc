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

vector<int> z_function(const string& s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    int n;
    input(n);

    string s;
    input(s);

    vector<int> z = z_function(s);
    int mini = n;
    for (int i = 1; i < n; i++) {
        if (z[i] == 0) {
            continue;
        }
        int m = n - z[i];
        // print(n, i, m);
        if (z[i] != n - i) {
            continue;
        }
        mini = min(mini, m);
    }
    print(mini);

    return 0;
}

/*

^^^TEST^^^
8
cabcabca
-----
3
$$$TEST$$$

^^^TEST^^^
5
ababa
-----
2
$$$TEST$$$

^^^TEST^^^
6
aaazzz
-----
6
$$$TEST$$$

^^^TEST^^^
9
aaazzzaaa
-----
6
$$$TEST$$$

*/
