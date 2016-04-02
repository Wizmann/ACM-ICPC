/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node* lca(node * root, int v1,int v2)
{
    if (root == nullptr) {
        return nullptr;
    }
    
    int u = root->data;
    if (v1 > v2) {
        swap(v1, v2);
    }
    
    if(v1 <= u && u <= v2) {
        return root;
    } else if (v2 < u) {
        return lca(root->left, v1, v2);
    } else {
        return lca(root->right, v1, v2);
    }
}

