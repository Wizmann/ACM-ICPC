#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int MAGIC = 47;

int n, k;
set<int> g[100];
vector<int> num;

int main() {
    freopen("input.txt", "r", stdin);

    input(n >> k);
    string s;
    input(s);
    num.resize(n);
    for (int i = 0; i < n; i++) {
        num[i] = s[i] - '0';
    }

    for (int i = 1; i < n; i++) {
        int u = num[i - 1] * 10 + num[i];
        g[u].insert(i - 1);
    }

    while (k) {
        if (g[MAGIC].empty()) {
            break;
        }
        int idx = *g[MAGIC].begin();

        if (idx % 2 == 1 && idx - 1 >= 0 && num[idx - 1] == 4) {
            k %= 2;
            num[idx] = k? 7: 4;
            break;
        }

        if (idx % 2 == 0 && idx + 2 < n && num[idx + 2] == 7) {
            k %= 2;
            num[idx + 1] = k? 4: 7;
            break;
        }

        if (idx - 1 >= 0) {
            int u = num[idx - 1] * 10 + num[idx];
            g[u].erase(g[u].find(idx - 1));
        }

        if (idx + 2 < n) {
            int u = num[idx + 1] * 10 + num[idx + 2];
            g[u].erase(g[u].find(idx + 1));
        }
        
        {
            g[MAGIC].erase(g[MAGIC].find(idx));
        }

        num[idx] = num[idx + 1] = idx % 2 == 1? 7: 4;

        if (idx - 1 >= 0) {
            int u = num[idx - 1] * 10 + num[idx];
            g[u].insert(idx - 1);
        }

        if (idx + 2 < n) {
            int u = num[idx + 1] * 10 + num[idx + 2];
            g[u].insert(idx + 1);
        }
        
        {
            int u = num[idx] * 10 + num[idx + 1];
            g[u].insert(idx);
        }
        
        k--;
        
        /*
        for (auto u: num) {
            printf("%d", u);
        }
        puts("");
        */
    }

    for (auto u: num) {
        printf("%d", u);
    }
    puts("");

    return 0;
}
