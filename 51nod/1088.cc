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

char dp[SIZE][SIZE];

string str;

int main() {
    input(str);
    int n = str.size();
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            int l = j;
            int r = j + i;
            if (str[l] == str[r]) {
                if (l + 1 == r) {
                    dp[l][r] = 1;
                } else {
                    dp[l][r] |= dp[l + 1][r - 1];
                }
            }
            if (dp[l][r]) {
                ans = max(ans, r - l + 1);
            }
        }
    }
    print(ans);
    return 0;
}
