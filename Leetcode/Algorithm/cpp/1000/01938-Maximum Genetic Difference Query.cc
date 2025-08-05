const int BITS = 18;

struct TrieNode {
    int next[2] = {-1, -1};
    int count[2] = {0, 0};
};

class Trie {
public:
    Trie() {
        nodes.push_back(TrieNode());
    }
    
    void insert(int num) {
        modify(num, 1);
    }
    
    void remove(int num) {
        modify(num, -1);
    }
    
    int query(int num) {
        int cur = 0;
        int res = 0;
        for (int bits = BITS - 1; bits >= 0; bits--) {
            auto& curnode = nodes[cur];
            int u = (num & (1 << bits)) ? 1 : 0;
            int v = 1 << bits;
            int nxt = curnode.next[u ^ 1];
            if (curnode.next[u ^ 1] == -1 || curnode.count[u ^ 1] == 0) {
                nxt = curnode.next[u];
                v = 0;
            }
            cur = nxt;
            res += v;
        }
        return res;
    }
private:
    void modify(int num, int delta) {
        int cur = 0;
        for (int bits = BITS - 1; bits >= 0; bits--) {
            assert(cur != -1);
            auto& curnode = nodes[cur];
            int u = (num & (1 << bits)) ? 1 : 0;
            if (curnode.next[u] == -1) {
                curnode.next[u] = nodes.size();
                nodes.push_back(TrieNode());
            }
            int nxt = curnode.next[u];
            curnode.count[u] += delta;
            cur = nxt;
        }
    }
private:
    deque<TrieNode> nodes;
};

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        g.resize(n);
        int root = -1;
        
        for (int i = 0; i < n; i++) {
            int p = parents[i];
            if (p >= 0) {
                g[p].push_back(i);
            } else {
                root = i;
            }
        }
        
        int q = queries.size();
        qs.resize(n);
        for (int i = 0; i < q; i++) {
            qs[queries[i][0]].push_back({queries[i][1], i});
        }
        res.resize(q);
        dfs(root);
        return res;
    }
private:
    void dfs(int root) {
        trie.insert(root);
        for (auto& p : qs[root]) {
            res[p.second] = trie.query(p.first);
        }
        for (auto& nxt : g[root]) {
            dfs(nxt);
        }
        trie.remove(root);
    }
private:
    vector<int> res;
    vector<vector<int>> g;
    vector<vector<pair<int, int>>> qs;
    Trie trie;
};

