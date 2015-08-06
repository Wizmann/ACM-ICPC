#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n;
    vector<pair<int, int> > intervals;
    
    input(n);
    intervals.resize(n);
    for (int i = 0; i < n; i++) {
        input(intervals[i].first >> intervals[i].second);
    }
    sort(intervals.begin(), intervals.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            }
    );
    
    size_t ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (auto interval: intervals) {
        int s = interval.first;
        int e = interval.second;
        
        while (!pq.empty() && pq.top() <= s) {
            pq.pop();
        }
        
        pq.push(e);
        ans = max(ans, pq.size());
    }
    print(ans);
    return 0;
}
