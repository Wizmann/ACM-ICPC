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

vector<int> primes;

void init() {
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);

    for (int i = 7; i <= 123; i += 2) {
        bool is_prime = true;
        for (auto prime: primes) {
            if (i % prime == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }
}

vector<int> get_factors(int x) {
    vector<int> res;
    for (auto prime: primes) {
        bool is_factor = false;
        is_factor = (x % prime == 0);
        while (x % prime == 0) {
            x /= prime;
        }
        if (is_factor) {
            res.push_back(prime);
        }
        if (x == 1) {
            break;
        }
    }
    if (x != 1) {
        res.push_back(x);
    }
    return res;
}

int solve(vector<int>& ns) {
    if (ns.size() == 1) {
        return 1;
    }
    map<int, int> mp;
    for (auto num: ns) {
        int maxi = 0;
        auto fs = get_factors(num);
        for (auto f: fs) {
            maxi = max(maxi, mp[f] + 1);
        }
        for (auto f: fs) {
            mp[f] = max(mp[f], maxi);
        }
    }
    int res = 0;
    for (auto kv: mp) {
        res = max(res, kv.second);
    }
    return res;
}

void test() {
    vector<int> t1 = {1, 2, 3, 4};
    assert(solve(t1) == 2);

    vector<int> t2 = {1, 2, 4, 3, 16, 8};
    assert(solve(t2) == 4);
}

int main() {
    init();
    test();

    int n;
    input(n);
    vector<int> ns(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    print(solve(ns));

    return 0;
}
