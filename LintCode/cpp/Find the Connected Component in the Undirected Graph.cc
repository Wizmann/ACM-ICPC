/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        label_to_idx.clear();
        idx_to_label.clear();
        int n = nodes.size();
        int idx = 0;
        father.resize(n);
        for (const auto& node: nodes) {
            label_to_idx[node->label] = idx;
            idx_to_label[idx] = node->label;
            father[idx] = {idx, 1};
            idx++;
        }
        
        for (auto node: nodes) {
            int u = label_to_idx[node->label];
            for (auto neighbor: node->neighbors) {
                int v = label_to_idx[neighbor->label];
                do_union(u, v);
            }
        }

        for (int i = 0; i < n; i++) {
            find_father(i);
        }
        unordered_map<int, vector<int> > res;
        for (int i = 0; i < n; i++) {
            int u = find_father(i);
            if (res.find(u) == res.end()) {
                res[u] = vector<int>();
            }
            res[u].push_back(idx_to_label[i]);
        }
        
        vector<vector<int> > ans;
        for (auto& p: res) {
            auto& vec = p.second;
            sort(vec.begin(), vec.end());
            ans.push_back(vec);
        }
        return ans;
    }
private:
    void do_union(int a, int b) {
        a = find_father(a);
        b = find_father(b);
        if (a == b) {
            return;
        }
        if (father[a].second > father[b].second) {
            swap(a, b);
        }
        father[a].second += father[b].second;
        father[b].first = father[a].first;
    }
    int find_father(int x) {
        if (father[x].first == x) {
            return x;
        }
        return father[x].first = find_father(father[x].first);
    }
private:
    vector<pair<int, int> > father;
    unordered_map<int, int> idx_to_label;
    unordered_map<int, int> label_to_idx;
};
