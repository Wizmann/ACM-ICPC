// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    if (A == 0) {
        return B / K + 1;
    }
    return B / K - (A - 1) / K;
}
