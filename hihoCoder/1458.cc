#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    string s;
    input(s);
    
    stack<int> q;
    const int n = s.size();
    
    vector<pair<int, int> > ps;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            q.push(i + 1);
        } else {
            int pre = q.top();
            q.pop();
            ps.push_back({ pre, i + 1 });
        }
    }
    
    sort(ps.begin(), ps.end());
    for (auto p: ps) {
        print(p.first << ' ' << p.second);
    }
    
    return 0;
}
