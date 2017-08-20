// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    int ans = 0;
    for (int i = 1; 1LL * i * i <= N; i++) {
        if (N % i != 0) {
            continue;
        }
        int a = i;
        int b = N / i;
        
        ans += 1 + (a != b);
    }
    return ans;
}
