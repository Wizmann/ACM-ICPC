#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 212345;

int n;
vector<int> ns;

int main() {
    input(n);
    ns.resize(n);
    for (int i = 0; i< n; i++) {
        input(ns[i]);
    }
    sort(ns.begin(), ns.end());
    
    set<int> st;
    for (auto num: ns) {
        st.insert(num);
    }
    
    int ans = 0;
    int pre = -1;
    for (auto num: ns) {
        if (num == pre) {
            continue;
        }
        pre = num;
        int u = 2;
        while (num / u > ans) {
            int v = *st.upper_bound(num / u);
            ans = max(ans, num % v);
            u++;
        }
    }
    print(ans);
    return 0;
}
