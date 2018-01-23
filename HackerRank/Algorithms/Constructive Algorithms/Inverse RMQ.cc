#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int BITSIZE = 20;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    Solution(int n_, const vector<int>& ns): n(n_), m(n * 2 - 1) {
        
        map<int, int> counter;

        for (int num: ns) {
            counter[num]++;
        }

        for (const auto& p: counter) {
            insert_number(p.first, p.second);
        }
    }

    void insert_number(int value, int count) {
        if (count >= BITSIZE) {
            ladder[BITSIZE].insert(value);
        } else {
            ladder[count].insert(value);
        }
    }

    int log2(int x) {
        int res = 0;
        while (x) {
            x >>= 1;
            res++;
        }
        return res;
    }

    vector<int> solve() {
        vector<int> res(m, -1);
        for (int i = 0; i < m; i++) {
            if (res[i] != -1) {
                continue;
            }
            int depth = log2(n) - log2(i + 1) + 1;
            int father = i == 0? -INF: res[(i - 1) / 2];

            if (ladder[depth].empty()) {
                return {};
            }

            auto mini = ladder[depth].lower_bound(father);
            if (mini == ladder[depth].end()) {
                return {};
            }
            int cnt = 0;

            int p = i;
            while (p < m) {
                res[p] = *mini;
                cnt++;
                p = p * 2 + 1;
            }

            if (cnt != depth) {
                print("fuck");
            }

            ladder[depth].erase(mini);

            // print(mini << ' ' << slot - cnt);
        }
        return res;
    }
private:
    int n;
    int m;
    set<int> ladder[BITSIZE + 1];
};


int main() {
    int n;

    input(n);
    vector<int> ns(n * 2 - 1);
    for (int i = 0; i < n * 2 - 1; i++) {
        scanf("%d", &ns[i]);
    }

    auto S = Solution(n, ns);
    auto res = S.solve();

    puts(res.empty()? "NO": "YES");

    if (!res.empty()) {
        for (auto num: res) {
            printf("%d ", num);
        }
        puts("");
    }

    return 0;
}

