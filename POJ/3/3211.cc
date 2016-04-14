#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int COLOR = 15;
const int SIZE = 1111 * 111;
const int INF = 0x3f3f3f3f;

int c, n;
vector<int> clothes[COLOR];

int dp[SIZE];

int do_dp(int idx) {
    const vector<int>& vec = clothes[idx];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int sum = accumulate(vec.begin(), vec.end(), 0);
    int cnt = vec.size();
    for (int i = 0; i < cnt; i++) {
        for (int j = SIZE - 1; j >= 0; j--) {
            if (dp[j] >= 0) {
                dp[j + vec[i]] = 1;
            }
        }
    }

    int mini = INF;
    for (int i = 0; i < SIZE; i++) {
        if (dp[i] >= 0) {
            int a = i;
            int b = sum - a;
            mini = min(mini, max(a, b));
        }
    }
    return mini;
}

int main() {
    while (input(c >> n) && c + n) {
        string color;
        map<string, int> mp;

        for (int i = 0; i < COLOR; i++) {
            clothes[i].clear();
        }

        for (int i = 0; i < c; i++) {
            input(color);
            mp[color] = i;
        }

        int tm;
        for (int i = 0; i < n; i++) {
            input(tm >> color);
            int idx = mp[color];
            clothes[idx].push_back(tm);
        }

        int ans = 0;
        for (int i = 0; i < c; i++) {
            ans += do_dp(i);
        }
        print(ans);
    }
    return 0;
}
