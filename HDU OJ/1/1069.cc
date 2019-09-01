#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INF = 1e10;

struct Box {
    int x, y, z;
};

int main() {
    int n;
    int case_ = 0;
    while (input(n) && n) {
        vector<Box> boxs;

        int a, b, c;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            boxs.push_back({a, b, c});
            boxs.push_back({a, c, b});
            boxs.push_back({b, a, c});
            boxs.push_back({b, c, a});
            boxs.push_back({c, a, b});
            boxs.push_back({c, b, a});
        }

        map<pair<llint, llint>, int> dp;
        dp[{INF, INF}] = 0;

        queue<pair<llint, llint> > q;
        q.push({INF, INF});

        set<pair<llint, llint> > visited;
        visited.insert({INF, INF});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            auto v = dp[p];
            visited.erase(visited.find(p));

            llint py = p.first;
            llint px = p.second;

            for (const auto& box: boxs) {
                if (box.y < py && box.x < px) {
                    pair<llint, llint> key = {box.y, box.x};
                    int& u = dp[key];
                    u = max(u, v + box.z);
                    if (!visited.count(key)) {
                        q.push(key);
                        visited.insert(key);
                    }
                }
            }
        }

        llint maxi = -INF;
        for (const auto& p: dp) {
            // print(p.first.first << ' ' << p.first.second << ' ' << p.second);
            maxi = max(maxi, 1LL * p.second);
        }
        printf("Case %d: maximum height = %lld\n", ++case_, maxi);
    }
    return 0;
}
