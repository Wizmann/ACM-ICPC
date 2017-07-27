#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

template<typename node_t>
struct AVLNode {
    node_t node;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(const node_t &i_node):
        node(i_node), height(0), left(nullptr), right(nullptr) {}
};

template<typename node_t, typename cmp_t, typename maintain_t>
class AVLTree {
public:
    typedef AVLNode<node_t> AVLNode_t;

    AVLTree(): _root(nullptr), _size(0) {}
    size_t size() { return _size; }
    bool empty() { return _size == 0; }
    void destroy() {
        do_destroy(_root);
    }
    ~AVLTree() {
        destroy();
    }
    void print_tree() {
        do_print(_root);
    }
public:
    void do_print(AVLNode_t* cur) {
        if (cur == nullptr) {
            return;
        }
        printf("<%d %d>(%d %d) %d ", 
                (cur->node).value, (cur->node).count, 
                (cur->node).maxi_value, (cur->node).maxi_count,
                cur->height);
        if (cur->left) {
            printf("L:%d ", (cur->left->node).value);
        }
        if (cur->right) {
            printf("R:%d ", (cur->right->node).value);
        }
        puts("");
        do_print(cur->left);
        do_print(cur->right);
    }
    void insert(const node_t& node) {
        _size++;
        if (_root == nullptr) {
            _root = new AVLNode_t(node);
            return;
        }
        _root = do_insert(_root, node);
    }
    node_t* query(const node_t& node) {
        return do_query(_root, node);
    }
    void remove(const node_t& node) {
        _size--;
        _root = do_remove(_root, node);
    }
    node_t* get_root() {
        if (_root) {
            return &(_root->node);
        } else {
            return nullptr;
        }
    }
private:
    node_t* do_query(AVLNode_t* cur, const node_t& node) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (cmp(node, cur->node)) {
            return do_query(cur->left, node);
        }
        if (cmp(cur->node, node)) {
            return do_query(cur->right, node);
        }
        return &(cur->node);
    }

    AVLNode_t* do_insert(AVLNode_t* cur, const node_t& node) {
        if (cur == nullptr) {
            return new AVLNode_t(node);
        }

        if (cmp(node, cur->node)) {
            cur->left = do_insert(cur->left, node);
        } else if (cmp(cur->node, node)) {
            cur->right = do_insert(cur->right, node);
        } else {
            cur->node = node;
        }

        return maintain(cur);
    }

    AVLNode_t* do_remove(AVLNode_t* cur, const node_t& node) {
        if (cur == nullptr) {
            return nullptr;
        }

        if (cmp(node, cur->node)) {
            cur->left = do_remove(cur->left, node);
        } else if (cmp(cur->node, node)) {
            cur->right = do_remove(cur->right, node);
        } else {
            cur = do_remove_cur(cur);
        }
        
        if (cur == nullptr) {
            return nullptr;
        }
        
        return maintain(cur);
    }

    AVLNode_t* do_remove_cur(AVLNode_t* cur) {
        if (cur->left == nullptr && cur->right == nullptr) {
            delete cur;
            return nullptr;
        }
        if (cur->right == nullptr) {
            AVLNode_t* res = cur->left;
            delete cur;
            return res;
        }
        if (cur->left == nullptr) {
            AVLNode_t* res = cur->right;
            delete cur;
            return res;
        }
        auto t = find_min(cur->right);
        cur->node = t->node;
        cur->right = do_remove(cur->right, t->node);
        return maintain(cur);
    }
    
    AVLNode_t* find_min(AVLNode_t* cur) {
        while (cur->left) {
            cur = cur->left;
        }
        return cur;
    }

    int get_height(AVLNode_t* cur) {
        if (cur == nullptr) {
            return -1;
        }
        return cur->height;
    }

    void update_height(AVLNode_t* cur) {
        int h = max(get_height(cur->left), get_height(cur->right));
        cur->height = h + 1;
    }

    int diff_h(AVLNode_t* cur) {
        return get_height(cur->left) - get_height(cur->right);
    }

    AVLNode_t* maintain(AVLNode_t* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        
        update_height(cur);

        if (cur->left) {
            if (diff_h(cur) > 1) {
                if (get_height(cur->left->left) > get_height(cur->left->right)) {
                    cur = rotate_to_right(cur);
                    cur->right = maintain(cur->right);
                    cur = maintain(cur);
                } else {
                    cur->left = rotate_to_left(cur->left);
                    cur = rotate_to_right(cur);
                    cur->left = maintain(cur->left);
                    cur->right = maintain(cur->right);
                    cur = maintain(cur);
                }
            }
        }
        
        if (cur->right) {
            if (diff_h(cur) < -1) {
                if (get_height(cur->right->right) > get_height(cur->right->left)) {
                    cur = rotate_to_left(cur);
                    cur->left = maintain(cur->left);
                    cur = maintain(cur);
                } else {
                    cur->right = rotate_to_right(cur->right);
                    cur = rotate_to_left(cur);
                    cur->left = maintain(cur->left);
                    cur->right = maintain(cur->right);
                    cur = maintain(cur);
                }
            }
        }

        maintain_fun(cur->left);
        maintain_fun(cur->right);
        maintain_fun(cur);
        return cur;
    }

    AVLNode_t* rotate_to_left(AVLNode_t* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        // AVLNode_t* left = cur->left;
        AVLNode_t* right = cur->right;
        
        AVLNode_t* tmp = right->left;
        right->left = cur;
        cur->right = tmp;
        update_height(cur);
        update_height(right);
        return right;
    }

    AVLNode_t* rotate_to_right(AVLNode_t* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        AVLNode_t* left = cur->left;
        // AVLNode_t* right = cur->right;
        
        AVLNode_t* tmp = left->right;
        left->right = cur;
        cur->left = tmp;
        update_height(cur);
        update_height(left);
        return left;
    }

