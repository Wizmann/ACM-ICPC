const int N = 22;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int bits = (1 << (maxChoosableInteger + 1)) - 2;
        int remains = desiredTotal;
        if (remains == 0) {
            return true;
        }
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < remains) {
            return false;
        }
        return dfs(bits, remains);
    }
private:
    bool dfs(int bits, int remains) {
        if (remains <= 0) {
            return false;
        }
        int hash = make_hash(bits, remains);
        
        if (mp.count(hash) != 0) {
            return mp[hash];
        }
        
        bool res = false;
        for (int i = 1; i <= N && !res; i++) {
            if (bits & (1 << i)) {
                res |= !dfs(bits ^ (1 << i), remains - i);
            }
        }
        return mp[hash] = res;
    }
    
    int make_hash(int bits, int remains) {
        return bits * 1000 + remains;
    }
private:
    unordered_map<int, bool> mp;
};
