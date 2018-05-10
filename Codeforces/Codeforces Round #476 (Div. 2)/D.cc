#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int n, l;
vector<int> frogs;
map<int, int> stones;

int main() {
    freopen("d.txt", "r", stdin);

    input(n >> l);
    frogs.resize(n + 1);

    frogs[0] = INF;
    
    int a;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a) {
            stones[i] = a;
        }
    }
    stones[n] = INF;

    for (int i = 0; i < n; i++) {
        for (auto iter = stones.begin(); 
                iter != stones.end(); 
                /* pass */) {
            if (iter->first <= i) {
                iter = stones.erase(iter);
            } else if (iter->first > i + l) {
                break;
            } else {
                int u = min(frogs[i], iter->second);
                frogs[i] -= u;
                frogs[iter->first] += u;
                iter->second -= u;

                if (iter->second == 0) {
                    iter = stones.erase(iter);
                } else {
                    ++iter;
                }
            }
        }
    }

    print(frogs[n]);

    return 0;
}
