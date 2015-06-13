#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 51234;

struct Arrow {
    int damage, cost;
    
    bool operator > (const Arrow& arrow) const {
        return cost > arrow.cost;
    }
};

int n, m;

int main() {
    int a, b;
    input(n >> m);
    
    priority_queue<Arrow, vector<Arrow>, greater<Arrow> > pq;
    multiset<int> rabbit_st;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        rabbit_st.insert(a);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        pq.push({a, b});
    }
    
    llint ans = 0;
    
    while (!pq.empty() && !rabbit_st.empty()) {
        auto p = pq.top();
        pq.pop();
        
        auto iter = rabbit_st.upper_bound(p.damage);
        if (iter == rabbit_st.begin()) {
            continue;
        }
        --iter;
        ans += p.cost;
        rabbit_st.erase(iter);
    }
    
    if (!rabbit_st.empty()) {
        puts("No Solution");
    } else {
        print(ans);
    }
    return 0;
}
