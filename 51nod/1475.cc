#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct City {
    int h, p, idx;

    bool operator < (const City& city) const {
        return p < city.p;
    }
};


int n, h;
vector<City> cities;

int solve(int x) {
    priority_queue<City> pq;

    int ans = 0;
    int idx = 0;

    for (int i = x; i >= 1; i--) {
        while (idx < n && cities[idx].h + i <= h) {
            pq.push(cities[idx]);
            idx++;
        }
        if (pq.empty()) {
            continue;
        }
        
        for (int j = 0; j < 1 + (i == x) && !pq.empty(); j++) {
            ans += pq.top().p;
            pq.pop();
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n >> h);
    cities.reserve(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        cities.push_back({a, b, i});
    }
    sort(cities.begin(), cities.end(), [](const City& a, const City& b) {
            return a.h < b.h;
    });
    

    int r = n;
    int l = 1;
    while(r > l)
    {
        int lt=(l+r)/2;
        int rt=(lt+r)/2;
        int ltVal=solve(lt);//三分法求值函数
        int rtVal=solve(rt);
        if(ltVal>=rtVal) r=rt;//求最大值
        else l=lt;
    }
    print(max(solve(r + 1), solve(r)));
    return 0;
}
