// Result: 2013-12-19 20:23:15  Accepted    2570    0MS 372K    1079 B  G++ Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 128;

int n, v, w;
vector<int> med;

int main()
{
    int T, x;
    input(T);
    while (T--) {
        input(n >> v >> w);
        med = vector<int>();
        for (int i = 0; i < n; i++) {
            input(x);
            med.push_back(x);
        }
        sort(med.begin(), med.end());

        int cnt = 0;
        int mm = 0;
        for(int i = 0; i < (int)med.size(); i++) {
            cnt++;
            mm += med[i];

            if ((double)mm / cnt <= w) {
                continue;
            } else {
                cnt--;
                mm -= med[i];
                break;
            }
        }

        if (cnt == 0) {
            puts("0 0.00");
        } else {
            printf("%d %.2lf\n", cnt * v, (double)mm / cnt / 100);
        }
    }
    return 0;
}



