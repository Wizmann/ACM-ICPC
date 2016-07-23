// Result: 2016-07-23 15:45:38	Accepted	1850	0MS	1608K	811B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define loop(i, n) for (int i = 0; i < n; i++) 

const int SIZE = 1000110;

int main() {
    int n;
    while (input(n) && n) {
        int res = 0;
        vector<int> ns(n, 0);
        loop(i, n) {
            scanf("%d", &ns[i]);
            res ^= ns[i];
        }
        if (res == 0) {
            puts("0");
        } else {
            int cnt = 0;
            loop(i, n) {
                int cur = ns[i] ^ res;
                if (ns[i] >= cur) {
                    cnt++;
                }
            }
            print(cnt);
        }
    }
    return 0;
}
