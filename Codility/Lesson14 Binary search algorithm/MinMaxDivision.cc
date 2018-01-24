// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const int INF = 0x3f3f3f3f;

int solution(int K, int M, vector<int> &A) {
    int l = 0;
    int r = INF;
    
    while (l <= r) {
        int mid = (1LL * l + r) / 2;
        
        int sum = 0;
        int cnt = 0;
        
        for (auto num: A) {
            if (num > mid) {
                cnt = INF;
                break;
            }
            
            sum += num;
            if (sum > mid) {
                sum = num;
                cnt++;
            }
        }
        
        if (sum) {
            cnt++;
        }
        
        if (cnt > K) {
            l = mid + 1;
        } else {
            r = mid - 1;   
        }
    }
    return l;
}
