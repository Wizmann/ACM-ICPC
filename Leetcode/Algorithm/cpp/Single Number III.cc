class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        res.clear();
        for (auto& num: nums) {
            if (num == 0) {
                num = 0xcafebabe;
            }
        }
        do_single_number(nums.begin(), nums.end());
        if (res[0] == 0xcafebabe) {
            res[0] = 0;
        }
        if (res[1] == 0xcafebabe) {
            res[1] = 0;
        }
        return res;
    }
private:
    void do_single_number(vector<int>::iterator st, vector<int>::iterator end) {
        if (st == end) {
            return;
        }
        int n = distance(st, end);
        int pivot = *(st + rand() % n);
        auto mid = partition(st, end, [&](const int u) { return u <= pivot; });
        function<int(int, int)> a_xor_b = [](const int a, const int b) {
            return a ^ b;
        };
        int l = accumulate(st, mid, 0, a_xor_b);
        int r = accumulate(mid, end, 0, a_xor_b);
        
        if (l && r) {
            res = {l, r};
            return;
        } else if (l) {
            do_single_number(st, mid);
        } else {
            do_single_number(mid, end);
        }
    }
private:
    vector<int> res;
};
