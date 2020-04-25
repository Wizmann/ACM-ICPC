#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 2001;
const int INF = 0x3f3f3f3f;

const vector<string> DIGITS = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

int diff[N][10];
char cache1[N][N];

void do_dp(int n, int k) {
    memset(cache1[n], 0, sizeof(cache1[n]));
    cache1[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            char flag = 0;
            for (int dig = 0; dig < 10; dig++) {
                int cur = i;
                int cost = diff[cur][dig];
                if (cost == -1 || cost > j) {
                    continue;
                }

                int kk = j - cost;
                assert(kk >= 0 && kk <= k);

                flag = cache1[i + 1][kk];

                assert(flag != -1);
                if (flag == 1) {
                    break;
                }
            }
            cache1[i][j] = flag;
        }
    }
}

bool dfs2(int cur, int n, int k, string& buffer) {
    if (k < 0) {
        return false;
    }
    if (cur == n) {
        return k == 0;
    }
    if (cache1[cur][k] == 0) {
        return false;
    }
    for (int i = 9; i >= 0; i--) {
        if (diff[cur][i] == -1) {
            continue;
        }
        if (k - diff[cur][i] < 0 || cache1[cur + 1][k - diff[cur][i]] == 0) {
            continue;
        }
        buffer.push_back(i + '0');
        bool res = dfs2(cur + 1, n, k - diff[cur][i], buffer);
        if (res) {
            return true;
        }
        buffer.pop_back();
    }
    return false;
}

int digit_diff(const string& a, const string& b) {
    assert(a.size() == 7);
    assert(b.size() == 7);
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (a[i] == '1' && b[i] == '0') {
            return -1;
        }
        if (a[i] == '0' && b[i] == '1') {
            cnt++;
        }
    }
    return cnt;
}

string solve(const int n, const int k, const vector<string>& digits) {
    for (int i = 0; i < n; i++) {
        const auto& digit = digits[i];
        for (int j = 0; j < 10; j++) {
            diff[i][j] = digit_diff(digit, DIGITS[j]);
        }
    }

    memset(cache1, -1, sizeof(cache1));
    do_dp(n, k);
    if (cache1[0][k] == 0) {
        return "-1";
    }

    string buffer;
    dfs2(0, n, k, buffer);
    return buffer;
}

int main() {
    int n, k;
    input(n >> k);

    char buffer[111];
    vector<string> digits;
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        digits.emplace_back(buffer);
    }

    puts(solve(n, k, digits).c_str());
    return 0;
}

