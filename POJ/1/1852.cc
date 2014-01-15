// Result: wizmann	1852	Accepted	1248K	141MS	G++	874B	2014-01-15 13:43:27
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int n, m;
vector<int> vec;

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    int a, b;
    int mini, maxi;
    input(T);
    while (T--) {
        scanf("%d%d", &n, &m);
        mini = -INF;
        maxi = -INF;
        vec.clear();
        for (int i = 0; i < m; i++) {
            scanf("%d", &a);
            vec.push_back(a);
        }

        for (int i = 0; i < m; i++) {
            a = vec[i];
            b = n - vec[i];
            //print(a << " " << b);
            mini = max(mini, min(a, b));
            maxi = max(maxi, max(a, b));
        }

        printf("%d %d\n", mini, maxi);
    }
    return 0;
}

