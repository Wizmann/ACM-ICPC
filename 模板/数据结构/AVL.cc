#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
};

int get_height(node* root) {
    if (root == nullptr) {
        return -1;
    }
    return root->ht;
}

void update_height(node* root) {
    root->ht = 1 + max(
        get_height(root->left),
        get_height(root->right));
}

node* rotate_to_left(node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    node* left = root->left;
    node* right = root->right;
    
    node* tmp = right->left;
    right->left = root;
    root->right = tmp;
    update_height(root);
    update_height(right);
    return right;
}

node* rotate_to_right(node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    node* left = root->left;
    node* right = root->right;
    
    node* tmp = left->right;
    left->right = root;
    root->left = tmp;
    update_height(root);
    update_height(left);
    return left;
}

int diff_h(node* root) {
    return (get_height(root->left) - get_height(root->right));
}

node* do_insert(node* root, int val) {
    if (root == nullptr) {
        return new node({val, nullptr, nullptr, 0});
    }
    if (val < root->val) {
        root->left = do_insert(root->left, val);
    } else {
        root->right = do_insert(root->right, val);
    }
    
    update_height(root);
    
    if (abs(diff_h(root)) > 1) {
        if (get_height(root->left) < get_height(root->right)) {
            if (val > root->right->val) {
                root = rotate_to_left(root);
            } else {
                root->right = rotate_to_right(root->right);
                root = rotate_to_left(root);
            }
        } else {
            if (val < root->left->val) {
                root = rotate_to_right(root);
            } else {
                root->left = rotate_to_left(root->left);
                root = rotate_to_right(root);
            }
        }
    }
    return root;
}

node* insert(node* root,int val)
{
    return do_insert(root, val);
}

void inorder_traversal(node* root) {
    if (!root) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d (h: %d d: %d)\n", root->val, root->ht, diff_h(root));
    inorder_traversal(root->right);
}

void preorder_traversal(node* root) {
    if (!root) {
        return;
    }
    printf("%d (h: %d d: %d)\n", root->val, root->ht, diff_h(root));
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main() {
    vector<int> vec = {5, 3, 4};
    node* root = nullptr;
    for (auto i: vec) {
        root = insert(root, i);
        inorder_traversal(root);
        puts("---");
        preorder_traversal(root);
        puts("===");
    }
    return 0;
}
