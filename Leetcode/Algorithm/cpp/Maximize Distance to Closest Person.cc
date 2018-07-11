class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int n = seats.size();
        int ans = 0;
        int pre = -1;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (pre == -1) {
                    ans = max(ans, i);
                    pre = i;
                } else {
                    ans = max(ans, (i - pre) / 2);
                    pre = i;
                }
            }
        }
        if (pre >= 0) {
            ans = max(ans, n - pre - 1);
        }
        return ans;
    }
};
