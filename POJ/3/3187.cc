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

int n, s;

bool solve(const vector<int>& perm, const vector<int>& ns) {
    int ss = 0;
    for (int i = 0; i < n; i++) {
        ss += perm[i] * ns[i];
    }
    return ss == s;
}

int main() {
    freopen("input.txt", "r", stdin);
    input(n >> s);
    vector<int> ns;

    int x = 1;
    ns.resize(n);
    ns[0] = 1;
    for (int i = 1; i < n; i++) {
        x *= n - i;
        x /= i;
        ns[i] = x;
    }

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    do {
        if (solve(perm, ns)) {
            break;
        }
    } while (next_permutation(perm.begin(), perm.end()));


    for (int i = 0; i < n; i++) {
        if (i) {
            putchar(' ');
        }
        printf("%d", perm[i]);
    }

    puts("");

    return 0;
}
