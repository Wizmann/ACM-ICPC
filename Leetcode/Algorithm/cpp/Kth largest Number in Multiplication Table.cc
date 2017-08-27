#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;


class Solution {
public:
    int findKthNumber(int n, int m, int k) {
        int l = 1;
        int r = n * m;
        
        while (l <= r) {
            int mid = (1LL * l + r) / 2;
            int cnt = count(n, m, mid);
            //print(n << ' ' << m << ' ' << mid << ' ' << cnt);
            
            if (cnt >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
private:
    int count(int n, int m, int v) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += min(m, v / i);
        }
        return res;
    }
};

int main() {
    auto S = Solution();
    
    assert(S.findKthNumber(2, 3, 6) == 6);
    assert(S.findKthNumber(2, 3, 1) == 1);
    assert(S.findKthNumber(2, 3, 2) == 2);
    assert(S.findKthNumber(2, 3, 3) == 2);
    assert(S.findKthNumber(2, 3, 4) == 3);
    assert(S.findKthNumber(3, 3, 5) == 3);
    
    return 0;
}
