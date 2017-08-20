#include <limits>

typedef long long llint;

int solution(vector<int> &A) {
    const int n = A.size();
    
    llint min_prefix = 0;
    llint prefix_sum = 0;
    llint ans = numeric_limits<llint>::min();
    for (int i = 0; i < n; i++) {
        prefix_sum += A[i];
        ans = max(ans, prefix_sum - min_prefix);
        min_prefix = min(min_prefix, prefix_sum);
    }
    return ans;    
}
