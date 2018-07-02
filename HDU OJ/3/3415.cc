#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int n, k;
vector<int> ns;

struct Answer {
    int ans, l, r;

    bool operator < (const Answer& other) const {
        if (ans != other.ans) {
            return ans < other.ans;
        } else if (l != other.l) {
            return (l - 1) % n > (other.l - 1) % n;
        } else {
            return (r - l + 1) > (other.r - other.l + 1);
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    input(T);

    while (T--) {
        scanf("%d%d", &n, &k);
        k = min(k, n);
        ns = vector<int>(n + n + 1, 0);
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &ns[i]);
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            ns[i] = ns[i - n];
        }
        for (int i = 1; i <= 2 * n; i++) {
            ns[i] += ns[i - 1];
        }


        Answer ans = {-INF, INF, INF};

        deque<int> st;

        for (int i = 0; i <= 2 * n; i++) {
            while (!st.empty() && i - st.front() > k) {
                st.pop_front();
            }
            if (!st.empty()) {
                int u = ns[i] - ns[st.front()];
                Answer cur = {u, st.front() + 1, i};
                if (ans < cur) {
                    ans = cur;
                }
            }
            while (!st.empty() && ns[i] <= ns[st.back()]) {
                st.pop_back();
            }
            st.push_back(i);
        }
        printf("%d %d %d\n", ans.ans, (ans.l - 1) % n + 1, (ans.r - 1) % n + 1);
    }

    return 0;
}
