#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111111;

typedef long long llint;

struct Edge {
    int a, b;
    int length;

    bool operator< (const Edge& e) const {
        return length < e.length;
    }
};

int n, m;
int father[SIZE];
vector<Edge> edges;

void init_father() {
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }
}

int find_father(int x) {
    if (x == father[x]) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

int main() {
    int a, b, c;
    input(n >> m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c});
    }
    init_father();
    sort(edges.begin(), edges.end());

    int maxi = numeric_limits<int>::min();
    for (auto& edge: edges) {
        int aa = find_father(edge.a);
        int bb = find_father(edge.b);

        if (aa == bb) {
            continue;
        }
        maxi = edge.length;
        father[bb] = aa;
    }
    
    auto pivot = partition(edges.begin(), edges.end(), 
            [&](const Edge& edge) { return edge.length <= maxi; });
    reverse(edges.begin(), pivot);
    init_father();

    llint sum = 0;
    for (auto iter = edges.begin(); iter != pivot; ++iter) {
        int aa = find_father(iter->a);
        int bb = find_father(iter->b);

        if (aa == bb) {
            continue;
        }
        sum += iter->length;
        father[bb] = aa;
    }

    print(sum);
    return 0;
}
