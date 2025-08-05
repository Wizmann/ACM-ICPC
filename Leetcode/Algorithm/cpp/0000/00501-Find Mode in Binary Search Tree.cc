/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int INF = 0x3f3f3f3f; 

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        res.clear();
        pre = INF;
        cnt = -1;
        max_cnt = 0;
        
        dfs(root);
        
        collect();
        
        return res;
    }
private:
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        
        if (root->val == pre) {
            cnt++;
        } else {
            collect();
            
            pre = root->val;
            cnt = 1;
        }
        
        dfs(root->right);
    }
    
    void collect() {
        if (cnt > max_cnt) {
            res.clear();
        }
        
        if (cnt >= max_cnt) {
            res.push_back(pre);
            max_cnt = cnt;
        }
    }
private:
    int pre;
    int cnt;
    int max_cnt;
    vector<int> res;
};
