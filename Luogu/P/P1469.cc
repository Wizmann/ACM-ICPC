#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    int n;
    input(n);

    int res = 0;

    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        res ^= a;
    }
    print(res);

    return 0;
}
/*
^^TEST^^
9
2 2 1 3 3 3 2 3 1
---
2
$$TEST$$

^^TEST^^
1
1
---
1
$$TEST$$

^^TEST^^
3
1 1 2
---
2
$$TEST$$
*/
