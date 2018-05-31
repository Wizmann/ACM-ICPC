#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;

int n, k;
vector<int> ns;

llint check(llint sum, const multiset<int>& st1, const multiset<int>& st2, int k) {
    llint res = sum;
    k = min(k, (int)min(st1.size(), st2.size()));

    auto iter = st1.begin();
    auto jter = st2.rbegin();

    for (int i = 0; i < k; i++) {
        sum -= *iter;
        sum += *jter;

        iter++;
        jter++;
        res = max(res, sum);
    }
    return res;
}

int main() {
    input(n >> k);
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    
    multiset<int> st1, st2;
    for (auto num: ns) {
        st2.insert(num);
    }

    llint sum = 0;
    llint res = -INF;
    for (int i = 0; i < n; i++) {
        sum += ns[i];
        st1.insert(ns[i]);
        st2.erase(st2.find(ns[i]));
        res = max(res, check(sum, st1, st2, k));
    }

    print(res);

    return 0;
}


