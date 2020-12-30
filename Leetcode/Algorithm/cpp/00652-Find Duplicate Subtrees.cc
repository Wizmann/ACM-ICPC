/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef long long llint;

const llint MOD = 0xdeadbeefcaffLL;
const llint PRIME1 = 17777777;
const llint PRIME2 = 29999999;
const llint MAGIC1 = 23456789;
const llint MAGIC2 = 19999999LL;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        dfs(root);
        for (auto p: mp) {
            if (p.second.second > 1) {
                res.push_back(p.second.first);
            }
        }
        return res;
    }
private:
    llint dfs(TreeNode* root) {
        if (root == nullptr) {
            return MAGIC2;
        }
        llint l = dfs(root->left);
        llint r = dfs(root->right);
        
        llint hash = ((l * PRIME1 + r * PRIME2) % MOD + (root->val + 1) * MAGIC1) % MOD;
        
        hash = (hash % MOD) + MOD % MOD;
        
        if (mp.count(hash) == 0) {
            mp[hash] = {root, 1};
        } else {
            mp[hash].second++;
        }
        return hash;
    }
private:
    map<llint, pair<TreeNode*, int> > mp;
};
