// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int solution(vector<int> &H) {
    stack<int> st;
    int ans = 0;
    H.push_back(-1);
    
    for (auto h: H) {
        while (!st.empty() && h < st.top()) {
            int cur = st.top();
            st.pop();
            int pre = st.empty()? 0: st.top();
            
            ans += (cur == pre)? 0: 1;
        }
        st.push(h);
    }
    return ans;
}
