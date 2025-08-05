/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/ 

string int2string(int x) {
    string res = "";
    res += char(x & (0xFF));
    x >>= 8;
    
    res += char(x & (0xFF));
    x >>= 8;
    
    res += char(x & (0xFF));
    x >>= 8;
    
    res += char(x & (0xFF));
    x >>= 8;
    
    return res;
}

int string2int(string s) {
    int x = 0;
    x |= uint8_t(s[3]);
    x <<= 8;
    
    x |= uint8_t(s[2]);
    x <<= 8;
    
    x |= uint8_t(s[1]);
    x <<= 8;
    
    x |= uint8_t(s[0]);
    
    return x;
}

class Serializer {
public:
    Serializer(TreeNode* root_): root(root_)  {
        // pass
    }
    
    string serialize() {
        res = "";
        idx = 0;
        dfs(-1, root, -1);
        return res;
    }
private:
    void dfs(int pre, TreeNode* cur, int child) {
        if (cur == nullptr) {
            return;
        }
        
        if (child == 0 && idx % 2 == 1) {
            idx++;
        }
        
        if (child == 1 && idx % 2 == 0) {
            idx++;
        }
        
        res += int2string(pre);
        res += int2string(idx);
        res += int2string(cur->val);
        
        int cur_idx = idx;
        idx++;
        
        dfs(cur_idx, cur->left, 0);
        dfs(cur_idx, cur->right, 1);
    }
private:
    TreeNode* root;
    string res;
    int idx;
};

class Deserializer {
public:
    Deserializer(string data_): data(data_) {
        for (int i = -2000; i <= 2000; i++) {
            auto s = int2string(i);
            int j = string2int(s);
            assert(i == j);
        }
    }
    
    TreeNode* deserialize() {
        mp.clear();
        TreeNode* root = nullptr;
        int n = data.size();
        for (int i = 0; i < n; i += 12) {
            string a = data.substr(i, 4);
            string b = data.substr(i + 4, 4);
            string c = data.substr(i + 8, 4);
            
            int pre = string2int(a);
            int cur = string2int(b);
            int val = string2int(c);
            
            TreeNode* node = new TreeNode(val);
            
            if (pre == -1) {
                root = node;
            } else {
                TreeNode* father = mp[pre];
                if (cur % 2 == 0) {
                    father->left = node;
                } else {
                    father->right = node;
                }
            }
            
            mp[cur] = node;
        }
        return root;
    }
private:
    map<int, TreeNode*> mp;
    string data;
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        auto s = Serializer(root);
        return s.serialize();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto d = Deserializer(data);
        return d.deserialize();
    }
};
