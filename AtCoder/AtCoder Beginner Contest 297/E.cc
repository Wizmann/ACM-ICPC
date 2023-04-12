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
    int n, k;
    input(n, k);
    k++;

    priority_queue<llint,
                  vector<llint>,
                  greater<llint>> pq;

    llint u;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &u);
        pq.push(u);
    }

    set<llint> st;
    st.insert(0);

    while (!pq.empty()) {
        llint cur = pq.top();
        pq.pop();

        
        if ((int)st.size() >= k && cur > *st.rbegin()) {
            continue;
        }

        llint maxi = INFLL;
        if ((int)st.size() >= k) {
            maxi = *st.rbegin();
        }

        pq.push(cur * 2);

        set<llint> st2;
        for (llint num : st) {
            if (num + cur < maxi) {
                st2.insert(num + cur);
            }
        }

        for (llint num : st2) {
            st.insert(num);
        }

        while ((int)st.size() > k) {
            st.erase(--st.end());
        }
    }

    /*
    for (auto num : st) {
        print(num);
    }
    puts("---");
    */

    print(*st.rbegin());

    return 0;
}

/*

^^^TEST^^^
4 6
20 25 30 100
-----
50
$$$TEST$$$

^^^TEST^^^
10 200000
955277671 764071525 871653439 819642859 703677532 515827892 127889502 881462887 330802980 503797872
-----
5705443819
$$$TEST$$$

*/
