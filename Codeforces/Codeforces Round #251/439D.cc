#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int MAXN = 1000000001;
const int SIZE = 123456;

int n, m;
vector<int> A[2];

llint tri(llint val) {
    llint step = 0;
    for (int i = 0; i < 2; i++) {
        for (auto iter = A[i].begin(); iter != A[i].end(); ++iter) {
            int u = *iter;
            if (i == 0 && u < val) {
                step += val - u;
            }
            if (i == 1 && u > val) {
                step += u - val;
            }
        }
    }
    return step;
}

llint solve()
{
    llint l = 0, r = MAXN;
    while (l < r) {
        llint lt = (l + r) / 2;
        llint rt = (lt + r) / 2;
        llint ltVal = tri(lt);
        llint rtVal = tri(rt);
        if (ltVal <= rtVal) {
            r = rt;
        } else {
            l = lt;
        }
    }
    return tri(l + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a;
    while (input(n >> m)) {
        for (int i = 0; i < 2; i++) {
            A[i].clear();
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            A[0].push_back(a);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &a);
            A[1].push_back(a);
        }
        print(solve());
    }
    return 0;
}

