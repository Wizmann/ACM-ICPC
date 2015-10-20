#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n;
    input(n);
    
    vector<int> nums(n + 1, numeric_limits<int>::min());
    stack<int> st;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    for (int i = 0; i <= n; i++) {
        int u = nums[i];
        while (!st.empty() && u < nums[st.top()]) {
            int v = nums[st.top()];
            st.pop();
            int l = st.empty()? 0: st.top() + 1;
            int r = i - 1;
            ans = max(ans, v * (r - l + 1));
        }
        st.push(i);
    }
    
    print(ans);
    return 0;
}
