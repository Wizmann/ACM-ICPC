const int INF = 0x3f3f3f3f;

class DisjointSet {
public:
    DisjointSet(int n): father(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
    void make_union(int a, int b) {
        father[find_father(a)] = find_father(b);
    }
private:
    vector<int> father;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> ind(n, 0);
        DisjointSet ds(n);
        
        int excluded = -1;
        for (int i = 0; i < n; i++) {
            const auto& edge = edges[i];
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            ind[b]++;
            if (ind[b] == 2) {
                excluded = i;
                break;
            }
        }
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (i == excluded) {
                continue;
            }
            const auto& edge = edges[i];
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            if (ds.find_father(a) == ds.find_father(b)) {
                if (excluded == -1) {
                    return edge;
                } else {
                    valid = false;
                    break;
                }
            }
            ds.make_union(b, a);
        }
        
        if (valid) {
            return edges[excluded];
        }
        for (int i = 0; i < n; i++) {
            const auto& edge = edges[i];
            if (i != excluded && edge[1] == edges[excluded][1]) {
                return edge;
            }
        }
        return {};
    }
};
