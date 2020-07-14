#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int HEIGHT = 20;
const int INF = 0x3f3f3f3f;

struct Node {
    llint vr1, vr2;

    void make_reverse() {
        swap(vr1, vr2);
    }
};

class Solution {
public:
    Solution(const int level_, vector<int>& ns) {
        level = level_;
        n = ns.size();
        segs.resize(level_ + 1);
        build(level, 0, n, ns);
    }

    llint query(int m) {
        llint res = 0;
        // print("--");
        for (int i = 0; i <= level; i++) {
            if (i <= m) {
                segs[i].make_reverse();
            }
            // print(i << ' ' << segs[i].vr1 << ' ' << segs[i].vr2);
            res += segs[i].vr1;
        }
        // print("--");
        return res;
    }
private:
    void build(int level, int l, int r, vector<int>& ns) {
        assert(r - l == (1 << level));
        if (level == 0) {
            assert(segs[level].vr1 == 0 && segs[level].vr2 == 0);
            return;
        }
        int mid = (l + r) / 2;
        auto& cur = segs[level];
        
        build(level - 1, l, mid, ns);
        build(level - 1, mid, r, ns);

        int lsize = mid - l;
        int rsize = r - mid;
        cur.vr1 += rev_cnt(ns.data() + l, lsize, ns.data() + mid, rsize);
        cur.vr2 += rev_cnt(ns.data() + mid, rsize, ns.data() + l, lsize);

        vector<int> buffer(r - l);

        int ptr = 0;
        for (int ll = 0, rr = 0; ll < lsize || rr < rsize; /* pass */) {
            int vl = ll < lsize? ns[l + ll]: INF;
            int vr = rr < rsize? ns[mid + rr]: INF;
            if (vl <= vr) {
                buffer[ptr] = ns[l + ll];
                ll++;
            } else {
                buffer[ptr] = ns[mid + rr];
                rr++;
            }

            ptr++;
        }

        for (int i = 0; i < r - l; i++) {
            ns[l + i] = buffer[i];
        }

        /*
        for (auto num: buffer) {
            printf("%d ", num);
        }
        puts("");
        printf(">> %lld %lld\n", cur.vr1, cur.vr2);
        */
    }

    llint rev_cnt(int* l, int lsize, int* r, int rsize) {
        llint res = 0;

        int lp = 0;
        int rp = 0;
        while (lp < lsize || rp < rsize) {
            assert(lp >= 0 && lp <= lsize);
            assert(rp >= 0 && rp <= rsize);
            int vl = lp < lsize? l[lp]: INF;
            int vr = rp < rsize? r[rp]: INF;
            if (vl <= vr) {
                // res += rp;
                lp++;
            } else {
                res += lsize - lp;
                rp++;
            }
        }
        return res;
    }
private:
    int n;
    int level;
    vector<Node> segs;
};

void test() {
    {
        vector<int> ns = {2, 1, 4, 3};
        auto S = Solution(2, ns);
        assert(S.query(1) == 0);
        assert(S.query(2) == 6);
        assert(S.query(0) == 6);
        assert(S.query(2) == 0);
    }
    {
        vector<int> ns = {1, 1, 3, 1};
        auto S = Solution(2, ns);
        assert(S.query(0) == 1);
        assert(S.query(1) == 0);
        assert(S.query(2) == 3);
    }
    {
        vector<int> ns = {1, 1, 1, 1};
        auto S = Solution(2, ns);
        assert(S.query(0) == 0);
        assert(S.query(1) == 0);
        assert(S.query(2) == 0);
    }
    {
        vector<int> ns = {1, 2};
        auto S = Solution(1, ns);
        assert(S.query(0) == 0);
        assert(S.query(1) == 1);
        assert(S.query(1) == 0);
    }
    {
        srand(0);
        vector<int> ns(1 << 18);
        for (int i = 0; i < (1 << 18); i++) {
            ns[i] = rand() % 1'000'000'000;
        }
        auto S = Solution(18, ns);
        for (int i = 0; i < 123456; i++) {
            S.query(rand() % 18);
        }
    }
    print("OK");
}

int main() {
    // test();

    int n;
    input(n);

    vector<int> ns(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        scanf("%d", &ns[i]);
    }

    Solution S(n, ns);

    int q;
    input(q);

    int m;
    while (q--) {
        scanf("%d", &m);
        printf("%s\n", to_string(S.query(m)).c_str());
    }

    return 0;
}
