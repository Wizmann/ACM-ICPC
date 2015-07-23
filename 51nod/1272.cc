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

int n;
vector<int> ns;

int main() {
    freopen("input.txt", "r", stdin);
    int x;
    input(n);
    for (int i = 0; i < n; i++) {
        input(x);
        ns.push_back(x);
    }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty() || ns[i] < ns[st.top()]) {
            st.push(i);
        }
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && ns[i] >= ns[st.top()]) {
            ans = max(ans, i - st.top());
            st.pop();
        }
    }
    print(ans);

    return 0;
}

