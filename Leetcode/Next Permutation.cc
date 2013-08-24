class Solution {
public:
    static const int INF = 1 << 29;
    void nextPermutation(vector<int> &num) {
        if (num.size() == 0) {
            return;
        }
        int tail = num.size() - 1;
        while (tail >= 0) {
            int pos = greater_pos(tail + 1, num.size(), num[tail], num);
            if (pos == -1) {
                tail--;
            } else {
                swap(num[tail], num[pos]);
                sort(num.begin() + tail + 1, num.end());
                return;
            }
        }
        sort(num.begin(), num.end());
    }
    
    int greater_pos(int begin, int end, int val, vector<int>& num) {
        int greater_val = INF;
        int greater_pos = -1;
        for(int i = begin; i < end; i++) {
            if (num[i] > val) {
                if (num[i] < greater_val) {
                    greater_val = num[i];
                    greater_pos = i;
                }
            }
        }
        return greater_pos;
    }
};
