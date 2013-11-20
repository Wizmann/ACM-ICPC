#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int prime[15] = {2, 3, 5, 7, 11,
                     13, 17, 19, 23, 29,
                     31, 37, 41, 43, 47};
                    

int main()
{
    int n;
    input(n);
    vector<int> res;
    int limit = 2 * n * n;

    for (int i = 0; i < 15; i++) {
        res.clear();
        res.push_back(1);
        for (int j = 0; j <= i; j++) {
            int p = prime[j];
            int sz = res.size();
            for (int k = 0; k < sz; k++) {
                int x = res[k];
                while (x * p <= limit) {
                    x *= p;
                    res.push_back(x);
                }
            }
        }
        if (res.size() >= n) {
            break;
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", res[i]);
    }
    puts("");
    return 0;
}
