class Solution {
public:
    string minWindow(string S, string T) {
        deque<char> dq;
        
        int a[256] = {0};
        int b[256] = {0};
        
        int count = 0;
        
        for (int i = 0; i < T.size(); i++) {
            if (a[T[i]] == 0) count++;
            a[T[i]]++;
        }
        
        int res = 1 << 28;
        int st = -1;
        int visit = 0;
        for (int i = 0; i < S.size(); i++) {
            dq.push_back(S[i]);

            b[S[i]] += 1;
            if (b[S[i]] == a[S[i]]) visit++;
            
            while (visit == count) {
                if (dq.size() < res) {
                    res = dq.size();
                    st = i - res + 1;
                }
                char now = dq[0];
                dq.pop_front();
                b[now]--;
                if (a[now] > b[now]) visit--;
            }
        }
        
        if (st == -1) return "";
        else return S.substr(st, res);
    }
};
