#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;

int n;

int solve(vector<int> cows, int k) {
    int step = 0;
    for (int i = 1; i + k <= n + 1; i++) {
        if (cows[i] == 1) {
        	cows[i] = 0;
            cows[i + k] ^= 1;
            step++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cows[i] == 1) {
            return INF;
        }
    }
    return step;
}

int main() {
    string cow;
    vector<int> cows;
	while(input(n)) {
        cows.clear();
        cows.resize(n + 5);
        int pre = 0;
        int cur = -1;
        for (int i = 1; i <= n; i++) {
            input(cow);
            cur = (cow[0] == 'F'? 0: 1);
            cows[i] = (pre == cur? 0: 1);
            pre = cur;
        }
        int step = INF;
        int num = -1;
        
        for (int i = 1; i <= n; i++) {
            int step_ = solve(cows, i);
            if (step_ < step) {
                step = step_;
                num = i;
            }
        }
        print(num << ' ' << step);
    }
	return 0;
}
