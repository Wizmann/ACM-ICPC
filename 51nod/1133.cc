#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<pair<int, int> > lines;

int main() {
    int n;
    int a, b;
    input(n);
    
    for (int i = 0; i < n; i++) {
        input(a >> b);
        lines.push_back({a, b});
    }
    
    auto cmp = [](const pair<int, int>& pa, const pair<int, int>& pb) {
        return pa.first < pb.first;
    };
    
    sort(lines.begin(), lines.end(), cmp);
    int last = numeric_limits<int>::min();
    int cnt = 0;
    
    for (auto line: lines) {
        int sp = line.first;
        int ep = line.second;
        
        if (sp >= last) {
            cnt++;
            last = ep;
        } else {
            last = min(last ,ep);
        }
    }
    print(cnt);
    return 0;
}
