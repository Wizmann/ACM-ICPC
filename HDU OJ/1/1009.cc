#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class Stor {
public:
    int catfood;
    int javabean;

    bool operator < (const Stor& other) const {
        return eval() < other.eval();
    }

    double eval() const {
        return 1.0 * javabean / catfood;
    }
};

int main() {
    int n, m;

    while (input(m >> n) && n != -1 && m != -1) {
        vector<Stor> stors;
        stors.resize(n);

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &stors[i].javabean, &stors[i].catfood);
        }

        sort(stors.begin(), stors.end());

        double ans = 0;
        for (vector<Stor>::reverse_iterator iter = stors.rbegin();
                iter != stors.rend();
                ++iter) {
            if (iter->catfood == 0) {
                ans += iter->javabean;
                continue;
            }
            int acc = min(m, iter->catfood);
            ans += iter->eval() * acc;
            m -= acc;
        }

        printf("%.3lf\n", ans);
    }
    return 0;

};
