typedef long long llint;

const llint MOD = 0xdeadbeefcafebabeLL;
const int MAGIC = 1007;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), [](const string& w1, const string& w2) {
            return w1.size() < w2.size();
        });
        
        for (const auto& word: words) {
            if (word.size() == 0) {
                continue;
            }
            if (is_concat(word)) {
                res.push_back(word);
            }
            hash.insert(make_hash(word, 0, word.size()));
        }
        return res;
    }
private:
    llint make_hash(const string& s, int st, int end) {
        llint res = 0;
        for (int i = st; i < end; i++) {
            int c = s[i] - 'a' + 1;
            res = ((res * MAGIC) % MOD + c) % MOD;
        }
        return res;
    }
    
    bool is_concat(const string& word) {
        int n = word.size();
        vector<bool> dp(n + 1);
        dp[0] = 1;
        
        for (int i = 0; i <= n; i++) {
            if (!dp[i]) {
                continue;
            }
            if (dp[n] == 1) {
                return true;
            }
            llint h = 0;
            for (int j = 1; i + j <= n; j++) {
                int c = word[i + j - 1] - 'a' + 1;
                h = ((h * MAGIC) % MOD + c) % MOD;
                if (hash.count(h)) {
                    dp[i + j] = 1;
                }
            }
        }
        return dp[n] == 1;
    }
private:
    unordered_set<llint> hash;
};
