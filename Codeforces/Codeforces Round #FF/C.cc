#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 123456;
const int INF = 0x3f3f3f3f;

int n;
int nums[SIZE];
int A[SIZE], B[SIZE];

int main()
{
    freopen("c.txt", "r", stdin);
    input(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
    
    A[0] = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] < nums[i]) {
            A[i] = A[i - 1] + 1;
        } else {
            A[i] = 1;
        }
    }
    
    B[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i + 1] > nums[i]) {
            B[i] = B[i + 1] + 1;
        } else {
            B[i] = 1;
        }
    }   
    for (int i = 0; i < n; i++) {
        int l = i - 1 < 0? 0: A[i - 1];
        int r = i + 1 >= n ? 0: B[i + 1];
        int lv = i - 1 < 0? -INF: nums[i - 1];
        int rv = i + 1 >= n ? INF: nums[i + 1];
        if (lv < rv && rv - lv != 1) {
            ans = max(ans, l + r + 1);
        } else {
            ans = max(ans, l + 1);
            ans = max(ans, r + 1);
        }
        // print(i << ' '<< ans);
    }
    print(ans);
    return 0;
}

