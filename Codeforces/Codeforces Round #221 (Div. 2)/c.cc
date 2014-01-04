//Result: Dec 24, 2013 7:48:42 PM   Wizmann  C - Divisible by Seven  GNU C++    Accepted     140 ms  1000 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1001000;

int g[12];
char buffer[SIZE];

int main()
{
    freopen("input.txt", "r", stdin);
    while (scanf("%s", buffer) != EOF) {
        memset(g, 0, sizeof(g));
        int all = 0;
        for (int i = 0; buffer[i]; i++) {
            int t = buffer[i] - '0';
            g[t]++;
            all++;
        }
        g[1]--;
        g[6]--;
        g[8]--;
        g[9]--;
        
        all -= 4;
        
        if (all == g[0]) {
            printf("1869");
            for (int i = 0; i < all; i++) {
                printf("0");
            }
            puts("");
        } else {
            int mod = 0;
            for (int i = 1; i <= 10; i++) {
                int ii = i % 10;
                for (int j = 0; j < g[ii]; j++) {
                    printf("%d", ii);
                    mod = mod * 10 + ii;
                    mod %= 7;
                }
            }
            mod *= 10000;
            mod %= 7;
            mod = (7 - mod)% 7;
            switch(mod) {
                case 0:
                    printf("1869");
                    break;
                case 1:
                    printf("6819");
                    break;
                case 2:
                    printf("6918");
                    break;
                case 3:
                    printf("6891");
                    break;
                case 4:
                    printf("8691");
                    break;
                case 5:
                    printf("1986");
                    break;
                case 6:
                    printf("8196");
                    break;
            }
            puts("");
        }
    }
    return 0;
}
    
