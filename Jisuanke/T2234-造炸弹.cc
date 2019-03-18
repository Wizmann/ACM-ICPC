#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 123456;

struct Node {
    llint sum;
    int idx, ptr;

    bool operator < (const Node& other) const {
        return sum < other.sum;
    }
};

int n, k;
vector<int> things[N];

int main() {
    input(n >> k);
    vector<int> g;
    llint sum = 0;
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        assert(c > 0);
        things[i].resize(c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &things[i][j]);
        }

        sort(things[i].begin(), things[i].end(), greater<int>());

        if (c > 1) {
            g.push_back(i);
        }
        sum += things[i][0];
    }

    if (k == 1) {
        print(sum);
        return 0;
    }

    sort(g.begin(), g.end(), [&](int a, int b) {
        int diff1 = things[a][0] - things[a][1];
        int diff2 = things[b][0] - things[b][1];
        return diff1 < diff2;
    });

    vector<int> order(n);
    for (int i = 0; i < g.size(); i++) {
        order[g[i]] = i;
    }

    priority_queue<Node> pq;
    pq.push({sum + things[g[0]][1] - things[g[0]][0], g[0], 1});

    for (int i = 2; i < k; i++) {
        auto cur = pq.top();
        pq.pop();

        sum = cur.sum;
        int idx = cur.idx;
        int ptr = cur.ptr;

        if (ptr + 1 < things[idx].size()) {
            pq.push({sum + things[idx][ptr + 1] - things[idx][ptr], idx, ptr + 1});
        }

        if (order[idx] + 1 < g.size()) {
            int next = g[order[idx] + 1];
            pq.push({sum + things[next][1] - things[next][0], next, 1});

            if (ptr == 1) {
                pq.push({sum + things[idx][0] - things[idx][1] + things[next][1] - things[next][0], next, 1});
            }
        }
    }

    print(pq.top().sum);

    return 0;
}
