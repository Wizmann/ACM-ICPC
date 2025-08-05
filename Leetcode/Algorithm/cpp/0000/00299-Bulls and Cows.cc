class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        for (auto c: secret) {
            mp[c]++;
        }
        
        int num_a = 0;
        int num_b = 0;
        
        int n = guess.size();
        int m = secret.size();
        // assert(n == m);
        
        for (int i = 0; i < n; i++) {
            if (guess[i] == secret[i]) {
                num_a++;
                mp[secret[i]]--;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (guess[i] != secret[i]) {
                if (mp[guess[i]] != 0) {
                    num_b++;
                    mp[guess[i]]--;
                }
            }
        }
        
        char ret_buffer[10];
        snprintf(ret_buffer, 10, "%dA%dB", num_a, num_b);
        return ret_buffer;
    }
};