private:
    void do_destroy(AVLNode_t *cur) {
        if (cur->left) {
            do_destroy(cur->left);
        }
        if (cur->right) {
            do_destroy(cur->right);
        }
        delete cur;
    }
private:
    maintain_t maintain_fun;
    cmp_t cmp;
    AVLNode_t* _root;
    size_t _size;
};

struct Node {
    int value;
    int count;

    int maxi_value;
    int maxi_count;
    
    void copy() {
        maxi_value = value;
        maxi_count = count;
    }
};

class NodeCmp {
public:
    bool operator() (const Node& na, const Node& nb) {
        return na.value < nb.value;
    }
};

class MaintainFunc {
public:
    void operator() (AVLNode<Node>* avl_node) {
        if (avl_node == nullptr) {
            return;
        }
        (avl_node->node).maxi_value = (avl_node->node).value;
        (avl_node->node).maxi_count = (avl_node->node).count;
        if (avl_node->left) {
            auto left = avl_node->left;
            if ((avl_node->node).maxi_count < (left->node).maxi_count ||
                (
                    (avl_node->node).maxi_count == (left->node).maxi_count &&
                    (avl_node->node).maxi_value > (left->node).maxi_value)
                ) {
                
                (avl_node->node).maxi_value = (left->node).maxi_value;
                (avl_node->node).maxi_count = (left->node).maxi_count;     
            }
        }
        
        if (avl_node->right) {
            auto right = avl_node->right;
            if ((avl_node->node).maxi_count < (right->node).maxi_count ||
                (
                    (avl_node->node).maxi_count == (right->node).maxi_count &&
                    (avl_node->node).maxi_value > (right->node).maxi_value)
                ) {
                
                (avl_node->node).maxi_value = (right->node).maxi_value;
                (avl_node->node).maxi_count = (right->node).maxi_count;     
            }
        }
    }
};

int main() {
    int n, k, cmd, v;
    input(n >> k);
    
    AVLTree<Node, NodeCmp, MaintainFunc> avl_tree;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cmd);
        switch (cmd) {
            case 1: {
                scanf("%d", &v);
                //print("CMD: " << cmd << ' ' << v);
                dq.push_back(v);
                if (dq.size() > k) {
                    int pre = *dq.begin();
                    dq.pop_front();
                    Node tmp = {pre, -1, -1, -1};
                    auto ptr = avl_tree.query(tmp);
                    tmp = *ptr;
                    avl_tree.remove(tmp);
                    if (tmp.count > 1) {
                        tmp.count--;
                        tmp.copy();
                        avl_tree.insert(tmp);
                    }
                }
                //avl_tree.print_tree();
                Node tmp({v, 1, v, 1});
                auto ptr = avl_tree.query(tmp);
                if (ptr == nullptr) {
                    avl_tree.insert(tmp);
                } else {
                    tmp = *ptr;
                    tmp.count++;
                    avl_tree.remove(tmp);
                    tmp.copy();
                    avl_tree.insert(tmp);
                }
                //avl_tree.print_tree();
            } break;
            case 2: {
                //print("CMD: " << cmd);
                auto root = avl_tree.get_root();
                printf("%d\n", root->maxi_value);
            } break;
            default: {
                while (1) {}
            }
        }
    }
    return 0;
}
