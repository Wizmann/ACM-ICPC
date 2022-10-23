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

int n, m;
vector<int> ns;

string solve(int prefix) {
    vector<int> ms = ns;
    assert(prefix + 1 < (int)ms.size());

    int cur = ms[prefix + 1];
    ms[prefix + 1] = -INF;
    for (int i = cur + 1; i < m; i++) {
        if (i == ms[prefix] || i == ms[prefix - 1]) {
            continue;
        }
        ms[prefix + 1] = i;
        break;
    }

    if (ms[prefix + 1] == -INF) {
        return "";
    }

    for (int i = prefix + 2; i < n + 2; i++) {
        assert(i < (int)ms.size());
        ms[i] = -INF;
        for (int j = 0; j < m; j++) {
            assert(i - 1 >= 0 && i - 2 >= 0);
            if (j != ms[i - 1] && j != ms[i - 2]) {
                ms[i] = j;
                break;
            }
        }
        if (ms[i] == -INF) {
            break;
        }
    }

    string res;
    for (int i = 2; i < n + 2; i++) {
        assert(ms[i] < m);
        assert(i < (int)ms.size());
        res.push_back(ms[i] + 'a');
    }
    return res;
}

int main() {
    input(n, m);

    string ss;
    input(ss);

    ns.resize(n + 2);
    ns[0] = -2;
    ns[1] = -1;
    for (int i = 0; i < n; i++) {
        ns[i + 2] = ss[i] - 'a';
    }

    string res;
    for (int i = n + 1; i >= 2; i--) {
        res = solve(i - 1);
        if (!res.empty()) {
            break;
        }
    }

    if (res.empty()) {
        print("NO");
    } else {
        puts(res.c_str());
    }

    return 0;
}

/*

^^^TEST^^^
3 3
cba
-----
NO
$$$TEST$$$

^^^TEST^^^
3 4
cba
-----
cbd
$$$TEST$$$

^^^TEST^^^
4 4
abcd
-----
abda
$$$TEST$$$

*/
