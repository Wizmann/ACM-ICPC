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

const int SIZE = 1024 + 233;

int n;
vector<int> vec;

int main() {
    int T, a, cas = 1;
    input(T);

    while (T--) {
        input(n);
        vec.clear();
        for (int i = 0; i < n; i++) {
            input(a);
            vec.push_back(a);
        }

        int ans = SIZE * 233;
        for (int i = 1; i <= SIZE; i++) {
            int step = 0;
            int maxi = 0;
            for (const auto& num: vec) {
                if (num > i) {
                    step += num % i? num / i: num / i - 1;
                    maxi = i;
                } else {
                    maxi = max(maxi, num);
                }
            }
            ans = min(ans, step + maxi);
        }
            
                
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
