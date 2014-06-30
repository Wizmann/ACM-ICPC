// Result: wizmann  3494    Accepted    17140K  2079MS  G++ 1317B   2014-05-24 21:08:07
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 2048;

int board[SIZE][SIZE];
int n, m;

void preload()
{
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (board[i][j] == 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            board[i][j] = cnt;
        }
    }
}

int solve()
{
    int ans = 0;
    for (int j = 0; j < m; j++) {
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && board[i][j] <= board[st.top()][j]) {
                int now = st.top();
                st.pop();
                ans = max(ans, board[now][j] * (st.empty()? i: i - st.top() - 1));
            }
            st.push(i);
        }
    }
    return ans;
}


int main()
{
    freopen("input.txt", "r", stdin);
    while (input(n >> m)) {
        memset(board, -1, sizeof(board));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        preload();
        print(solve());
    }
    return 0;
}
