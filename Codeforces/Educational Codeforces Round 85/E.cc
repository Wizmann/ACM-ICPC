#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MAXI = 1234567890123456LL;
const llint SQRTMAXI = 32622776;
const llint MOD = 998244353LL;
const llint N = 111;

vector<bool> sieve;
vector<int> primes;
vector<int> factor;
unordered_map<llint, llint> mp;

void init(llint n) {
    sieve = vector<bool>(SQRTMAXI, false);
    for (llint i = 2; i < SQRTMAXI; i++) {
        if (sieve[i] == true) {
            continue;
        }
        for (llint j = 2; i * j < SQRTMAXI; j++) {
            sieve[i * j] = true;
        }
    }

    primes.push_back(2);
    for (int i = 3; i < SQRTMAXI; i += 2) {
        if (sieve[i] == false && n % i == 0) {
            primes.push_back(i);
        }
    }

    factor.push_back(1);
    for (int i = 1; i < N; i++) {
        factor.push_back(1LL * i * factor.back() % MOD);
    }
}

llint gcd(llint a, llint b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

llint mypow(llint a, llint b) {
    llint res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

llint divmod(llint a) {
    return mypow(a, MOD - 2) % MOD;
}

llint calcpath(llint u) {
    const llint key = u;
    if (mp.count(key)) {
        return mp[key];
    }

    llint tot = 0;
    llint div = 1;
    for (auto p : primes) {
        if (p > u) {
            break;
        }
        llint cnt = 0;
        while (u % p == 0) {
            tot++;
            cnt++;
            u /= p;
        }
        div = div * divmod(factor[cnt]) % MOD;
    }
    if (u > 1) {
        tot++;
    }

    llint res = factor[tot] * div % MOD;
    return mp[key] = res;
}

llint solve(llint D, llint a, llint b) {
    if (a > b) {
        swap(a, b);
    }
    llint g = gcd(a, b);

    llint pa = calcpath(a / g);
    llint pb = calcpath(b / g);

    // print(pa << ' ' << pb);

    return pa * pb % MOD;
}

void test() {
    init(12);
    assert(solve(12, 12, 1) == 3);
    assert(solve(12, 4, 4) == 1);
    assert(calcpath(12) == 3);

    mp.clear();
    init(288807105787200LL);
    assert(solve(288807105787200LL, 46LL, 482955026400LL) == 547558588LL);
    mp.clear();
}

template <class T>
inline void scan_d(T &ret) 
{
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main() {
    llint D;
    scan_d(D);

    init(D);

    int q;
    scan_d(q);
    while (q--) {
        llint a, b;
        scan_d(a);
        scan_d(b);
        puts(to_string(solve(D, a, b)).c_str());
    }

    return 0;
}
