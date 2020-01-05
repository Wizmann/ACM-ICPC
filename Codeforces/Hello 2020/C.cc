#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
vector<llint> fs;
 
llint solve(llint n, llint mod) {
    fs = vector<llint>(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fs[i] = fs[i - 1] * i % mod;
    }
 
    llint res = 0;
    for (int i = n; i >= 1; i--) {
        llint cur = (n - i + 1);
        cur = (cur * cur) % mod;
        cur = (cur * fs[i]) % mod;
        cur = (cur * fs[n - i]) % mod;
        // print(cur);
        res = (res + cur) % mod;
    }
    // print(res);
    return res;
}
 
int main() {
    assert(solve(2, 100000) == 6);
    assert(solve(1, 100000) == 1);
    assert(solve(3, 100000) == 32);
 
    llint a, b;
    input(a >> b);
    print(solve(a, b));
    return 0;
}
