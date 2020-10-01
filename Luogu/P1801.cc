#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int main() {
    int m, n;
    input(m >> n);

    int a;
    vector<int> ns;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        ns.push_back(a);
    }
    vector<int> qs;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        qs.push_back(a - 1);
    }

    multiset<int> st;
    st.insert(-INF);
    auto iter = st.begin();

    for (int i = 0, j = 0; i < m; i++) {
        int cur = ns[i];
        st.insert(cur);
        if (cur >= *iter) {
            // pass
        } else {
            --iter;
        }
        while (j < n && qs[j] == i) {
            ++iter;
            printf("%d\n", *iter);
            j++;
        }
    }

    return 0;
}

/*
^^^TEST^^^
7 4
3 1 -4 2 8 -1000 2
1 2 6 6
---
3
3
1
2
$$$TEST$$$

^^^TEST^^^
1 1
1
1
---
1
$$$TEST$$$

^^^TEST^^^
5 5
1 3 2 4 5
1 2 3 4 5
---
1
3
3
4
5
$$$TEST$$$
*/
