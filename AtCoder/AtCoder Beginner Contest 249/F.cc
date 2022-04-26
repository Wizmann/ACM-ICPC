// using 2 std::set

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

struct Operation {
    int t, y;
};

multiset<int> st1;
multiset<int> st2;

llint v1, v2;

llint solve(int k) {
    while ((int)st1.size() > k) {
        int cur = *st1.rbegin();
        st1.erase(--st1.end());
        st2.insert(cur);
        v1 -= cur;
        v2 += cur;
    }

    while ((int)st1.size() < k && !st2.empty() && *st2.begin() < 0) {
        int cur = *st2.begin();
        st2.erase(st2.begin());
        st1.insert(cur);
        v2 -= cur;
        v1 += cur;
    }

    while (k && (int)st1.size() == k && !st2.empty()) {
        if (*st1.rbegin() > *st2.begin()) {
            int a = *st1.rbegin();
            int b = *st2.begin();

            st1.erase(--st1.end());
            st2.erase(st2.begin());

            st1.insert(b);
            st2.insert(a);

            v2 = v2 - b + a;
            v1 = v1 - a + b;
        } else {
            break;
        }
    }

    assert((int)st1.size() <= k);

    return v2;
}

int main() {
    int n, k;
    input(n, k);

    vector<Operation> ops(n + 1);

    ops[0] = {1, 0};

    int a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        ops[i] = {a, b};
    }

    v1 = v2 = 0;

    llint res = -INFLL;
    int rem = k;
    for (int i = n; i >= 0; i--) {
        const auto& op = ops[i];
        if (rem < 0) {
            break;
        }
        if (op.t == 1) {
            llint cur = solve(rem) + op.y;
            // print(i, cur);
            res = max(res, cur);
            rem--;
        } else {
            st2.insert(op.y);
            v2 += op.y;
        }
    }

    print(res);

    return 0;
}

/*

^^^TEST^^^
5 1
2 4
2 -3
1 2
2 1
2 -3
-----
3
$$$TEST$$$

^^^TEST^^^
1 0
2 -1000000000
-----
-1000000000
$$$TEST$$$

^^^TEST^^^
10 3
2 3
2 -1
1 4
2 -1
2 5
2 -9
2 2
1 -6
2 5
2 -3
-----
15
$$$TEST$$$

*/

// -------------
// using SBT

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

template <typename T>
class SizeBalancedTree {
public:
    struct TreeNode {
        T key;

        uint32_t size;
        T sum;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(const T& key_) : key(key_), size(0), sum(key_) {
            // pass
        }
    };
public:
    SizeBalancedTree(): _root(nullptr), _size(0) {}
    ~SizeBalancedTree() {
        destroy(_root);
    }
public:
    int insert(const T& key) {
        _size++;
        _root = do_insert(_root, key);
        return 0;
    }

    int remove(const T& key) {
        _size--;
        _root = do_remove(_root, key);
        return 0;
    }
    
