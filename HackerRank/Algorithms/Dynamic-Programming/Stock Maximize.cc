#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int INF = 0x3f3f3f3f;

int n;
vector<int> stocks;

llint solve() {
    int maxi = -INF;
    llint cnt = 0;
    llint sum = 0;
    llint ans = 0;
    
    reverse(stocks.begin(), stocks.end());
    stocks.push_back(INF);
    
    for (auto stock: stocks) {
        if (stock > maxi) {
            ans += (maxi * cnt) - sum;
            cnt = 0;
            sum = 0;
            maxi = stock;
        } else {
            cnt++;
            sum += stock;
        }
    }
    return ans;
}

int main() {
    int T, a;
    input(T);
    while (T--) {
        input(n);
        for (int i = 0; i < n; i++) {
            input(a);
            stocks.push_back(a);
        }
        print(solve());
    }
    return 0;
}
