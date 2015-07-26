class Solution {
public:
    int getMaxSubarraySum(vector<int> &A) {
        vector<pair<int, int> > left_max_array, right_max_array;
        vector<int> left_max, right_max;
        n = A.size();
        calc(A, 0, n - 1, left_max_array, left_max,
            [](int i)->int {return i + 1;});
        calc(A, n - 1, 0, right_max_array, right_max,
            [](int i)->int {return i - 1;});
        int ans = numeric_limits<int>::min();
        for (int i = 0; i < n; i++) {
            ans = max(ans, A[i]);
        }
        if (ans < 0) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
            int mid = A[i];            
            auto ll = i - 1 >= 0? left_max_array[i - 1]:  pair<int, int>({0, -1});
            auto rr = i + 1 < n ? right_max_array[i + 1]: pair<int, int>({0, n});
            int l_max = ll.second - 1 >= 0? left_max[ll.second - 1]: 0;
            int r_max = rr.second + 1 < n ? right_max[rr.second + 1]: 0;
            
            int sum = ll.first + rr.first;
            ans = max(ans, sum);
            ans = max(ans, sum + mid);
            ans = max(ans, sum + l_max);
            ans = max(ans, sum + r_max);
        }
        return ans;
    }
private:
    void calc(const vector<int>& A, int st, int end, 
            vector<pair<int, int> >& max_array, vector<int>& max_num,
            function<int(int)> fun) {
        max_array.resize(n);
        max_num.resize(n);

        int sum = 0;
        int maxi = numeric_limits<int>::min();
        int ptr = st;

        for (int i = st; i != end; i = fun(i)) {
            sum += A[i];
            maxi = max(maxi, A[i]);
            if (sum <= 0) {
                sum = 0;
                ptr = i;
            }
            max_num[i] = maxi;
            max_array[i] = {sum, ptr};
        }
    }
private:
    int n;
};