    TreeNode* find(const T& key)    { return do_find(_root, key);              }
    TreeNode* get_rank(int rank, T& prefix_sum) {
        return do_get_rank(_root, rank, prefix_sum);
    }
    int size()                      { return _size;                            }
    int count_lt(const T& key)      { return do_count_lt(_root, key);          }
private:
    int get_node_size(TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }
        return cur->size + 1;
    }

    T get_node_sum(TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }
        return cur->sum;
    }

    void destroy(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        destroy(cur->left);
        destroy(cur->right);
        delete cur;
    }
    
    int do_count_lt(TreeNode* cur, const T& key) {
        if (cur == nullptr) {
            return 0;
        }
        if (key < cur->key) {
            return do_count_lt(cur->left, key);
        } else if (key == cur->key) {
            return get_node_size(cur->left);
        } else {
            return get_node_size(cur->left) + 1 + do_count_lt(cur->right, key);
        }
    }
    
    TreeNode* maintain(TreeNode* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (cur->left) {
            if (get_node_size(cur->right) < get_node_size(cur->left->left)) {
                cur = rotateToRight(cur);
                cur->right = maintain(cur->right);
                cur = maintain(cur);
            } else if (get_node_size(cur->right) < get_node_size(cur->left->right)) {
                cur->left = rotateToLeft(cur->left);
                cur = rotateToRight(cur);
                cur->left = maintain(cur->left);
                cur->right = maintain(cur->right);
                cur = maintain(cur);
            }
        }
        if (cur->right) {
            if (get_node_size(cur->left) < get_node_size(cur->right->right)) {
                cur = rotateToLeft(cur);
                cur->left = maintain(cur->left);
                cur = maintain(cur);
            } else if (get_node_size(cur->left) < get_node_size(cur->right->left)) {
                cur->right = rotateToRight(cur->right);
                cur = rotateToLeft(cur);
                cur->left = maintain(cur->left);
                cur->right = maintain(cur->right);
                cur = maintain(cur);
            }
        }
        return cur;
    }

    TreeNode* rotateToLeft(TreeNode* cur) {
        assert(get_node_sum(cur) == get_node_sum(cur->left) + get_node_sum(cur->right) + cur->key);
        
        TreeNode* k1 = cur->right;
        cur->right = k1->left;
        k1->left = cur;

        cur->size = get_node_size(cur->left) + get_node_size(cur->right);
        cur->sum = get_node_sum(cur->left) + get_node_sum(cur->right) + cur->key;

        k1->size = get_node_size(k1->left) + get_node_size(k1->right);
        k1->sum = get_node_sum(k1->left) + get_node_sum(k1->right) + k1->key;

        assert(get_node_sum(k1) == get_node_sum(k1->left) + get_node_sum(k1->right) + k1->key);

        return k1;
    }

    TreeNode* rotateToRight(TreeNode* cur) {
        assert(get_node_sum(cur) == get_node_sum(cur->left) + get_node_sum(cur->right) + cur->key);

        TreeNode* k1 = cur->left;
        cur->left = k1->right;
        k1->right = cur;

        cur->size = get_node_size(cur->left) + get_node_size(cur->right);
        cur->sum = get_node_sum(cur->left) + get_node_sum(cur->right) + cur->key;

        k1->size = get_node_size(k1->left) + get_node_size(k1->right);
        k1->sum = get_node_sum(k1->left) + get_node_sum(k1->right) + k1->key;

        assert(get_node_sum(k1) == get_node_sum(k1->left) + get_node_sum(k1->right) + k1->key);

        return k1;
    }
