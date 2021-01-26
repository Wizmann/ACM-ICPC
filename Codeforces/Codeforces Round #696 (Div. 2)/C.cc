#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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

bool do_solve(int tot, const vector<int>& ns, vector<pair<int, int> >& ps) {
    const int n = ns.size();
    multiset<int> st;
    for (auto num : ns) {
        st.insert(num);
    }
    
    ps.clear();
    int pre = tot;

    for (int i = 0; i < n / 2; i++) {
        int a = *st.rbegin();
        st.erase(st.find(a));
        int b = pre - a;
        if (st.count(b) == 0) {
            return false;
        }
        ps.push_back({a, b});
        st.erase(st.find(b));

        pre = max(a, b);
    }

    return true;
}

bool solve(vector<int>& ns, vector<pair<int, int> >& ps) {
    const int n = ns.size();
    sort(ns.begin(), ns.end());
    int maxi = ns.back();
    for (int i = 0; i < n - 1; i++) {
        int tot = maxi + ns[i];
        if (do_solve(tot, ns, ps)) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    input(T);
    while (T--) {
        int n;
        input(n);
        vector<int> ns(n * 2);
        for (int i = 0; i < n * 2; i++) {
            scanf("%d", &ns[i]);
        }

        vector<pair<int, int> > res;
        bool flag = solve(ns, res);
        if (flag) {
            puts("YES");
            printf("%d\n", res[0].first + res[0].second);
            for (const auto& p : res) {
                printf("%d %d\n", p.first, p.second);
            }
        } else {
            puts("NO");
        }
    }

    return 0;
}

/*

^^^TEST^^^
4
2
3 5 1 2
3
1 1 8 8 64 64
2
1 1 2 4
5
1 2 3 4 5 6 7 14 3 11
-----
YES
6
1 5
2 3
NO
NO
YES
21
14 7
3 11
5 6
2 4
3 1
$$$TEST$$$

*/
