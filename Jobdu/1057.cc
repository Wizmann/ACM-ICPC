#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int x;
    while (true) {
        int cnt = 0;
        map<int, int> mp;
        for (int i = 0; i < 20; i++) {
            if (scanf("%d", &x) == EOF) {
                break;
            }
            cnt++;
            mp[x]++;
        }

        if (cnt != 20) {
            break;
        }

        int ans = -1;
        int maxi = 0;
        for (int i = 0; i < 50; i++) {
            int v = mp[i];
            if (v > maxi) {
                maxi = v;
                ans = i;
            }
        }
        print(ans);
    }
    return 0;
}