private:
    TreeNode* do_find(TreeNode* cur, const T& key) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (key == cur->key) {
            return cur;
        }
        if (key < cur->key) {
            return do_find(cur->left, key);
        } else {
            return do_find(cur->right, key);
        }
    }

    TreeNode* do_get_rank(TreeNode* cur, int r, T& prefix_sum) {
        assert(r >= 0);
        prefix_sum = 0;
        if (cur == nullptr || r < 0 || r >= size()) {
            return nullptr;
        }
        assert(get_node_sum(cur) == get_node_sum(cur->left) + get_node_sum(cur->right) + cur->key);
        if (get_node_size(cur->left) == r) {
            prefix_sum = get_node_sum(cur->left) + cur->key;
            return cur;
        } else if (get_node_size(cur->left) < r) {
            prefix_sum = get_node_sum(cur->left) + cur->key;
            T s1 = 0;
            auto* p = do_get_rank(cur->right, r - get_node_size(cur->left) - 1, s1);
            prefix_sum += s1;
            return p;
        } else {
            return do_get_rank(cur->left, r, prefix_sum);
        }
    }
    
    TreeNode* do_remove(TreeNode* cur, const T& key) {
        if (cur == nullptr) {
            return nullptr;
        }
        --cur->size;
        cur->sum -= key;
        if (cur->key == key) {
            return remove_cur(cur);
        } else if (cur->key > key) {
            cur->left = do_remove(cur->left, key);
        } else {
            cur->right = do_remove(cur->right, key);
        }
        cur = maintain(cur);
        return cur;
    }

    TreeNode* remove_cur(TreeNode* cur) {
        if (cur == nullptr || (cur->left == nullptr && cur->right == nullptr)) {
            delete cur;
            return nullptr;
        }
        if (cur->left == nullptr) {
            auto res = cur->right;
            delete cur;
            return res;
        }
        if (cur->right == nullptr) {
            auto res = cur->left;
            delete cur;
            return res;
        }
        TreeNode* mini = get_mini(cur->right);
        cur->key = mini->key;
        cur->value = mini->value;

        cur->right = do_remove(cur->right, mini->key);
        return cur;
    }

    TreeNode* get_mini(TreeNode* cur) {
        while (cur->left) {
            cur = cur->left;
        }
        return cur;
    }

    TreeNode* do_insert(TreeNode* cur, const T& key) {
        if (cur == nullptr) {
            cur = new TreeNode(key);
            return cur;
        }
        ++cur->size;
        cur->sum += key;
        if (key < cur->key) {
            cur->left = do_insert(cur->left, key);
        } else {
            cur->right = do_insert(cur->right, key);
        }
        assert(get_node_sum(cur) == get_node_sum(cur->left) + get_node_sum(cur->right) + cur->key);
        cur = maintain(cur);
        return cur;
    }

private:
    TreeNode* _root;
    uint32_t _size;
};

struct Operation {
    int t, y;
};

vector<Operation> ops;

int main() {
    int n, k;
    input(n, k);

    ops.resize(n + 1);

    ops[0] = {1, 0};

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &ops[i].t, &ops[i].y);
    }

    SizeBalancedTree<llint> sbt;

    int rem = k;
    llint tot = 0;
    int neg = 0;
    llint res = -INFLL;
    for (int i = n; i >= 0; i--) {
        const auto& op = ops[i];

        if (rem < 0) {
            break;
        }

        if (op.t == 1) {
            llint u = op.y;
            int r = rem - 1;
            if (neg < rem) {
                r = neg - 1;
            }

            r = min(r, sbt.size() - 1);

            if (r >= 0) {
                llint v = 0;
                sbt.get_rank(r, v);
                u += tot - v;

            } else {
                u += tot;
            }

            res = max(res, u);
            // print(i, u, r, rem);

            rem--;
        } else {
            assert(op.t == 2);
            sbt.insert(op.y);
            tot += op.y;
            if (op.y < 0) {
                neg++;
            }
        }

        /*
        int size = sbt.size();
        llint prefix = 0;
        for (int j = 0; j < size; j++) {
            llint u = 0;
            llint key = sbt.get_rank(j, u)->key;
            print(key, prefix, u);
            fflush(stdout);
            assert(prefix + key == u);
            prefix += key;
        }
        puts("--");
        */

    }
    print(res);

    return 0;
}

/*
^^^^^TEST^^^^^
10 3
2 3
2 -1
1 4
2 -1
2 5
2 -9
2 2
1 -6
2 5
2 -3
---------------
15
$$$$TEST$$$

^^^^^TEST^^^^
10 2
1 84
1 -100
2 6
1 65
2 91
2 8
1 -60
2 32
1 87
2 -13
------
183
$$$TEST$$$

^^^^TEST^^^^
10 2
2 39
2 -26
2 -94
2 -79
1 -61
1 72
1 60
1 -9
2 44
1 -75
--------
104
$$$TEST$$$

^^^^^TEST^^^^
10 2
1 -75
2 -44
2 32
1 53
1 -49
2 -50
2 -17
1 75
1 -81
2 44
-------
119
$$$TEST$$$


 */

