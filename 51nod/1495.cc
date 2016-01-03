#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 10000010;

vector<int> nums;

int n, k, t;
int a, b, c, p;

int sum(int pp, int qq) {
    int u = nums[pp];
    int v = qq - 1 > 0? nums[qq - 1]: 0;
    return u - v;
}

int main() {
    input(n >> k >> t >> a >> b >> c >> p);
    nums.resize(SIZE);

    nums[0] = a;
    for (int i = 1; i <= n; i++) {
        nums[i] = (1LL * nums[i - 1] * b + c) % p;
    }
    
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d ", nums[i]);
    }
    puts("");
    */

    for (int i = 1; i <= n; i++) {
        nums[i] = (nums[i] >= t? 1: 0);
    }

    for (int i = 2; i <= n; i++) {
        nums[i] += nums[i - 1];
    }
    
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d ", nums[i]);
    }
    puts("");
    */
    
    int pp = k;
    int qq = 1;
    llint ans = 0;

    while (pp <= n && qq <= n) {
        bool flag = false;
        while (pp - qq + 1 >= k && sum(pp, qq) >= k) {
            flag = true;
            qq++;
        }
        if (flag) {
            ans += qq - 1;
        }
        pp++;
        qq--;
    }
    print(ans);

    return 0;
}
