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

typedef long long llint;

const llint INF = 1e12;

struct Toy {
    int e, r, idx;

    int sum() const {
        return e + r;
    }

    bool operator < (const Toy& other) const {
        if (sum() != other.sum()) {
            return sum() > other.sum();
        }
        return idx < other.idx;
    }
};

void solve(int n, vector<Toy>& toys, int& cut, llint& loop) {
    llint tot = 0;
    for (int i = 1; i <= n; i++) {
        const auto& toy = toys[i];
        tot += toy.e;
    }

    {
        llint ctot = tot;
        set<Toy> st;
        for (int i = 1; i <= n; i++) {
            const auto& toy = toys[i];
            st.insert(toy);
        }

        while (!st.empty() && st.begin()->sum() > ctot) {
            ctot -= st.begin()->e;
            st.erase(st.begin());
        }

        if (!st.empty()) {
            cut = n - st.size();
            loop = INF;
            return;
        }
    }

    {
        set<Toy> st;

        pair<llint, int> res = {tot, 0};
        cut = 0;
        llint pre = 0;
        for (int i = 1; i <= n; i++) {
            const auto& toy = toys[i];
            if (toy.sum() <= tot) {
                st.insert(toy);
                pre += toy.e;
                // res = max(res, {pre + tot, -cut});
            } else {
                cut++;
                tot -= toy.e;
            }
            while (!st.empty() && st.begin()->sum() > tot) {
                tot -= st.begin()->e;
                pre -= st.begin()->e;
                res = max(res, {pre + tot + st.begin()->e, -cut});
                st.erase(st.begin());
                cut++;
            }
        }

        cut = -res.second;
        loop = res.first;
    }
}

int main() {
    int T;
    input(T);
    
    for (int case_ = 0; case_ < T; case_++) {
        int n;
        input(n);

        vector<Toy> toys(n + 1);

        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &toys[i].e, &toys[i].r);
            toys[i].idx = i;
        }

        int cut = 0;
        llint loop = INF;

        solve(n, toys, cut, loop);
        printf("Case #%d: %d %s\n",
                case_ + 1,
                cut,
                loop >= INF? "INDEFINITELY": std::to_string(loop).c_str());
    }

    return 0;
}
