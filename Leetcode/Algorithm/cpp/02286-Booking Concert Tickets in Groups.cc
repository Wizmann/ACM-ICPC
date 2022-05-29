#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

int lowbit(int x) { return x & (-x); }

template <typename T, class Compare=less<int> >
class BITreeRMQ {
public:
    BITreeRMQ() {}
    BITreeRMQ(int n_, const vector<T>& nums_) : n(n_), nums(nums_), tree(nums_) {
        assert((int)nums.size() == n);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }

    T query(int a, int b) {
        T ans = nums[b];
        while (a != b) {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b)) {
                ans = cmp(ans, tree[b]);
            }
            ans = cmp(ans, nums[b]);
        }
        return ans;
    }

    void modify(int pos, T val) {
        nums[pos] = val;
        for (int i = pos; i < n; i += lowbit(i)) {
            tree[i] = nums[i];
            for (int j = 1; j < lowbit(i); j <<= 1) {
                tree[i] = cmp(tree[i], tree[i - j]);
            }
        }
    }
private:
    T cmp(T a, T b) {
        return cmp_func(a, b)? a: b;
    }

    inline int lowbit(int x) {
        return x&(-x);
    }

    Compare cmp_func = Compare();
    int n;
    vector<T> nums;
    vector<T> tree;
};

template <typename T>
class BIT
{
public:
    BIT() {}
    BIT(int n_) : n(n_), nums(n + 1) {}

    void add(int x, T val) {
        while(x < n) {
            nums[x] += val;
            x += lowbit(x);
        }
    }

    T sum(int x) {
        T res = 0;
        while(x > 0) {
            res += nums[x];
            x -= lowbit(x);
        }
        return res;
    }

    T sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
private:
    int n;
    vector<T> nums;
};

class BookMyShow {
public:
    BookMyShow(int n_, int m_) {
        n = n_;
        m = m_;
        seats = vector<int>(n + 1, 0);
        rmq = BITreeRMQ<int>(n + 1, seats);
        bit = BIT<llint>(n + 1);
        p = 0;
        rem = 1LL * n * m;
    }
    
    vector<int> gather(int k, int maxRow) {
        int l = 0;
        int r = maxRow;

        while (l <= r) {
            int mid = (l + r) / 2;
            int mini = rmq.query(1, mid + 1);
            if (m - mini >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (l == -1 || l > maxRow) {
            return vector<int>();
        }

        int base = seats[l];
        seats[l] += k;
        rmq.modify(l + 1, seats[l]);
        bit.add(l + 1, k);

        rem -= k;

        while (p < n && seats[p] == m) {
            p++;
        }

        return {l, base};
    }
    
    bool scatter(int k, int maxRow) {
        if (k > rem) {
            return false;
        }
        if (1LL * m * (maxRow + 1) - bit.sum(1, maxRow + 1) < k) {
            return false;
        }
        vector<pair<int, int> > ps;
        for (int i = p; i <= maxRow && k; i++) {
            int rem = m - seats[i];
            int delta = min(k, rem);
            k -= delta;
            ps.push_back({i, delta});
        }

        if (k) {
            return false;
        }

        for (const auto& pa : ps) {
            int idx = pa.first;
            int cnt = pa.second;

            seats[idx] += cnt;
            bit.add(idx + 1, cnt);
            rmq.modify(idx + 1, seats[idx]);
            rem -= cnt;
        }

        while (p < n && seats[p] == m) {
            p++;
        }

        return true;
    }
private:
    int n;
    int m;
    int p;
    llint rem;
    vector<int> seats;
    BITreeRMQ<int> rmq;
    BIT<llint> bit;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

