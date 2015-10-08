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

typedef long long llint;

vector<int> A, B;
llint n, k;

llint do_count(llint c) {
    llint cnt = 0;
    for (auto a: A) {
        int l = 0;
        int r = n - 1;
        
        while (l <= r) {
            int m = (l + r) >> 1;
            if (1LL * B[m] * a > c) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cnt += l;
    }
    return cnt;
}
                

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n >> k);
    for (int i = 0; i < n; i++) {
        input(a >> b);
        A.push_back(a);
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    llint l = 0;
    llint r = 1000000000000000000LL;
    
    while (l <= r) {
        llint m = (l + r) >> 1;
        llint cnt = do_count(m);
        if (cnt + k > n * n) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    print(l);
    return 0;
}
