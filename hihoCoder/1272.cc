#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n;
vector<pair<int, int> > foods;

int main() {
    int T;
    input(T);
    while (T--) {
        input(n);

        double _a;
        int a;
        int b;
        foods.clear();
        for (int i = 0; i < n; i++) {
            input(_a >> b);
            a = static_cast<int>(_a * 2 + 0.5);
            foods.push_back({a, b});
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int aa = foods[i].first;
            if (aa % 10 == 0) {
                ans = max(ans, foods[i].second);
            }
            for (int j = i + 1; j < n; j++) {
                int bb = aa + foods[j].first;
                if (bb % 10 == 0) {
                    ans = max(ans, foods[i].second + foods[j].second);
                }
                for (int k = j + 1; k < n; k++) {
                    int cc = bb + foods[k].first;
                    if (cc % 10 == 0) {
                        ans = max(ans, foods[i].second + foods[j].second + foods[k].second);
                    }
                }
            }
        }
        print(ans);
    }
    return 0;
}
