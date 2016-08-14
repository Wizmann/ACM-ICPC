/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value)
{
    if (root == NULL) {
        root = new node();
        root->data = value;
        root->left = root->right = NULL;
        return root;
    }
    if (root->data > value) {
        if (root->left == NULL) {
            root->left = new node();
            root->left->data = value;
            root->left->left = root->left->right = NULL;
        } else {
            insert(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = new node();
            root->right->data = value;
            root->right->left = root->right->right = NULL;
        } else {
            insert(root->right, value);
        } 
    }
    return root;
}
