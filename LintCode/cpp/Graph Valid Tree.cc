class UnionSet {
public:
    UnionSet(size_t n) {
        _father.resize(n);
        for (int i = 0; i < n; i++) {
            _father[i] = i;
        }
    }
    
    bool is_union(int x, int y) {
        int xx = get_father(x);
        int yy = get_father(y);
        return xx == yy;
    }
    
    void set_union(int x, int y) {
        int xx = get_father(x);
        int yy = get_father(y);
        _father[xx] = yy;
    }
private:
    int get_father(int x) {
        if (_father[x] == x) {
            return x;
        }
        return _father[x] = get_father(_father[x]);
    }
private:
    vector<int> _father;
};

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        auto union_set = UnionSet(n);
        int m = edges.size();
        
        if (m != n - 1) {
            return false;
        }
        
        
        for (auto edge: edges) {
            union_set.set_union(edge[0], edge[1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!union_set.is_union(0, i)) {
                return false;
            }
        }
        return true;
    }
};
