#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 55555;

struct Work {
    int e, w;
};

int main() {
    int n;
    int a, b;
    input(n);
    
    priority_queue<Work, 
            vector<Work>,
            function<bool(const Work&, const Work&)>> pq(
        [](const Work& w1, const Work& w2) {
            return w1.w < w2.w;
        }
    );
    vector<Work> works;
    
    int tt = 0;
    
    for (int i = 0; i < n; i++) {
        input(a >> b);
        works.push_back({a, b});
        tt = max(tt, a);
    }
    
    sort(works.begin(), works.end(), [](const Work& w1, const Work& w2) {
        return w1.e > w2.e;
    });
    
    llint ans = 0;
    
    int ptr = 0;
    while (tt) {
        while (ptr < n && works[ptr].e >= tt) {
            pq.push(works[ptr]);
            ptr++;
        }
        if (!pq.empty()) {
            ans += pq.top().w;
            pq.pop();
        }
        tt--;
    }
    
    print(ans);
    return 0;
}
