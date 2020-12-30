const int CHAR_RANGE = 256;

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int> > vec(CHAR_RANGE);
        for (int i = 0; i < CHAR_RANGE; i++) {
            vec[i] = {char(i), 0};
        }
        for (auto c: s) {
            vec[c].second++;
        }
        sort(vec.begin(), vec.end(), [](pair<char, int> pa, pair<char, int> pb) {
            return pa.second > pb.second;
        });
        
        string ans = "";
        for (auto item: vec) {
            if (item.second == 0) {
                break;
            }
            ans += string(item.second, item.first);
        }
        return ans;
    }
};
