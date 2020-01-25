#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
const int SIZE = 123456;
 
vector<bool> isPrime;
vector<int> miu;
vector<int> prime;
vector<int> g[SIZE];
 
void init() {
    isPrime = vector<bool>(SIZE, true);
    miu = vector<int>(SIZE, 0);
 
    miu[1] = 1;
 
    for (int i = 2; i < SIZE; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
            miu[i] = -1;
        }
 
        for (int j = 0; j < prime.size() && i * prime[j] < SIZE; j++) {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            } else {
                miu[i * prime[j]] = -miu[i];
            }
        }
    }
    for (int i = 1; i < SIZE; i++) {
        for (int j = i; j < SIZE; j += i) {
            g[j].push_back(i);
        }
    }
}
 
vector<bool> ps(SIZE, false);
vector<int> sum(SIZE, 0);
 
int query(int x) {
    int res = 0;
    for (auto f : g[x]) {
        res += miu[f] * sum[f];
    }
    return res;
}
 
void add(int x, int val) {
    for (auto f : g[x]) {
        sum[f] += val;
    }
}
 
int main() {
    init();
 
    int n;
    input(n);
    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
        ps[ns[i]] = true;
    }
    llint ans = 0;
    for (int i = 1; i < SIZE; i++) {
        vector<int> st;
        for (int j = (SIZE - 1) / i; j >= 1; j--) {
            if (ps[i * j] == false) {
                continue;
            }
            while (query(j)) {
                ans = max(ans, 1LL * i * j * st.back());
                add(st.back(), -1);
                st.pop_back();
            }
            add(j, 1);
            st.push_back(j);
        }
        while (!st.empty()) {
            add(st.back(), -1);
            st.pop_back();
        }
    }
    sort(ns.begin(), ns.end());
    for (int i = 0; i < n - 1; i++) {
        if (ns[i] == ns[i + 1]) {
            ans = max(ans, 1LL * ns[i]);
        }
    }
    print(ans);
    return 0;
}
