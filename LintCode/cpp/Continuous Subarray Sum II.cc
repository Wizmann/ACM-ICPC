
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <map>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        int a = maxSubarray(A);
        int b = maxSubarrayII(A);
        print(a << ' ' << b);
        return a > b? ans_a: ans_b;
    }
private:
    int maxSubarray(const vector<int>& A) {
        int maxi = numeric_limits<int>::min();
        int sum = 0;
        ans_a = {-1, -1};
        int n = A.size();
        int st = 0;
        
        for (int i = 0; i < n; i++) {
            sum += A[i];

            if (sum > maxi) {
                maxi = sum;
                ans_a = {st, i};
            }
            
            if (sum < 0) {
                sum = 0;
                st = i + 1;
            }
        }
        return maxi;
    }
    
    int maxSubarrayII(const vector<int>& A) {
        int n = A.size();
        vector<pair<int, int>> acc_ll;
        vector<pair<int, int>> acc_rr;
        int maxi = numeric_limits<int>::min();;
        int ptr = 0;
    
        maxi = 0;
        ptr = 0;
        for (int i = 0, j = 0; i < n; i++) {
            j += A[i];
            if (maxi < j) {
                ptr = i;
                maxi = j;
            }
            acc_ll.push_back({maxi, ptr});
        }
        
        maxi = numeric_limits<int>::min();;
        ptr = 0;
        for (int i = n - 1, j = 0; i >= 0; i--) {
            j += A[i];
            if (maxi < j) {
                ptr = i;
                maxi = j;
            }
            acc_rr.push_back({maxi, ptr});
        }
        reverse(acc_rr.begin(), acc_rr.end());
        
        maxi = numeric_limits<int>::min();
        
        for (int i = n - 1; i > 0; i--) {
            auto lp = acc_ll[i - 1];
            auto rp = acc_rr[i];
            
            int sum = lp.first + rp.first;
            
            if (sum > maxi) {
                maxi = sum;
                ans_b = {rp.second, lp.second};
            }
        }
        return maxi;
    }
private:
    vector<int> ans_a;
    vector<int> ans_b;
};

int main() {
    auto S = Solution();
    vector<int> vec = {-101,-33,-44,-55,-67,-78,-101,-33,-44,-55,-67,-78,-100,-200,-1000,-22,-100,-200,-1000,-22};
    S.continuousSubarraySumII(vec);
    return 0;
}
