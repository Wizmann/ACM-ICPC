#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<pair<int, int> > vec;

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n);
    for (int i = 0; i < n; i++) {
        input(a >> b);
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>& pa, const pair<int, int>& pb) {
        return pa.first + max(pa.second, pb.first) + pb.second <
               pb.first + max(pb.second, pa.first) + pa.second;
    });
    
    queue<int> q;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tm = vec[i].first;
        ans += tm;
        while (tm && !q.empty()) {
            if (tm < q.front()) {
                q.front() -= tm;
                tm = 0;
            } else if (tm == q.front()) {
                q.pop();
                tm = 0;
            } else {
                tm -= q.front();
                q.pop();
            }
        }
        q.push(vec[i].second);
    }
    while (!q.empty()) {
        ans += q.front();
        q.pop();
    }
    print(ans);
    return 0;
}
