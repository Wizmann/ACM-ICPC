// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <unordered_map>
#include <functional>
#include <numeric>

void get_mode(vector<int> &A, int& mode, int& cnt) {
    int pre = -1;
    int k = 0;
    int n = A.size();
    
    for (auto num: A) {
        if (num == pre) {
            k++;
        } else {
            k--;
        }
        if (k <= 0) {
            pre = num;
            k = 1;
        }
    }
    
    cnt = accumulate(A.begin(), A.end(), 0, [&](const int a, const int b) {
        return a + (b == pre);
    });
    
    if (cnt * 2 > n) {
        mode = pre;
    } else {
        cnt = -1;
    }   
}

int solution(vector<int> &A) {
    int n = A.size();
    int mode = -1;
    int cnt = -1;
    
    get_mode(A, mode, cnt);
    
    if (cnt == -1) {
        return 0;
    }
    
    int res = 0;
    int cur = 0;    
    for (int i = 0; i < n; i++) {
        if (A[i] == mode) {
            cur++;
        }
        
        int l = i + 1;
        int r = n - l;
        
        if (cur * 2 > l && (cnt - cur) * 2 > r) {
            res++;
        }
    }
    
    return res;
}
