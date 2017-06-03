class Solution {
public:
    int findIntegers(int num) {
        return dfs(num);
    }
private:
    int dfs(int num) {
        if (num == 0) {
            return 1;
        }
        if (mp.count(num) != 0) {
            return mp[num];
        }
        
        int x = all_one(num);
        int mask1 = x ^ (x >> 2);
        int mask2 = x ^ (x >> 1);
        
        int res = 0;
        if ((num & mask1) != mask2) {
            res = dfs(x ^ mask1) + dfs(x ^ mask2);
        } else {
            res = dfs(num ^ mask2) + dfs(x ^ mask2);
        }
        return mp[num] = res;
    }
    
    int all_one(int num) {
        num = num | (num >> 1);
        num = num | (num >> 2);
        num = num | (num >> 4);
        num = num | (num >> 8);
        num = num | (num >> 16);
        return num;
    }
    
    map<int, int> mp;
};
