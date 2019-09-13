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
const int MAXI = 33333;

struct Mouse {
    int weight, speed, idx;

    bool operator < (const Mouse& other) const {
        if (weight != other.weight) {
            return weight < other.weight;
        }
        return speed > other.speed;
    }
};

int main() {
    int w, s;
    vector<Mouse> ns;
    ns.reserve(1234);
    int idx = 1;

    while (scanf("%d%d", &w, &s) != EOF) {
        ns.push_back({w, s, idx++});
    }

    const int n = ns.size();
    sort(ns.begin(), ns.end());

    vector<int> dp(n, 0);
    vector<int> path(n, -1);

    for (int i = 0; i < n; i++) {
        int maxi = 0;
        int maxp = -1;
        for (int j = 0; j < i; j++) {
            if (ns[j].weight == ns[i].weight) {
                continue;
            }
            if (ns[j].speed > ns[i].speed) {
                if (dp[j] > maxi) {
                    maxi = dp[j];
                    maxp = j;
                }
            }
        }
        dp[i] = maxi + 1;
        path[i] = maxp;
    }

    int maxi = 0;
    int maxp = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxi) {
            maxi = dp[i];
            maxp = i;
        }
    }

    vector<int> ans;
    while (maxp != -1) {
        ans.push_back(ns[maxp].idx);
        maxp = path[maxp];
    }

    reverse(ans.begin(), ans.end());
    printf("%lu\n", ans.size());

    for (auto num: ans) {
        printf("%d\n", num);
    }

    return 0;
}

