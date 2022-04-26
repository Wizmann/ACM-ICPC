// Tested by: https://www.luogu.com.cn/problem/P3369

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
    
    TreeNode* find(const T& key) {
        return do_find(_root, key);
    }

    TreeNode* get_rank(int rank, T& prefix_sum) {
        return do_get_rank(_root, rank, prefix_sum);
    }

    int size() {
        return _size;
    }

    int count_lt(const T& key) {
        return do_count_lt(_root, key);
    }

    TreeNode* get_lt(const T& key) {
        return do_get_lt(_root, key);
    }

    TreeNode* lower_bound(T x) {
        return do_lower_bound(_root, x);
    }

    TreeNode* upper_bound(T x) {
        return do_upper_bound(_root, x);
    }

private:
    TreeNode* do_get_lt(TreeNode* cur, T x) {
        if (cur == nullptr) {
            return nullptr;
        }

        if (cur->key >= x) {
            return do_get_lt(cur->left, x);
        }

        TreeNode* res = do_get_lt(cur->right, x);
        if (res) {
            return res;
        }

        return cur;
    }

    TreeNode* do_lower_bound(TreeNode* cur, T x) {
        if (cur == nullptr) {
            return nullptr;
        }

        if (cur->key < x) {
            return do_lower_bound(cur->right, x);
        }

        TreeNode* res = do_lower_bound(cur->left, x);
        if (res) {
            return res;
        }

        return cur;
    }

    TreeNode* do_upper_bound(TreeNode* cur, T x) {
        if (cur == nullptr) {
            return nullptr;
        }

        if (cur->key <= x) {
            return do_upper_bound(cur->right, x);
        }

        TreeNode* res = do_upper_bound(cur->left, x);
        if (res) {
            return res;
        }

        return cur;
    }

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
        if (key <= cur->key) {
            return do_count_lt(cur->left, key);
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

int main() {
    int n;
    input(n);

    SizeBalancedTree<int> sbt;
    int op, x;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &op, &x);

        if (op == 1) {
            sbt.insert(x);
        } else if (op == 2) {
            sbt.remove(x);
        } else if (op == 3) {
            printf("%d\n", sbt.count_lt(x) + 1);
        } else if (op == 4) {
            int s;
            auto p = sbt.get_rank(x - 1, s);
            printf("%d\n", p->key);
        } else if (op == 5) {
            auto p = sbt.get_lt(x);
            printf("%d\n", p->key);
        } else if (op == 6) {
            auto p = sbt.upper_bound(x);
            printf("%d\n", p->key);
        } else {
            assert(false);
        }
    }

    return 0;
}

/*
^^^^^TEST^^^^^
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
--------
106465
84185
492737
$$$TEST$$$

^^^^TEST^^^^
10
1 -7
1 2
6 0
4 2
4 1
2 -7
3 2
4 1
4 1
3 2
-------------
2
2
-7
1
2
2
1
$$$TEST$$$

 */

