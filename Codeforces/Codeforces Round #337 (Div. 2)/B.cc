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

int n;
vector<int> colors;

int main() {
    int x;
    input(n);
    colors.reserve(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        colors.push_back(x);
    }
    
    int mini = *min_element(colors.begin(), colors.end());
    
    for (auto& color: colors) {
        color -= mini;
    }
    
    int max_cnt = 0;
    for (int i = 0; i < n; /* pass */) {
        if (colors[i] != 0) {
            i++;
            continue;
        }
        int p = 1;
        int cnt = 0;
        while (colors[(i + p) % n] != 0) {
            cnt++;
            p++;
        }
        max_cnt = max(max_cnt, cnt);
        i = i + p;
    }
    
    print(1LL * mini * n + max_cnt);
    return 0;
}
