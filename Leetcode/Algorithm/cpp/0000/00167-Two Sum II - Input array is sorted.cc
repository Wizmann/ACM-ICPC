class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p = 0;
        int q = n - 1;
        while (p < q) {
            int s = numbers[p] + numbers[q];
            if (s == target) {
                return vector<int>{p + 1, q + 1};
            } else if (s < target) {
                p++;
            } else {
                q--;
            }
        }
        // assert(false);
        return vector<int>();
    }
};
