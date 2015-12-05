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

const int SIZE = 111;
const int MAX_SIZE = 10000;

int n;
vector<pair<int, int> > h[111];

struct Node {
    int a, b, c, d;

    bool operator > (const Node& node) const {
        double x = this->get_x();
        double y = node.get_x();
        
        if (x != y) {
            return x > y;
        }
        
        if (h[a][b].second != h[node.a][node.b].second) {
            return h[a][b].second > h[node.a][node.b].second;
        }
        
        return h[c][d].second > h[node.c][node.d].second;
    }
    
    double get_x() const {
        return 1.0 * (h[c][d].first - h[a][b].first) / (a - c);
    }
    
    bool add_one() {
        d++;
        return h[c].size() > d;
    }

};

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        h[b].push_back({a, i});
    }
    for (int i = 1; i < SIZE; i++) {
        sort(h[i].begin(), h[i].end());
    }
    
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    for (int i = 1; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            int L = h[i].size();
            int R = h[j].size();
            
            for (int l = 0, r = 0; l < L && r < R; /* pass */) {
                if (h[i][l].first <= h[j][r].first) {
                    l++;
                    continue;
                }
                pq.push({j, r, i, l});
                r++;
            }
        }
    }

    vector<pair<int, int> > res;
    for (int i = 0; i < MAX_SIZE && !pq.empty(); i++) {
        auto node = pq.top();
        pq.pop();
        
        res.push_back({h[node.a][node.b].second, h[node.c][node.d].second});
        if (node.add_one()) {
            pq.push(node);
        }
    }
    if (res.empty()) {
        puts("No Solution");
    }

    for (auto node: res) {
        printf("%d %d\n", node.first + 1, node.second + 1);
    }
    return 0;
}
