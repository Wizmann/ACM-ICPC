const int INF = 0x3f3f3f3f;

class WordDistance {
public:
    WordDistance(vector<string> words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            const auto& word = words[i];
            mp[word].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = INF;
        for (int i = 0, j = 0; i < mp[word1].size() && j < mp[word2].size(); /* pass */) {
            ans = min(ans, abs(mp[word1][i] - mp[word2][j]));
            if (mp[word1][i] < mp[word2][j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
private:
    map<string, vector<int> > mp;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
