#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int MAXI = 1234567 * 2;

int n;
vector<int> vec;
int maxi[MAXI];

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    input(n);
    vec.reserve(n);
    memset(maxi, -1 , sizeof(maxi));
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (maxi[t] != -1) {
            continue;
        }
        vec.push_back(t);
        maxi[t] = t;
    }
    sort(vec.begin(), vec.end());
    int pre = -1, now;
    for (int i = 0; i < MAXI; i++) {
        pre = max(maxi[i], pre);
        maxi[i] = pre;
    }

    int ans = 0;
    for (auto& i: vec) {
        now = 0;
        while (now + i < MAXI) {
            pre = now;
            now += i;
            int u = maxi[now - 1];
            if (u < pre) {
                continue;
            } else if (u > i) {
                ans = max(ans, u % i);
            }
        }
    }
    print(ans);
    return 0;
}
