// Result: wizmann	2376	Accepted	916K	110MS	G++	936B	2017-07-15 23:14:03
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    freopen("input.txt", "r", stdin);
    int n, t;
    input(n >> t);

    vector<pair<int, int> > cows(n + 1);

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        cows[i] = make_pair(a, min(b, t));
    }
    cows[n] = make_pair(t + 1, t + 1);

    sort(cows.begin(), cows.end());

    int end = 0;
    int next = -1;
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        const pair<int, int>& cow = cows[i];

        if (cow.first <= end + 1) {
            next = max(next, cow.second);
        } else if (next + 1 >= cow.first) {
            cnt++;
            end = next;
            i--;
        } else {
            cnt = -1;
            break;
        }
    }

    print(cnt);
    return 0;
}
