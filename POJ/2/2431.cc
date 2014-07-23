//Result: wizmann   2431    Accepted    860K    32MS    G++ 1337B   2014-06-30 22:24:23
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 12345;

struct Station {
    int pos, fuel;
    Station(){}
    Station(int ipos, int ifuel): pos(ipos), fuel(ifuel) {}
    friend bool operator < (const Station& a, const Station& b)
    {
        return a.pos < b.pos;
    }
};

Station gas[SIZE];
int n, L, P;

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    input(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        gas[i] = Station(a, b);
    }
    input(L >> P);
    for (int i = 1; i <= n; i++) {
        gas[i].pos = L - gas[i].pos;
    }

    gas[0] = Station(0, P);
    n++;
    gas[n] = Station(L, 0);
    n++;
    sort(gas, gas + n);

    int now = 0, ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i + 1 < n; i++) {
        pq.push(gas[i].fuel);
        now -= gas[i + 1].pos - gas[i].pos;
        while (now < 0 && !pq.empty()) {
            now += pq.top();
            pq.pop();
            ans++;
        }
        if (now < 0) {
            break;
        }
    }
    if (now >= 0) {
        print(--ans);
    } else {
        print(-1);
    }
    return 0;
}





