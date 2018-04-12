#include <algorithm>

const int INF = (-1u) >> 1;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int res = INF;
    
    for (auto num: A) {
        auto iter = lower_bound(A.begin(), A.end(), -num);
        if (iter != A.end()) {
            res = min(res, abs(*iter + num));
        }
        if (iter != A.begin()) {
            res = min(res, abs(*(--iter) + num));
        }
    }
    return res;
}
