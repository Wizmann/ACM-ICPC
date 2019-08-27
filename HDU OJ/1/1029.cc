#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n;

    while (input(n) && n) {
        vector<int> ns(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }

        int cur = -1;
        int cnt = 0;
        for (auto num: ns) {
            if (num == cur) {
                cnt++;
            } else {
                cnt--;
                if (cnt < 0) {
                    cur = num;
                    cnt = 1;
                }
            }
        }
        printf("%d\n", cur);
    }
    return 0;
}
