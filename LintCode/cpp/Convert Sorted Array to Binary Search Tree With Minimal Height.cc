/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return do_sortedArrayToBST(A.begin(), A.end());
    }
private:
    TreeNode *do_sortedArrayToBST(
            vector<int>::iterator st,
            vector<int>::iterator end) {
        if (st == end) {
            return nullptr;
        }
        int d = distance(st, end);
        auto mid = st + d / 2;
        auto cur = new TreeNode(*mid);
        cur->left = do_sortedArrayToBST(st, mid);
        cur->right = do_sortedArrayToBST(mid + 1, end);
        return cur;
    }
};



