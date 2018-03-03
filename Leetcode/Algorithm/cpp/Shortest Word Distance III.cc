class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1;
        int p2 = -1;
        int n = words.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            const auto& word = words[i];
            if (word == word1 && word == word2) {
                if (p1 < p2) {
                    p1 = i;
                } else {
                    p2 = i;
                }
            } else if (word == word1) {
                p1 = i;
            } else if (word == word2) {
                p2 = i;
            }
            if (p1 != -1 && p2 != -1) {
                ans = min(ans, abs(p1 - p2));
            }
        }
        return ans;
    }
};
