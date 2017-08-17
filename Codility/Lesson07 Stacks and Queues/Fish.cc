#include <stack>
#include <queue>
#include <cassert>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int maxi = -1;
    int n = A.size();
    int ans = 0;
    
    maxi = -1;
    for (int i = 0; i < n; i++) {
        if (B[i] == 0 && A[i] > maxi) {
            ans++;
            maxi = -1;
        } else if (B[i] == 1) {
            maxi = max(maxi, A[i]);
        }
    }
    
    maxi = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (B[i] == 1 && A[i] > maxi) {
            ans++;
            maxi = -1;
        } else if (B[i] == 0) {
            maxi = max(maxi, A[i]);
        }
    }
    
    return ans;
}
