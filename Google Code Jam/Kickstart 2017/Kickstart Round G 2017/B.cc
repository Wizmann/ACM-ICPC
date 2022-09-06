#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123;

struct Edge {
    int a, b, c;
};

int father[SIZE];
vector<Edge> edges;


int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}

void init(int n, const vector<int>& R, const vector<int>& B) {
    for (int i = 0; i < SIZE; i++) {
        father[i] = i;
    }

    edges.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edges.push_back({
                i,
                j,
                min(R[i] ^ B[j], B[i] ^ R[j])
            });
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
            return e1.c < e2.c;
    });
}

llint solve(int n, const vector<int>& R, const vector<int>& B) {
    init(n, R, B);

    llint sum = 0;
    for (const auto& e: edges) {
        if (find_father(e.a) != find_father(e.b)) {
            sum += e.c;
            father[find_father(e.a)] = find_father(e.b);
        }
    }
    return sum;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        printf("Case #%d: ", case_ + 1);

        int n;
        input(n);
        vector<int> R(n), B(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &R[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }

        print(solve(n, R, B));
    }
    return 0;
}
