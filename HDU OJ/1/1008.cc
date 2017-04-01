#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n;
    while (input(n) && n) {
        vector<int> ns;
        ns.resize(n + 1);
        ns.push_back(0);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &ns[i]);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int a = ns[i - 1];
            int b = ns[i];

            if (a < b) {
                ans += (b - a) * 6;
            } else {
                ans += (a - b) * 4;
            }
        }
        print(ans + n * 5);
    }
    return 0;
}
