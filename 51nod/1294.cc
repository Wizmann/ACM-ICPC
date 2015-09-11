#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << endl

const int INF = 0x3f3f3f3f;

int LIS(const vector<int>& vec) {
    vector<int> st;
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        int u = vec[i];
        if (st.empty() || u >= *st.rbegin()) {
            st.push_back(u);
        } else {
            vector<int>::iterator iter = upper_bound(st.begin(), st.end(), u);
            *iter = u;
        }
    }
    return st.size();
}

int main() {
    int n, x;
    vector<int> vec;
    
    input(n);
    for (int i = 0; i < n; i++) {
        input(x);
        int u = x - i - 1;
        if (u < 0) {
            continue;
        }
        vec.push_back(u);
    }
    print(n - LIS(vec));
    return 0;
}
