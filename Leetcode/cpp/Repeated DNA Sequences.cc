class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        
        int len = s.size();
        int key = 0;
        for (int i = 0; i < 9; i++) {
            key = key * 4 + ord(s[i]);
        }
        
        unordered_map<int, int> mp;
        for (int i = 9; i < len; i++) {
            key = key * 4 + ord(s[i]);
            key &= MASK;
            mp[key]++;
        }
        
        for (auto pair: mp) {
            int dna = pair.first;
            int count = pair.second;
            
            if (count <= 1) {
                continue;
            }
            res.push_back(dna_to_string(dna));
        }
        return res;
    }
private:
    int ord(char c) {
        switch(c) {
            case 'A': return 0;
            case 'T': return 1;
            case 'C': return 2;
            case 'G': return 3;
        }
        return -1;
    }
    
    char chr(int u) {
        switch(u) {
            case 0: return 'A';
            case 1: return 'T';
            case 2: return 'C';
            case 3: return 'G';
        }
        return '\0';
    }
    
    string dna_to_string(int dna) {
        string res = "fuckmebaby";
        for (int i = 0; i < 10; i++) {
            int u = dna & 3;
            dna >>= 2;
            res[9 - i] = chr(u);
        }
        return res;
    }
private:
    static const int MASK = 0xFFFFF;
};
