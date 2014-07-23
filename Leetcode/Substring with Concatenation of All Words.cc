class Solution {  
public:  
    vector<int> findSubstring(string S, vector<string> &L) {  
        map<string, int> words;  
        map<string, int> curStr;  
        for (int i = 0; i < L.size(); ++i) { 
            words[L[i]]++;  
        }
        
        int n = L.size();  
        vector<int> ret;  
        
        if (n <= 0) {
            return ret;
        }
        int m = L[0].size();
        
        for (int i = 0; i <= (int)S.size() - m * n; i++)  
        {  
            curStr.clear();  
            int j = 0;  
            for (j = 0; j < n; j++)  
            {  
                string w = S.substr(i + j * m, m);  
                if (words.find(w) == words.end()) {
                    break;
                }
                curStr[w]++;
                if (curStr[w] > words[w]) {
                    break;
                }
            }  
            if (j == n) {
                ret.push_back(i);
            }
        }  
        return ret;  
    }  
};
