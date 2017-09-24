class UnionFind {
public:
    UnionFind(int n_): n(n_), father(n_) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    
    void make_union(int a, int b) {
        father[find_father(b)] = find_father(a);
    }
    
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
    
    bool is_same_union(int a, int b) {
        return find_father(a) == find_father(b);
    }
private:
    int n;
    vector<int> father;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        auto u = UnionFind(1111);
        for (auto edge: edges) {
            int a = edge[0];
            int b = edge[1];
            
            if (u.is_same_union(a, b)) {
                return {a, b};
            }
            
            u.make_union(a, b);
        }
        return {};
    }
};
