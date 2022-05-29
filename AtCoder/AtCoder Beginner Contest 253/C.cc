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

int main() {
    int q;
    input(q);

    int cmd;
    int x, c;

    multiset<int> st;
    for (int i = 0; i < q; i++) {
        scanf("%d", &cmd);

        if (cmd == 1) {
            scanf("%d", &x);
            st.insert(x);
        } else if (cmd == 2) {
            scanf("%d%d", &x, &c);
            for (int j = 0; j < c; j++) {
                auto iter = st.find(x);
                if (iter == st.end()) {
                    break;
                }
                st.erase(iter);
            }
        } else if (cmd == 3) {
            int maxi = *st.rbegin();
            int mini = *st.begin();
            printf("%d\n", maxi - mini);
        } else {
            assert(false);
        }
    }

    return 0;
}

/*

^^^TEST^^^
8
1 3
1 2
3
1 2
1 7
3
2 2 3
3
-----
1
5
4
$$$TEST$$$

^^^TEST^^^
4
1 10000
1 1000
2 100 3
1 10
-------

$$$TEST$$$

*/
