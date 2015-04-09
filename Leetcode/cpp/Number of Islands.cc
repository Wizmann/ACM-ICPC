class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        _n = grid.size();
        if (_n == 0) {
            return 0;
        }
        _m = grid.begin()->size();
        if (_m == 0) {
            return 0;
        }
        _father.resize(_n * _m);
        for (int i = 0; i < _n * _m; i++) {
            _father[i] = i;
        }
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _m; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                    cnc({i, j}, {i - 1, j});
                }
                if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                    cnc({i, j}, {i, j - 1});
                }
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _m; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                st.insert(find_father(get_idx({i, j})));
            }
        }
        return st.size();
    }
private:
    int get_idx(const pair<int, int>& p) {
        return p.first * _m + p.second;
    }
    int find_father(int idx) {
        if (_father[idx] == idx) {
            return idx;
        }
        return _father[idx] = find_father(_father[idx]);
    }
    void cnc(const pair<int, int>& a, const pair<int, int>& b) {
        int aa = get_idx(a);
        int bb = get_idx(b);
        
        _father[find_father(aa)] = find_father(bb);
    }
private:
    vector<int> _father;
    int _n;
    int _m;
};
