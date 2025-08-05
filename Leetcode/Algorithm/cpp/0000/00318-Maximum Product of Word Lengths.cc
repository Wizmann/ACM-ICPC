class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> words_sign(n, 0);
        for (int i = 0; i < n; i++) {
            string& word = words[i];
            int sign = 0;
            for (auto c: word) {
                sign |= 1 << (c - 'a');
            }
            words_sign[i] = sign;
        }
        
        size_t ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words_sign[i] & words_sign[j]) {
                    continue;
                }
                ans = max(ans, words[i].size() * words[j].size());
            }
        }
        return ans;
    }
};
