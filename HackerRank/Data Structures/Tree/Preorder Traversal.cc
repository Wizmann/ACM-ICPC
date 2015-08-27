/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

#define print(x) cout << x << endl

void Preorder(node *root) {
    stack<node*> st;
    node* ptr = root;
    vector<int> res;
    
    while (ptr || !st.empty()) {
        if (ptr == nullptr) {
            ptr = st.top();
            st.pop();
            ptr = ptr->right;
            continue;
        }
        res.push_back(ptr->data);
        st.push(ptr);
        ptr = ptr->left;
    }
    for (auto num: res) {
        printf("%d ", num);
    }
    puts("");
}
