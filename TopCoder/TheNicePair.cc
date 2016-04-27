#include <vector>
using namespace std;
class TheNicePair {
public:
    int solve(vector<int> A) {
        int n = A.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans = max(ans, check(A, i, j));
            }
        }
        if (ans == 0) {
            return -1;
        }
        return ans;
    }
private:
    int check(const vector<int>& A, int a, int b) {
        for (int i = 2; i <= 1000; i++) {
            int cnt = 0;
            for (int j = a; j <= b; j++) {
                if (A[j] % i == 0) {
                    cnt++;
                }
            }
            if (cnt * 2 >= b - a + 1) {
                return b - a;
            }
        }
        return -1;
    }
};
