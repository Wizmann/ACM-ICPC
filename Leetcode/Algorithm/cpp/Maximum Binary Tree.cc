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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return nullptr;
        }
        vector<pair<int, int> > enums(n);
        
        for (int i = 0; i < n; i++) {
            enums[i] = {nums[i], i};
        }
        sort(enums.begin(), enums.end());
        reverse(enums.begin(), enums.end());
        
        map<int, TreeNode*> mp;
        
        TreeNode* root = new TreeNode(enums.begin()->first);
        mp.insert({enums.begin()->second, root});
        for (int i = 1; i < n; i++) {
            TreeNode* newNode = new TreeNode(enums[i].first);
            auto iter = mp.upper_bound(enums[i].second);
            
            if (iter == mp.end()) {
                --iter;
                iter->second->right = newNode;
            } else if (iter == mp.begin()) {
                iter->second->left = newNode;
            } else {
                auto jter = iter;
                --iter;
                TreeNode* p1 = iter->second;
                TreeNode* p2 = jter->second;
                
                if (p1->val > p2->val) {
                    p2->left = newNode;
                } else {
                    p1->right = newNode;
                }
            }
            mp.insert({enums[i].second, newNode});
        }
        return root;
    }
};
