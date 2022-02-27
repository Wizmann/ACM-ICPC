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

int solution(vector<string> &T) {
    map<string, int> mp;
    for (auto& s : T) {
        set<string> st;
        st.insert(s);

        swap(s[0], s[1]);
        st.insert(s);
        swap(s[0], s[1]);

        swap(s[1], s[2]);
        st.insert(s);
        swap(s[1], s[2]);

        for (auto perm : st) {
            mp[perm]++;
        }
    }

    int ans = 0;
    for (const auto& p : mp) {
        ans = max(ans, p.second);
    }

    return ans;
}



/*

^^^TEST^^^
<NULL>
-----
3
2
3
$$$TEST$$$

*/
