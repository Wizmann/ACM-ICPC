#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123;

int n, m;
vector<int> g[SIZE];
char visit[SIZE];
int pre[SIZE];

bool deal(int cur) {
    for (size_t i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];
        if (!visit[next]) {
            visit[next] = true;

            if (pre[next] == -1 || deal(pre[next])) {
                pre[next] = cur;
                return true;
            }

        }
    }
    return false;
}

int hungary() {
    int sum = 0;
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < n; i++) {
        memset(visit, false, sizeof(visit));
        if (deal(i)) {
            sum++;
        }
    }
    return sum;
}

int main() {
    input(n >> m);
    int a, b;
    while (input(a) && input(b) && a + b > 0) {
        a--;
        b--;
        g[a].push_back(b);
    }

    print(hungary());
    return 0;
}
