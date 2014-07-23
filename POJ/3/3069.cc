// Result: wizmann  3069    Accepted    748K    16MS    G++ 1076B   2014-06-30 15:15:18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024;
int n, r;
vector<int> vec;

int solve()
{
    int res = 0, p = 0;
    while (p < n) {
        int u = -1, v = -1;
        for (int i = p; i < n; i++) {
            if (vec[i] - vec[p] <= r) {
                u = i;
            } else {
                break;
            }
        }
        for (int i = u; i < n; i++) {
            if (vec[i] - vec[u] <= r) {
                v = i;
            } else {
                break;
            }
        }
        p = v + 1;
        res++;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a;
    while (input(r >> n) && n != -1) {
        vec.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            vec.push_back(a);
        }
        
        sort(vec.begin(), vec.end());
        print(solve());
    }
    return 0;
}


