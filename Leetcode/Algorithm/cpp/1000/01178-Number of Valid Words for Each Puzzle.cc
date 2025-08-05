struct TrieNode {
    TrieNode(int l_, int r_) {
        nxt[0] = l_;
        nxt[1] = r_;
    }
    
    int nxt[2];
    int cnt = 0;
};

struct Trie {
    Trie() {
        tree.push_back(TrieNode(-1, -1));
    }
    
    void insert(int cur, int num, int length) {
        if (length == -1) {
            // print(cur << ' ' << length);
            tree[cur].cnt++;
            return;
        }
        int v = (num & (1 << length)) ? 1: 0;
        if (tree[cur].nxt[v] == -1) {
            tree.push_back(TrieNode(-1, -1));
            tree[cur].nxt[v] = tree.size() - 1;
        }
        int nxt = tree[cur].nxt[v];
        insert(nxt, num, length - 1);
    }
    
    int query(int cur, int num, int length) {
        if (length == -1) {
            return tree[cur].cnt;
        }
        int v = (num & (1 << length)) ? 1: 0;
        if (tree[cur].nxt[v] == -1) {
            return 0;
        }
        int nxt = tree[cur].nxt[v];
        return query(nxt, num, length - 1);
    }
    
    int idx = 0;
    vector<TrieNode> tree;
};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        const int n = puzzles.size();
        Trie trie;
        for (const auto& word: words) {
            int u = 0;
            int m = word.size();
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                int c = word[i] - 'a';
                if (u & (1 << c)) {
                    continue;
                }
                cnt++;
                u |= (1 << c);
            }
            if (cnt <= 7) {
                trie.insert(0, u, 25);
            }
        }
        vector<int> ans(n);
        for (int idx = 0; idx < n; idx++) {
            const auto& puzzle = puzzles[idx];
            string s;
            set<int> st;
            for (auto c: puzzle) {
                if (st.count(c) == 0) {
                    s += c;
                    st.insert(c);
                }
            }
            int m = s.size();
            for (int i = 0; i < (1 << m); i++) {
                if ((i & 1) == 0) {
                    continue;
                }
                int u = 0;
                for (int j = 0; j < m; j++) {
                    if (i & (1 << j)) {
                        int c = s[j] - 'a';
                        u |= (1 << c);
                    }
                }
                ans[idx] += trie.query(0, u, 25);
            }
        }
        return ans;
    }
};

