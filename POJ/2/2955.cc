#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111;

int dp[SIZE][SIZE];

class Solution {
public:
    Solution(const string& s_) : n(s_.size()), s(s_) {
        // pass
    }

    int solve() {
        memset(dp, -1, sizeof(dp));
        return max(do_solve(0, n - 1), do_solve(0, n - 1));
    }

    int do_solve(int l, int r) {
        if (l > r) {
            return 0;
        }

        int& u = dp[l][r];
        if (u != -1) {
            return u;
        }

        const char b[] = "([";
        const char d[] = ")]";

        int ans = 0;
        for (int i = 0; i < 2; i++) {
            int ll = l;
            while (ll <= r) {
                if (s[ll] == b[i]) {
                    break;
                }
                ll++;
            }

            int rr = ll;
            while (rr <= r) {
                if (s[rr] == d[i]) {
                    ans = max(ans, 2 + do_solve(ll + 1, rr - 1) + do_solve(rr + 1, r));
                }
                rr++;
            }
        }

        return u = ans;
    }
private:
    int n;
    string s;
};

int main() {
    string s;
    while (input(s) && s != "end") {
        Solution S(s);
        printf("%d\n", S.solve());
    }
    return 0;
}
