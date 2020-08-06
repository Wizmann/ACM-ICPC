#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int solve(const vector<int>& ns) {
    const int n = ns.size();
    set<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        st.insert({i, ns[i]});
    }
    vector<pair<int, int> > ps(n);
    for (int i = 0; i < n; i++) {
        ps[i] = {i, ns[i]};
    }
    sort(ps.begin(), ps.end(), [](const auto& p1, const auto& p2) {
        if (p1.second != p2.second) {
            return p1.second < p2.second;
        } 
        else {
            return p1.first < p2.first;
        }
    });

    int res = 0;
    for (auto p: ps) {
        auto iter1 = st.find(p);
        assert(iter1 != st.end());
        if (iter1 != st.begin()) {
            auto iter2 = iter1;
            iter2--;
            res = max(res, iter1->second ^ iter2->second);
        }
        if (iter1 != --st.end()) {
            auto iter2 = iter1;
            iter2++;
            res = max(res, iter1->second ^ iter2->second);
        }
        st.erase(iter1);
    }
    return res;
}

int main() {
    int n;
    input(n);
    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    print(solve(ns));

    return 0;
}
