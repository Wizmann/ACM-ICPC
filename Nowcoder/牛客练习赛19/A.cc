#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
int n;
string s;
vector<int> mp;
llint ans;
 
pair<int, int> solve(const string& s, int l, int r, int color) {
    if (l + 1 == r) {
        ans += color;
        return {1, 1};
    }
 
    int a = l;
    int b = mp[l];
 
    int w = 0;
    int h = 0;
    if (b + 1 < r) {
        auto p = solve(s, b + 1, r, color);
        w += p.first + 1;
        h = max(h, p.second);
    }
 
    if (a + 1 == b) {
        ans += color;
        w += 1;
        h = max(h, 1);
    } else {
        auto p = solve(s, a + 1, b - 1, color * -1);
        int ww = p.first + 2;
        int hh = p.second + 1;
        ans += 1LL * ww * hh * color;
 
        w += ww;
        h = max(h, hh);
    }
 
    return {w, h};
 
}
 
int main() {
    int T;
    input(T);
    while (T--) {
        while (true) {
            input(s);
            if (s.size() != 0) {
                break;
            }
        }
 
        n = s.size();
        vector<int> st;
        mp = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push_back(i);
            } else {
                int cur = *st.rbegin();
                mp[cur] = i;
                st.pop_back();
            }
        }
 
        ans = 0;
        solve(s, 0, n, 1);
        print(ans);
    }
 
    return 0;
}