#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define print(x) cout << x << endl
#define input(x) cin >> x
 
typedef long long llint;
 
vector<int> minis;
vector<int> maxis;
vector<pair<int, bool> > ns;
 
const int INF = 0x3f3f3f3f;
 
int main() {
    int n;
    input(n);
 
    int r = 0;
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
 
        int maxi = -INF;
        int mini = INF;
        bool flag = false;
        int a;
        for (int j = 0; j < m; j++) {
            scanf("%d", &a);
            maxi = max(maxi, a);
            mini = min(mini, a);
 
            if (a > mini) {
                // print(j << ' ' << a << ' ' << mini);
                flag = true;
            }
        }
        if (flag == true) {
            r++;
        } else {
            minis.push_back(mini);
            maxis.push_back(maxi);
        }
        ns.push_back({mini, flag});
    }
 
    sort(minis.begin(), minis.end());
    sort(maxis.begin(), maxis.end());
 
    llint tot = 0;
 
    for (int i = 0; i < n; i++) {
        int mini = ns[i].first;
        bool flag = ns[i].second;
 
        if (flag) {
            tot += n;
            continue;
        }
 
        tot += r;
 
        auto iter = upper_bound(maxis.begin(), maxis.end(), mini);
        int d = distance(iter, maxis.end());
        tot += d;
    }
    print(tot);
 
    return 0;
}
