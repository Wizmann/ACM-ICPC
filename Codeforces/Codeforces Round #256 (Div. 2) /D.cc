#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const llint SIZE = 512345;
llint n, m, k;

llint do_count(llint v, llint c)
{
    if (v % c == 0) {
        return v / c - 1;
    } else {
        return v / c;
    }
}

llint count(llint v)
{
    llint res = 0;
    for (int i = 1; i <= m; i++) {
        res += min(n, do_count(v, i));
    }
    return res;
}

int main()
{
    freopen("d.txt", "r", stdin);
    input(n >> m >> k);
    llint l = 0, r = n * m;
    while (l <= r) {
        llint mid = (l + r) >> 1;
        if (count(mid) < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    print (r);
    return 0;
}

