class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return true;
        }
        vector<int> desc;
        preorder += ",";
        int tmp = 0;
        for (auto c: preorder) {
            if (c != ',') {
                tmp = tmp * 10 + (c - '0');
            } else {
                desc.push_back(tmp);
                tmp = 0;
            }
        }
        for (auto num: desc) {
            cout << num << endl;
        }
        cnt = 0;
        ptr = 0;
        return dfs(desc, nullptr) && cnt == desc.size();
    }
private:
    bool dfs(const vector<int>& desc, TreeNode* pre) {
        if (ptr >= desc.size()) {
            return false;
        }
        TreeNode* cur = new TreeNode(desc[ptr]);
        cnt++;
        if (pre) {
            if (!pre->left) {
                pre->left = cur;
            } else if (!pre->right) {
                pre->right = cur;
            } else {
                return false;
            }
        }
        if (desc[ptr] == -13) {
            ptr++;
            return true;
        } else {
            ptr++;
            return dfs(desc, cur) && dfs(desc, cur);
        }
    }
private:
    int ptr;
    int cnt;
};
