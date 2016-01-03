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

const int SIZE = 555;

int board[SIZE][SIZE];
int n, m;

int solve(int array[]) {
    stack<int> st;
    int res = 0;
    for (int i = 0; i <= m; i++) {
        while (!st.empty() && array[i] <= array[st.top()]) {
            int t = st.top();
            st.pop();
            int left = (st.empty()? 0: st.top() + 1);
            int right = i - 1;
            int height = array[t];
            res = max(res, height * (right - left + 1));
        }
        st.push(i);
    }
    return res;
}

int main() {
    input(n >> m);
    memset(board, -1, sizeof(board));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] += (board[i][j] && i - 1 >= 0? board[i - 1][j]: 0);
        }
        ans = max(ans, solve(board[i]));
    }
    print(ans);
    return 0;
}
