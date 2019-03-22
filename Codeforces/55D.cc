#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int TOT_LCM = 2520;
const int MOD = 23456789;

unordered_map<llint, llint> mp;

llint get_hash_key(int len, int rem, int status) {
    assert(rem < TOT_LCM);
    return status * 1000000LL + rem * 100 + len;
}

int gcd(int a, int b) {
    if (a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0 || b == 1) {
        return a;
    }
    return 1LL * a * b / gcd(a, b);
}

int pplus(int rem, int u) {
    return (rem * 10 + u) % TOT_LCM;
}

llint dfs(const string& ns, int p, int rem, int status, bool lt) {
    llint key = get_hash_key(ns.size() - p, rem, status);

    if (lt && mp.count(key) != 0) {
        return mp[key];
    }

    if (p == ns.size()) {
        if (status == 0) {
            return 0;
        }
        return rem % status == 0? 1: 0;
    }

    llint res = 0;
    int cur = ns[p] - '0';
    for (int i = 9; i >= 0; i--) {
        if (lt == false && i <= cur) {
            int rr = pplus(rem, i);
            int ss = lcm(status, i);
            res += dfs(ns, p + 1, rr, ss, i < cur);
        }
        if (lt == true) {
            int rr = pplus(rem, i);
            int ss = lcm(status, i);
            res += dfs(ns, p + 1, rr, ss, true);
        }
    }

    if (lt) {
        return mp[key] = res;
    } else {
        return res;
    }
}

llint solve(llint x) {
    string xs = to_string(x);
    return dfs(xs, 0, 0, 0, false);
}

int main() {
    int T;
    input(T);
    while (T--) {
        llint a, b;
        input(a >> b);
        print(solve(b) - solve(a - 1));
    }
    return 0;
}
