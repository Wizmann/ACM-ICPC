#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 212345;
const int INF = 0x3f3f3f3f;

struct node {
    int l, r;
};

vector<node> nodes;
vector<int> upper;

int main() {
    int n;
    int a, b;
    input(n);
    
    for (int i = 0; i < n; i++) {
        input(a >> b);
        nodes.push_back({a - b, a + b});
    }
    
    sort(nodes.begin(), nodes.end(), [](const node& na, const node& nb) -> bool {
        return na.r < nb.r;
    });
    
    int ans = 0;
    node last({-INF, -INF});
    for (auto& item: nodes) {
        if (item.l >= last.r) {
            ans++;
            last = item;
        }
    }
    print(ans);
    return 0;
}
