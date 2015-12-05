#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1024;
const int K = 1024000;

int n, m, k, p;
llint sumX[K + 5], sumY[K + 5];
vector<llint> xs, ys;

void do_calc(const vector<llint>& vs, llint sum[], int u)
{
    priority_queue<llint> pq;
    for (auto i: vs) {
        pq.push(i);
    }
    sum[0] = 0;
    for (int i = 1; i <= k; i++) {
        llint now = pq.top();
        pq.pop();
        sum[i] = sum[i - 1] + now;
        now -= (llint)p * u;
        pq.push(now);
    }
}

void calcX()
{
    do_calc(xs, sumX, m);
}

void calcY()
{
    do_calc(ys, sumY, n);
}

int main()
{
    int a;
    freopen("input.txt", "r", stdin);
    input(n >> m >> k >> p);
    ys.resize(m);
    xs.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a);
            ys[j] += a;
            xs[i] += a;
        }
    }

    calcX();
    calcY();

    llint ans = std::numeric_limits<llint>::min();
    for (int i = 0; i <= k; i++) {
        llint t = 0;
        t += sumX[i];
        t += sumY[k - i];
        t -= (llint)i * (k - i) * p;
        ans = max(ans, t);
    }
    print(ans);
    return 0;
}



