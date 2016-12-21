// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int solution(int N) {
    int ans = 0;
    int pre = -1;
    int cur = 0;
    while (N) {
        int x = N & 1;
        N >>= 1;
        
        if (x == 1) {
            if (pre != -1) {
                ans = max(ans, cur - pre - 1);
            }
            pre = cur;
        }
        cur++;
    }
    return ans;
}
