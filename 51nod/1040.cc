#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;

int euler(int n) {
     int res = n;
     int a = n;

     for(int i = 2; i * i <= a; ++i) {
         if(a % i == 0) {
             res -= res / i;
             while (a % i == 0) {
                 a /= i;
             }
         }
     }

     if (a > 1) {
         res -= res / a;
     }
     return res;
}

int main() {
    int n;
    input(n);
    llint ans = 0;
    set<int> factors;

    for (llint i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int a = i;
            int b = n / i;
            if (factors.count(a) == 0) {
                ans += b * euler(a);
            }
            factors.insert(a);

            if (factors.count(b) == 0) {
                ans += a * euler(b);
            }
            factors.insert(b);
        }
    }
    print(ans);

    return 0;
}
