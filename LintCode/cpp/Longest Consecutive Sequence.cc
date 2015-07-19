class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        for (auto i: num) {
            father[i] = i;
        }
        
        for (auto i: num) {
            int a = i - 1;
            int b = i + 1;
            
            if (father.find(a) != father.end()) {
                father[find_father(a)] = find_father(i);
            }
            
            if (father.find(b) != father.end()) {
                father[find_father(b)] = find_father(i);
            }
        }
        
        int ans = 0;
        unordered_map<int, int> cnt;
        for (auto p: father) {
            cnt[p.second]++;
            ans = max(ans, cnt[p.second]);
        }
        return ans;
    }
private:
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
private:
    unordered_map<int, int> father;
};
