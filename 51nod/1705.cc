#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 7;
const int N = 12345;
const double inf = 1e20;

vector<int> prices;
double prob[SIZE + 10][N];
int lose[SIZE + 10][N];

double ans[SIZE + 10];

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    input(n);

    prices.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &prices[i]);
    }

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lf", &prob[i][j]);
        }
    }

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &lose[i][j]);
            lose[i][j] = i - 1 - lose[i][j];
        }
    }

    ans[0] = 0;
    for (int i = 1; i <= SIZE; i++) {
        ans[i] = inf;
        for (int j = 1; j <= n; j++) {
            if (fabs(prob[i][j]) <= 1e-9) {
                continue;
            }
            if (lose[i][j] == i) {
                continue;
            }
            double u = ans[i - 1] + prices[j] - (1 - prob[i][j]) * ans[lose[i][j]];
            
            ans[i] = min(ans[i], u / prob[i][j]);
        }
    }
    if (ans[SIZE] < inf) {
        printf("%.10lf", ans[SIZE]);
    } else {
        puts("-1");
    }
    return 0;
}
