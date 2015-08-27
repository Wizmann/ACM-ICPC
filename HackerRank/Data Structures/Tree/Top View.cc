/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root)
{
    stack<node*> st;
    vector<int> vec;
    
    node* ptr = root;
    while (ptr) {
        vec.push_back(ptr->data);
        ptr = ptr->left;
    }
    reverse(vec.begin(), vec.end());
    
    ptr = root->right;
    while (ptr) {
        vec.push_back(ptr->data);
        ptr = ptr->right;
    }
    
    for (auto num: vec) {
        cout << num << " ";
    }
    cout << endl;
}
