/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        if (!root) {
            return res;
        }
        
        vector<TreeNode*> st;
        auto ptr = root;
        unordered_set<TreeNode*> visit;
        
        while (ptr || !st.empty()) {
            if (ptr) {
                st.push_back(ptr);
                ptr = ptr->left;
            } else {
                ptr = *st.rbegin();
                if (!ptr->left && !ptr->right) {
                    add_to_res(res, st);
                }
                if (visit.find(ptr) != visit.end() || !ptr->right) {
                    st.pop_back();
                    ptr = nullptr;
                } else {
                    visit.insert(ptr);
                    ptr = ptr->right;
                }
            }
        }
        
        return res;
    }
private:
    void add_to_res(vector<string>& res, vector<TreeNode*> nodes) {
        string s = "";
        int n = nodes.size();
        for (int i = 0; i < n; i++) {
            if (i) {
                s += "->";
            }
            s += to_string(nodes[i]->val);
        }
        res.push_back(s);
    }
};
