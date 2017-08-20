#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <limits>
#include <set>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11
    if (A.size() <= 3) {
        return 0;
    }
    int n = A.size();

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    {
        int min_prefix = 0;
        int prefix_sum = 0;
        for (int i = 1; i < n; i++) {
            prefix_sum += A[i];
            left[i] = prefix_sum - min_prefix;
            min_prefix = min(min_prefix, prefix_sum);
        }
    }

    {
        int min_suffix = 0;
        int suffix_sum = 0;
        for (int i = n - 2; i >= 0; i--) {
            suffix_sum += A[i];
            right[i] = suffix_sum - min_suffix;
            min_suffix = min(min_suffix, suffix_sum);
        }
    }

    int ans = numeric_limits<int>::min();
    for (int i = 1; i + 1 < n; i++) {
        ans = max(ans, left[i] + right[i] - 2 * A[i]);
    }

    return ans;
}
