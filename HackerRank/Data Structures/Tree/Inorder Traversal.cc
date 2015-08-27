/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Inorder(node *root) {
    stack<node*> st;
    node* ptr = root;
    
    while (ptr || !st.empty()) {
        if (ptr == nullptr) {
            ptr = st.top();
            printf("%d ", ptr->data);
            st.pop();
            ptr = ptr->right;
            continue;
        }
        st.push(ptr);
        ptr = ptr->left;
    }
    puts("");
}
