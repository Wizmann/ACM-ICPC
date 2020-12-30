class Solution {
public:
    vector<TreeNode *> _generateTrees(int st, int end) 
    {
        vector<TreeNode *> ret;
        if (st > end) {
            ret.push_back(NULL);
        } else {
            for (int i = st; i <= end; i++) {
                vector<TreeNode *> leftTree  = _generateTrees(st, i - 1);
                vector<TreeNode *> rightTree = _generateTrees(i + 1, end);
                for (int j = 0; j < (int)leftTree.size(); j++) {
                    for (int k = 0; k < (int)rightTree.size(); k++) {
                        TreeNode* new_node = new TreeNode(i + 1);
                        new_node -> left = leftTree[j];
                        new_node -> right = rightTree[k];
                        ret.push_back(new_node);
                    }
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        return _generateTrees(0, n-1);
    }
};
