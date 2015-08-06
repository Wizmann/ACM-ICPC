#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1111;
const llint INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int a, b, c;
};

int n, m;
int father[SIZE];

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

void union_set(int a, int b) {
    father[find_father(a)] = find_father(b);
}

int main() {
    int a, b, c;
    while (input(n >> m)) {
        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
            input(a >> b >> c);
            edges.push_back({a, b, c});
        }
        for (int i = 0; i < SIZE; i++) {
            father[i] = i;
        }
        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
            return e1.c < e2.c;
        });
        
        llint ans = 0;
        for (auto& edge: edges) {
            int a = edge.a;
            int b = edge.b;
            int c = edge.c;
            
            if (find_father(a) == find_father(b)) {
                continue;
            }
            
            union_set(a, b);
            ans += c;
        }
        print(ans);
    }
    return 0;
}
