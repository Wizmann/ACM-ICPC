#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int N = 123;

int main() {
    int n, m;
    input(n >> m);
    vector<int> circles;
    
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        circles.push_back(a);
    }

    vector<int> ps(N, 0);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        ps[a] = max(ps[a], b);
    }
    
    sort(circles.begin(), circles.end());
    int p = 0;
    int q = 0;
    int maxi = 0;
    llint ans = 0;
    while (p < n) {
        int cur = circles[p];
        while (q < N && q < cur) {
            maxi = max(maxi, ps[q]);
            q++;
        }
        ans += maxi;
        p++;
    }
    print(ans);
    return 0;
}
