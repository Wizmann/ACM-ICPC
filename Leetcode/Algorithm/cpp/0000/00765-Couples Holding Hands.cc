class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[row[i]] = i;
        }
        
        for (int i = 0; i < n; i += 2) {
            if (row[i] == -1) {
                continue;
            }
            
            int p = i;
            
            int s = 0;
            while (true) {
                if (row[p] == -1) {
                    break;
                }
                int next = mp[row[p] ^ 1];
                swap(row[p + 1], row[next]);
                row[p] = row[p + 1] = -1;
                s++;
                p = next & 0xFFFFFFFE;
            }
            res += s - 1;
        }
        return res;
    }
};
