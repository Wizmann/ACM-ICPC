
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

template <typename T1, typename T2>
class SizeBalancedTree {
public:
    struct TreeNode {
        T1 key;
        T2 value;
        uint32_t size;
        TreeNode* left;
        TreeNode* right;

        TreeNode(const T1& i_key, const T2& i_value):
                key(i_key), value(i_value), size(0), left(nullptr), right(nullptr) {}
    };
public:
    SizeBalancedTree(): _root(nullptr), _size(0) {}
    ~SizeBalancedTree() {
        destroy(_root);
    }
public:
    int insert(const T1& key, const T2& value) { 
        _size++;
        _root = do_insert(_root, key, value);
        return 0;
    }

    int remove(const T1& key) {
        _size--;
        _root = do_remove(_root, key);
        return 0;
    }

    int find(const T1& key, T2& value)         { return do_find(_root, key, value); }
    TreeNode* get_rank(int r)                  { return do_get_rank(_root, r);      }
    int size()                                 { return _size;                      }
    TreeNode* find_max()                       { return get_maxi(_root);            }
    TreeNode* find_min()                       { return get_mini(_root);            }
private:
    uint32_t get_node_size(TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }
        return cur->size + 1;
    }
    
    void destroy(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        destroy(cur->left);
        destroy(cur->right);
        delete cur;
    }
    
    TreeNode* maintain(TreeNode* cur) {
        if (cur->left) {
            if (get_node_size(cur->right) < get_node_size(cur->left->left)) {
                cur = rotateToRight(cur);
            }
            if (get_node_size(cur->right) < get_node_size(cur->left->right)) {
                cur->left = rotateToLeft(cur->left);
                cur = rotateToRight(cur);
            }
        }
        if (cur->right) {
            if (get_node_size(cur->left) < get_node_size(cur->right->right)) {
                cur = rotateToLeft(cur);
            }
            if (get_node_size(cur->left) < get_node_size(cur->right->left)) {
                cur->right = rotateToRight(cur->right);
                cur = rotateToLeft(cur);
            }
        }
        return cur;
    }

    TreeNode* rotateToLeft(TreeNode* cur) {
        TreeNode* k1 = cur->right;
        cur->right = k1->left;
        k1->left = cur;
        cur->size = get_node_size(cur->left) + get_node_size(cur->right);
        k1->size = get_node_size(k1->left) + get_node_size(k1->right);
        return k1;
    }

    TreeNode* rotateToRight(TreeNode* cur) {
        TreeNode* k1 = cur->left;
        cur->left = k1->right;
        k1->right = cur;
        cur->size = get_node_size(cur->left) + get_node_size(cur->right);
        k1->size = get_node_size(k1->left) + get_node_size(k1->right);
        return k1;
    }
private:
    int do_find(TreeNode* cur, const T1& key, T2& value) {
        if (cur == nullptr) {
            return 0;
        }
        if (key == cur->key) {
            value = cur->value;
            return 1;
        }
        if (key < cur->key) {
            return do_find(cur->left, key, value);
        } else {
            return do_find(cur->right, key, value);
        }
    }

    TreeNode* do_get_rank(TreeNode* cur, int r) {
        if (cur == nullptr || r < 0 || r >= size()) {
            return nullptr;
        }
        if (get_node_size(cur->left) == r) {
            return cur;
        } else if (get_node_size(cur->left) < r) {
            return do_get_rank(cur->right, r - get_node_size(cur->left) - 1);
        } else {
            return do_get_rank(cur->left, r);
        }
    }
    
    TreeNode* do_remove(TreeNode* cur, const T1& key) {
        if (cur == nullptr) {
            return nullptr;
        }
        --cur->size;
        if (cur->key == key) {
            return remove_cur(cur);
        } else if (cur->key > key) {
            cur->left = do_remove(cur->left, key);
        } else {
            cur->right = do_remove(cur->right, key);
        }
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
    
    TreeNode* get_maxi(TreeNode* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        while (cur->right) {
            cur = cur->right;
        }
        return cur;
    }

    TreeNode* get_mini(TreeNode* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        while (cur->left) {
            cur = cur->left;
        }
        return cur;
    }

    TreeNode* do_insert(TreeNode* cur, const T1& key, const T2& value) {
        if (cur == nullptr) {
            cur = new TreeNode(key, value);
            return cur;
        }
        ++cur->size;
        if (key < cur->key) {
            cur->left = do_insert(cur->left, key, value);
        } else {
            cur->right = do_insert(cur->right, key, value);
        }
        cur = maintain(cur);
        return cur;
    }

private:
    TreeNode* _root;
    uint32_t _size;
};

int main() {
    freopen("input.txt", "r", stdin);
    SizeBalancedTree<int, int> sbt;
    
    int cmd;
    int key;
    int value;

    while (input(cmd) && cmd) {
        if (cmd == 1) {
            input(value >> key);
            sbt.insert(key, value);
        } else if (cmd == 2) {
            auto node = sbt.find_max();
            printf("%d\n", node == nullptr? 0: node->value);
            sbt.remove(node->key);
        } else {
            auto node = sbt.find_min();
            printf("%d\n", node == nullptr? 0: node->value);
            sbt.remove(node->key);
        }
    }
    return 0;
}
