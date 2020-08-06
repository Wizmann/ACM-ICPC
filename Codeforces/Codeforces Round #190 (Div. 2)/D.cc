#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111'111;
const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> atks;
    vector<int> defs;

    char buffer[10];
    int value;
    for (int i = 0; i < n; i++) {
        scanf("%s%d", buffer, &value);
        if (buffer[0] == 'A') {
            atks.push_back(value);
        } else {
            defs.push_back(value);
        }
    }
    sort(atks.begin(), atks.end());
    sort(defs.begin(), defs.end());

    vector<int> cards(m);;
    for (int i = 0; i < m; i++) {
        scanf("%d", &cards[i]);
    }
    sort(cards.begin(), cards.end());

    int tot1 = 0;
    do {
        multiset<int> st;
        for (auto card: cards) {
            st.insert(card);
        }
        for (auto def: defs) {
            auto iter = st.upper_bound(def);
            if (iter == st.end()) {
                tot1 = -INF;
                break;
            } else {
                st.erase(iter);
            }
        }
        if (tot1 < 0) {
            break;
        }
        int ptr = atks.size() - 1;
        for (auto iter = st.rbegin(); iter != st.rend(); ++iter) {
            if (ptr == -1) {
                tot1 += *iter;
            } else if (*iter >= atks[ptr]) {
                tot1 += *iter - atks[ptr];
                ptr--;
            } else {
                tot1 = -INF;
                break;
            }
        }
    } while(0);

    int tot2 = 0;
    {
        int u = min(atks.size(), cards.size());
        int p = 0;
        int q = 0;
        for (int i = 0; i < u; i++) {
            p += cards[cards.size() - i - 1];
            q += atks[i];

            if (atks[i] <= cards[cards.size() - i - 1]) {
                tot2 = max(tot2, p - q);
            } else {
                break;
            }
        }
    }
    // print(tot1 << " " << tot2);
    print(max(tot1, tot2));

    return 0;
}
