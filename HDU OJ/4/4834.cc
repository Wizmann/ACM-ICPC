// Result: 2014-05-25 19:56:23  Accepted    4834    3890MS  80204K  1784 B  C++ Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 100010;
const int MAXN = 10000010;

llint dp[MAXN];

struct Query {
    int val;
    int pos;
    llint ans;

    Query(){}
    Query(int ival, int ipos): val(ival), pos(ipos) {}
};

Query query[SIZE];
int n;

int cmpByPos(const Query& a, const Query& b) 
{
    return a.pos < b.pos;
}

int cmpByVal(const Query& a, const Query& b)
{
    return a.val < b.val;
}

llint sumA(int x)
{
    static int ptr = 1;
    static llint sum = 1;
    if (x == 0) {
        return 0;
    }

    ptr += 1;
    for (/*pass*/; ptr <= x; ptr++) {
        // print(ptr << ' ' << sum);
        sum += dp[ptr];
        // print(ptr << ' ' << sum);
    }
    ptr -= 1;
    return sum;
}

void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < MAXN; i += 2) {
        for (int j = 1; (llint)i * j < MAXN; j++) {
            dp[i * j]++;
        }
    }
    for (int i = 1; i < MAXN; i++) {
        dp[i] += dp[i - 1];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int v;
    input(n);
    init();
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        query[i] = Query(v, i);
    }
    sort(query, query + n, cmpByVal);
    for (int i = 1, j = 0; i < MAXN && j < n; i++) {
        llint f = 1 + i + sumA(i - 1);
        while (i == query[j].val) {
            query[j].ans = f;
            j++;
        }
    }
    sort(query, query +n ,cmpByPos);
    for (int i = 0; i < n; i++) {
        printf("Case #%d:\n%I64d\n", i + 1, query[i].ans);
    }
    return 0;
}


