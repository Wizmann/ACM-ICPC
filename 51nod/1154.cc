#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5005;
const int INF = 0x3f3f3f3f;

vector<vector<bool> > dp0;
int dp1[SIZE];
char s[SIZE];
int n;

void do_dp() {
    for (int i = 1; i <= n; i++) {
        dp0[i][i] = 1;
    }
    
    for (int i = 2; i < n; i++) {
        for (int j = 0; i + j - 1 < n; j++) {
            int a = j;
            int b = j + i - 1;
            if (s[a] == s[b]) {
                if (a + 1 == b || dp0[a + 1 + 1][b - 1 + 1]) {
                    dp0[a + 1][b + 1] = 1;
                }
            }
        }
    }
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    dp0 = vector<vector<bool> >(n + 5, vector<bool>(n + 5, false));
    do_dp();
    
    memset(dp1, INF, sizeof(dp1));
    dp1[0] = 0;
    
    /*
    for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", dp0[i][j]);
		}
		puts("");
	}
	*/
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp0[j][i] == 0) {
                continue;
            }
            dp1[i] = min(dp1[i], dp1[j - 1] + 1);
        }
    }
    
    print(dp1[n]);
    return 0;
}
