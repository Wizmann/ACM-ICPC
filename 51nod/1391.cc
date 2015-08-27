#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

vector<int> solve(const string& s, int a, int b) {
    int n = s.size();
    vector<int> sum(n, 0);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            sum[i] += sum[i - 1];
        }
        sum[i] += (s[i] - '0') == a? 1: -1;
    }
    mp[0] = -1;
    
    vector<int> res(n, -INF);
    for (int i = 0; i < n; i++) {
        auto iter = mp.lower_bound(sum[i]);
        if (iter != mp.begin()) {
            res[i] = i - (--iter)->second;
        }
        if (sum[i] < mp.begin()->first) {
            mp[sum[i]] = i;
        }
    }
    return res;
}

int main() {
    string s;
    while (input(s)) {
        int n = s.length();
        
        vector<int> a = solve(s, 0, 1);
        
        reverse(s.begin(), s.end());
        vector<int> b = solve(s, 1, 0);
        reverse(b.begin(), b.end());
        
        int ans = 0;
        
        /*
        for (auto i: a) {
            printf("%d ", i);
        }
        puts("");
        for (auto i: b) {
            printf("%d ", i);
        }
        puts("");
        */
        
        for (int i = 0; i + 1 < n; i++) {
            ans = max(ans, a[i] + b[i + 1]);
        }
        print(ans);
    }
    return 0;
}
