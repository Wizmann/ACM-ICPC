class Solution {
public:
    int findCircleNum(vector<vector<int>>& M_) {
        M = M_;
        n = M.size();
        
        father = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 0) {
                    continue;
                }
                int fa = find_father(i);
                int fb = find_father(j);
                
                father[fb] = fa;
            }
        }
        
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(find_father(i));
        }
        return s.size();
    }
private:
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

    int n;
    vector<vector<int> > M;
    vector<int> father;
};
