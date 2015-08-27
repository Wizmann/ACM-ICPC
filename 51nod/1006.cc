#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;

int dp[SIZE][SIZE];
string a, b;

void solve(int& x, int& y) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    int n = a.size();
    int m = b.size();
    int maxi = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            
            if (dp[i][j] > maxi) {
                maxi = dp[i][j];
                y = i;
                x = j;
            }
        }
    }
}

string get_result(int x, int y) {
    string res;
    
    while (x && y) {
        if (a[y - 1] == b[x - 1]) {
            res += a[y - 1];
            x--;
            y--;
            continue;
        }
        if (dp[y][x] == dp[y - 1][x]) {
            y--;
        } else if (dp[y][x] == dp[y][x - 1]) {
            x--;
        } else {
            x--;
            y--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    input(a >> b);
    
    int x, y;
    solve(x, y);
    
    string res = get_result(x, y);
    print(res);
    return 0;
}
