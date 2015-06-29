class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        n = grid.size();
        if (n == 0) {
            return 0;
        }
        m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        
        grid_num = m * n;
        init();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) {
                    continue;
                }
                
                if (i - 1 >= 0 && grid[i - 1][j]) {
                    island_union({i - 1, j}, {i, j});
                }
                if (j - 1 >= 0 && grid[i][j - 1]) {
                    island_union({i, j}, {i, j - 1});
                }
            }
        }
        
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) {
                    continue;
                }
                
                st.insert(find_father(get_nr(i, j)));
            }
        }
        return st.size();
    }
private:
    void init() {
        father.resize(grid_num);
        for (int i = 0; i < grid_num; i++) {
            father[i] = i;
        }
    }
    
    int get_nr(int y, int x) {
        return y * m + x;
    }
    
    void island_union(pair<int, int> pa, pair<int, int> pb) {
        int aa = get_nr(pa.first, pa.second);
        int bb = get_nr(pb.first, pb.second);
        
        father[find_father(aa)] = find_father(bb);
    }
    
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

private:
    int n, m;
    int grid_num;
    vector<int> father;
};
