#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<pair<int, int> > vec;

int main() {
    int T;
    int a, b;
    input(T);
    while (T--) {
        input(n);
        vec.clear();

        multiset<int> st;

        for (int i = 0; i < n; i++) {
            input(a >> b);
            vec.push_back({a, b});
        }
        sort(vec.begin(), vec.end(),
            [](const pair<int, int>& pa, const pair<int, int>& pb)->bool {
            if (pa.first != pb.first) {
                return pa.first < pb.first;
            } else {
                return pa.second > pb.second;
            }
        });

        for (auto& p: vec) {
            int u = p.second;
            if (st.empty()) {
                st.insert(u);
                continue;
            }

            auto iter = st.lower_bound(u);
            if (iter == st.begin()) {
                st.insert(u);
            } else {
                --iter;
                st.erase(iter);
                st.insert(u);
            }
        }
        print(st.size());
    }
    return 0;
}
