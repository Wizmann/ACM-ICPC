/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root) {
		const int MIN = -0x3f3f3f3f;
        const int MAX = 0x3f3f3f3f;
        return do_checkBST(root, MIN, MAX);
	}

    bool do_checkBST(Node* root, int mini, int maxi) {
        if (root == nullptr) {
            return true;
        }
        int cur = root->data;
        if (cur <= mini || cur >= maxi) {
            return false;
        }
        return do_checkBST(root->left, mini, cur) && do_checkBST(root->right, cur, maxi);
    }
