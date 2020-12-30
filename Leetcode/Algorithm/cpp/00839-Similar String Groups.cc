class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        father = vector<int>(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (find_father(i) == find_father(j)) {
                    continue;
                }
                
                int diff = 0;
                for (int k = 0; k < m; k++) {
                    if (A[i][k] != A[j][k]) {
                        diff++;
                    }
                    if (diff > 2) {
                        break;
                    }
                }
                if (diff <= 2) {
                    father[find_father(i)] = find_father(j);
                }
            }
        }
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(find_father(i));
        }
        return st.size();
    }
private:
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
private:
    vector<int> father;
};
