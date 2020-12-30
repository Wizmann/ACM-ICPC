class DisjointSet {
public:
    DisjointSet(int n_): n(n_) {
        father.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        } else {
            return father[x] = find_father(father[x]);
        }
    }
    
    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        
        father[fa] = fb;
    }
    
    bool is_same_set(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);
        
        return fa == fb;
    }
private:
    int n;
    vector<int> father;
};

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        DisjointSet ds(N + 1);
        vector<vector<int> > g(N + 1);
        for (const auto& dislike: dislikes) {
            int a = dislike[0];
            int b = dislike[1];
            
            if (ds.is_same_set(a, b)) {
                return false;
            }
            
            g[a].push_back(b);
            g[b].push_back(a);
            
            for (auto next: g[a]) {
                ds.make_union(b, next);
            }
            
            for (auto next: g[b]) {
                ds.make_union(a, next);
            }        
        }
        return true;
    }
};
