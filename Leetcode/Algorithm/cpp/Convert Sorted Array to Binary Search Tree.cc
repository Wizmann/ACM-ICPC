/**
* Definition for binary tree
* struct TreeNode {
* int val;
* TreeNode *left;
* TreeNode *right;
* TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		int n = num.size();
		return sortedArrayToBST(num, 0, n - 1);
	}
private:
	TreeNode *sortedArrayToBST(vector<int> &num, int l, int r) {
		if (l > r) {
			return NULL;
		} else if (l == r) {
			return new TreeNode(num[l]);
		} else {
			int m = (l + r) >> 1;
			TreeNode* root = new TreeNode(num[m]);
			root -> left = sortedArrayToBST(num, l, m - 1);
			root -> right = sortedArrayToBST(num, m + 1, r);
			return root;
		}
	}
};