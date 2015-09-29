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

const uint64_t MOD = 1000000007LL;
const int SIZE = 123456;
const uint64_t MAGIC_NUM = 19;

struct SegTree {
    struct Node {
        uint32_t hash_value;
        int value;
        int l, r;
    };

    inline int LEFT  (int x) { return x * 2 + 1;   }
    inline int RIGHT (int x) { return x * 2 + 2;   }
    inline int PARENT(int x) { return (x - 1) / 2; }

    uint64_t mod_plus(uint64_t a, uint64_t b) {
        return (a + b) % MOD;
    }
    
    uint64_t mod_pow_magic(uint64_t a) {
        return _pow[a];
    }

    uint64_t mod_mul(uint64_t a, uint64_t b) {
        return (a * b) % MOD;
    }

    void init(int l, int r, const vector<int>& values) {
        _tree.clear();
        init_pow();
        _tree.resize((r - l + 1) * 4 + 1999);
        do_init(0, l, r, values);
    }
    
    void init_pow() {
        uint64_t p = 1;
        _pow.reserve(SIZE);
        for (int i = 0; i < SIZE; i++) {
            _pow.push_back(p);
            p = (p * MAGIC_NUM) % MOD;
        }
    }

    void do_init(int ptr, int l, int r, const vector<int>& values) {
        _tree[ptr].l = l;
        _tree[ptr].r = r;
        _tree[ptr].value = -1;
        _tree[ptr].hash_value = -1;

        if (l == r) {
            _tree[ptr].value = values[l];
            _tree[ptr].hash_value = values[l];
        } else {
            int m = (l + r) >> 1;
            do_init(LEFT(ptr), l, m, values);
            do_init(RIGHT(ptr), m + 1, r, values);
            push_up(ptr);
        }
    }

    void push_up(int ptr) {
        int left = LEFT(ptr);
        int right = RIGHT(ptr);

        if (_tree[left].value == _tree[right].value) {
            _tree[ptr].value = _tree[left].value;
        }
        _tree[ptr].hash_value = calc_hash(_tree[left], _tree[right]);
    }

    uint64_t calc_hash(const Node& a, const Node& b) {
        int right_size = b.r - b.l + 1;
        uint64_t p = mod_mul(a.hash_value, mod_pow_magic(right_size));
        uint64_t q = mod_plus(p, b.hash_value);
        return q;
    }

    uint64_t calc_hash(const Node& a) {
        int size = a.r - a.l + 1;
        return do_calc(a.value, size);
    }

    uint64_t do_calc(uint64_t a, uint64_t b) {
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return a;
        }
        uint64_t x = do_calc(a, b / 2);
        if (b % 2 == 0) {
            return mod_plus(
                    x, mod_mul(x, mod_pow_magic(b / 2)));
        } else {
            uint64_t p =  mod_plus(
                    x, mod_mul(x, mod_pow_magic(b / 2 + 1)));
            uint64_t q = mod_mul(a, mod_pow_magic(b / 2));
            return mod_plus(p, q);
        }
    }

    void modify(int l, int r, int value) {
        do_modify(0, l, r, value);
    }

    void push_down(int ptr) {
        if (_tree[ptr].l == _tree[ptr].r) {
            return;
        }
        int left = LEFT(ptr);
        int right = RIGHT(ptr);
        
        _tree[left].value = _tree[right].value = _tree[ptr].value;
        _tree[left].hash_value = calc_hash(_tree[left]);
        _tree[right].hash_value = calc_hash(_tree[right]);
        
        _tree[ptr].value = -1;
    }

    void do_modify(int ptr, int l, int r, int value) {
        if (_tree[ptr].l == l && _tree[ptr].r == r) {
            _tree[ptr].value = value;
            _tree[ptr].hash_value = calc_hash(_tree[ptr]);
            return;
        }
        if (_tree[ptr].value != -1) {
            push_down(ptr);
        }
        int m = (_tree[ptr].l + _tree[ptr].r) >> 1;
        if (l > m) {
            do_modify(RIGHT(ptr), l, r, value);
        } else if (r <= m) {
            do_modify(LEFT(ptr), l, r, value);
        } else {
            do_modify(LEFT(ptr), l, m, value);
            do_modify(RIGHT(ptr), m + 1, r, value);
        }
        push_up(ptr);
    }

    uint64_t query_hash(int l, int r) {
        return do_query_hash(0, l, r);
    }

    uint64_t do_query_hash(int ptr, int l, int r) {
        if (_tree[ptr].l == l && _tree[ptr].r == r) {
            return _tree[ptr].hash_value;
        }
        
        if (_tree[ptr].value != -1) {
            return do_calc(_tree[ptr].value, r - l + 1);
        }
        
        int m = (_tree[ptr].l + _tree[ptr].r) / 2;

        if (r <= m) {
            return do_query_hash(LEFT(ptr), l, r);
        } else if (l > m) {
            return do_query_hash(RIGHT(ptr), l, r);
        } else {
            uint64_t p = do_query_hash(LEFT(ptr), l, m);
            uint64_t q = do_query_hash(RIGHT(ptr), m + 1, r);

            uint64_t t = mod_pow_magic(r - m);
            p = mod_mul(p, t);
            return mod_plus(p, q);
        }
    }

    vector<Node> _tree;
    vector<uint32_t> _pow;
};

SegTree S;
int n, m, k;

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> m >> k);

    vector<int> value;
    string instr;
    input(instr);
    for (auto c: instr) {
        value.push_back(c - '0');

    }
    S.init(0, n - 1, value);

    int q = m + k;
    int a, b, c, d;
    
    if (k == 0) {
        return 0;
    }

    while (q--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        b--;
        c--;
        if (a == 1) {
            S.modify(b, c, d);
        } else {
            if (d == c - b + 1) {
                puts("YES");
                continue;
            }
            uint64_t hash_left = S.query_hash(b, c - d);
            uint64_t hash_right = S.query_hash(b + d, c);
            //print(hash_left << " " << hash_right);
            puts(hash_left == hash_right? "YES": "NO");
        }
    }
    return 0;
}
    
