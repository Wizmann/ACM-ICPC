#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 256;

int n, k;
vector<int> ns;
vector<int> nr;

int main() {
    input(n >> k);
    ns.resize(n);

    nr = vector<int>(SIZE, -1);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    for (int i = 0; i < n; i++) {
        int cur = ns[i];
        if (nr[cur] != -1) {
            ns[i] = nr[cur];
            continue;
        }

        int pre = -1;
        for (int j = max(0, cur - k + 1); j <= cur; j++) {
            if (nr[j] == -1) {
                pre = j;
                break;
            } else {
                if (cur - nr[j] < k) {
                    pre = j;
                    break;
                }
            }
        }

        for (int j = pre; j <= cur; j++) {
            nr[j] = pre;
        }

        ns[i] = nr[cur];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ns[i]);
    }
    puts("");

    return 0;
}
