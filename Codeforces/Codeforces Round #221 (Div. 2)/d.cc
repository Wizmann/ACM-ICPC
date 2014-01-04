//Result: Dec 24, 2013 6:33:57 PM   Wizmann  D - Maximum Submatrix 2     GNU C++    Accepted     1092 ms     103300 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5120;

int g[SIZE][SIZE];
char buffer[SIZE];
int n, m;
stack<int> st;

int main()
{
    freopen("input.txt", "r", stdin);
    
    while (input(n >> m)) {
        memset(g, 0, sizeof(g));
        memset(buffer, 0, sizeof(buffer));
        st = stack<int>();

        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            int p = 0;
            for (int j = m - 1; j >= 0; j--) {
                buffer[j] -= '0';
                if (buffer[j] == 1) {
                    p++;
                } else {
                    p = 0;
                }
                g[i][j] = p;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<int> vec;
            for (int j = 0; j < n; j++) {
                vec.push_back(g[j][i]);
            }
            sort(vec.begin(), vec.end());

            int t = 0;
            for (int j = 0; j < n; j++) {
                t = max(t, vec[j] * (n - j));
            }

            ans = max(ans, t);
        }
        print(ans);
    }
    return 0;
}
