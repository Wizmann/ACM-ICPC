#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5120;
const int INF = 0x3f3f3f3f;

int n;
vector<int> ns;

int solve(int l, int r)
{
    int mini = INF;
    for (int i = l; i <= r; i++) {
        if (ns[i] < mini) {
            mini = ns[i];
        }
    }
    int ans = mini;
    for (int i = l; i <= r; i++) {
        ns[i] -= mini;
    }

    int pre = -1;
    for (int i = l; i <= r; i++) {
        if (pre == -1 && ns[i]) {
            pre = i;
        } 
        if (i == r || !ns[i + 1]) {
            if (pre != -1) {
                ans += solve(pre, i);
                pre = -1;
            }
        }
    }
    return min(ans, r - l + 1);
}

int main()
{
    int a;
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ns.push_back(a);
    }
    print(solve(0, n - 1));
    return 0;
}
