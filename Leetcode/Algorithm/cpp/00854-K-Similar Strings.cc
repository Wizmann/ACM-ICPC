class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        queue<string> q;
        q.push(s1);
        map<string, int> mp;
        mp[s1] = 0;

        while (!q.empty()) {
            s1 = q.front();
            q.pop();
            int step = mp[s1];
            if (s1 == s2) {
                return step;
            }

            for (int i = 0; i < n; i++) {
                if (s1[i] != s2[i]) {
                    for (int j = i + 1; j < n; j++) {
                        if (s1[j] == s2[i]) {
                            string s3 = s1;
                            swap(s3[i], s3[j]);
                            if (mp.count(s3) == 0) {
                                mp[s3] = step + 1;
                                q.push(s3);
                            }
                        }
                    }
                    break;
                }
            }
        }
        return -1;
    }
};
