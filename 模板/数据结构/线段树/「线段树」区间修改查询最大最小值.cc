#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MAXI = numeric_limits<llint>::max();
const llint MINI = numeric_limits<llint>::min();

struct SegTree {
    struct SegTreeNode {
        llint maxi, mini;
        llint left, right;

        bool is_lazy_node() {
            if (left == right) {
                return false;
            }
            return maxi == mini;
        }

        bool equals(int l, int r) {
            return l == left && r == right;
        }
    };

    inline int LEFT(int x) { return 2 * x + 1; }
    inline int RIGHT(int x) { return 2 * x + 2; }
    static const int ROOT = 0;

    void init(int n) {
        _tree.clear();
        _tree.resize(n * 4);
        do_init(ROOT, 0, n);
    }

    void do_init(int pos, int l, int r) {
        _tree[pos] = {MINI, MAXI, l, r};
        if (l != r) {
            int mid = (l + r) >> 1;
            do_init(LEFT(pos), l, mid);
            do_init(RIGHT(pos), mid + 1, r);
        }
    }

    void update(int idx, llint value) {
        do_update(ROOT, idx, value);
    }

    void query(int l, int r, llint& maxi, llint& mini) {
        do_query(ROOT, l, r, maxi, mini);
    }

    void update_maxi(int l, int r, llint value) {
        do_update_maxi(ROOT, l, r, value);
    }

    void update_mini(int l, int r, llint value) {
        do_update_mini(ROOT, l, r, value);
    }

    void update_add(int l, int r, llint value) {
        do_update_add(ROOT, l, r, value);
    }

    void update_cur(int pos) {
        _tree[pos].maxi = max(
                _tree[LEFT(pos)].maxi,
                _tree[RIGHT(pos)].maxi);
        _tree[pos].mini = min(
                _tree[LEFT(pos)].mini,
                _tree[RIGHT(pos)].mini);
    }

    void down_cur(int pos) {
        _tree[LEFT(pos)].maxi = _tree[RIGHT(pos)].maxi = _tree[pos].maxi;
        _tree[LEFT(pos)].mini = _tree[RIGHT(pos)].mini = _tree[pos].mini;
    }

    void do_update(int pos, int idx, llint value) {
        if (_tree[pos].equals(idx, idx)) {
            _tree[pos].maxi = _tree[pos].mini = value;
            return;
        }
        if (_tree[pos].is_lazy_node()) {
            down_cur(pos);
        }
        int mid = (_tree[pos].left + _tree[pos].right) >> 1;
        if (idx <= mid) {
            do_update(LEFT(pos), idx, value);
        } else {
            do_update(RIGHT(pos), idx, value);
        }
        update_cur(pos);
    }

    void do_update_maxi(int pos, int l, int r, llint value) {
        if (_tree[pos].mini >= value) {
            return;
        }
        if (_tree[pos].equals(l, r) && l == r) {
            _tree[pos].maxi = _tree[pos].mini = max(_tree[pos].maxi, value);
            return;
        }
        if (_tree[pos].is_lazy_node()) {
            if (_tree[pos].equals(l, r) && _tree[pos].maxi <= value) {
                _tree[pos].maxi = _tree[pos].mini = value;
                return;
            }
            down_cur(pos);
        }
        int mid = (_tree[pos].left + _tree[pos].right) >> 1;
        if (r <= mid) {
            do_update_maxi(LEFT(pos), l, r, value);
        } else if (l > mid) {
            do_update_maxi(RIGHT(pos), l, r, value);
        } else {
            do_update_maxi(LEFT(pos), l, mid, value);
            do_update_maxi(RIGHT(pos), mid + 1, r, value);
        }
        update_cur(pos);
    }

    void do_update_mini(int pos, int l, int r, llint value) {
        if (_tree[pos].maxi <= value) {
            return;
        }
        if (_tree[pos].equals(l, r) && l == r) {
            _tree[pos].maxi = _tree[pos].mini = min(_tree[pos].mini, value);
            return;
        }
        if (_tree[pos].is_lazy_node()) {
            if (_tree[pos].equals(l, r) && _tree[pos].mini >= value) {
                _tree[pos].maxi = _tree[pos].mini = value;
                return;
            }
            down_cur(pos);
        }
        int mid = (_tree[pos].left + _tree[pos].right) >> 1;
        if (r <= mid) {
            do_update_mini(LEFT(pos), l, r, value);
        } else if (l > mid) {
            do_update_mini(RIGHT(pos), l, r, value);
        } else {
            do_update_mini(LEFT(pos), l, mid, value);
            do_update_mini(RIGHT(pos), mid + 1, r, value);
        }
        update_cur(pos);
    }

    void do_update_add(int pos, int l, int r, llint value) {
        if (_tree[pos].equals(l, r) && (_tree[pos].is_lazy_node() || l == r)) {
            _tree[pos].maxi = _tree[pos].mini = _tree[pos].maxi + value;
            return;
        }
        if (_tree[pos].is_lazy_node()) {
            down_cur(pos);
        }

        int mid = (_tree[pos].left + _tree[pos].right) >> 1;
        if (r <= mid) {
            do_update_add(LEFT(pos), l, r, value);
        } else if (l > mid) {
            do_update_add(RIGHT(pos), l, r, value);
        } else {
            do_update_add(LEFT(pos), l, mid, value);
            do_update_add(RIGHT(pos), mid + 1, r, value);
        }
        update_cur(pos);
    }

    void do_query(int pos, int l, int r, llint& maxi, llint &mini) {
        if (_tree[pos].equals(l, r) || _tree[pos].is_lazy_node()) {
            maxi = _tree[pos].maxi;
            mini = _tree[pos].mini;
            return;
        }
            
        int mid = (_tree[pos].left + _tree[pos].right) >> 1;
        if (r <= mid) {
            do_query(LEFT(pos), l, r, maxi, mini);
        } else if (l > mid) {
            do_query(RIGHT(pos), l, r, maxi, mini);
        } else {
            llint lmaxi = MINI;
            llint lmini = MAXI;
            llint rmaxi = MINI;
            llint rmini = MAXI;
            do_query(LEFT(pos), l, mid, lmaxi, lmini);
            do_query(RIGHT(pos), mid + 1, r, rmaxi, rmini);

            maxi = max(lmaxi, rmaxi);
            mini = min(lmini, rmini);
        }
    }

    vector<SegTreeNode> _tree;
};


int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int n, q;
    input(T);
    while (T--) {
        llint x;
        SegTree seg_tree;
        input(n >> q);
        seg_tree.init(n);
        for (int i = 0; i < n; i++) {
            input(x);
            seg_tree.update(i, x);
        }

        int l, r;
        llint c;
        for (int i = 0; i < q; i++) {
            input(x);
            switch (x) {
                case 1: {
                    input(l >> r >> c);
                    seg_tree.update_add(--l, --r, c);
                } break;
                case 2: {
                    input(l >> r >> c);
                    seg_tree.update_mini(--l, --r, c);
                } break;
                case 3: {
                    input(l >> r >> c);
                    seg_tree.update_maxi(--l, --r, c);
                } break;
                case 4: {
                    input(l >> r);
                    llint maxi = MINI;
                    llint mini = MAXI;
                    seg_tree.query(--l, --r, maxi, mini);
                    print(mini << " " << maxi);
                } break;
            }
        }
    }
    return 0;
}
