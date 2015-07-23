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

int n, m;
stack<int> st;

int main() {
    freopen("input.txt", "r", stdin);
    int x;
    input(n >> m);
    for (int i = 0; i < n; i++) {
        input(x);
        if (st.empty()) {
            st.push(x);
        } else {
            st.push(
                min(st.top(), x)
            );
        }
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        input(x);
        if (st.empty()) {
            continue;
        }
        while (!st.empty() && st.top() < x) {
            st.pop();
        }
        if (!st.empty()) {
            ans++;
            st.pop();
        }
    }
    
    return 0;
}
