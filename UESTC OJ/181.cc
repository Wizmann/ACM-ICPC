// Result: Wizmann	181	Accepted	1080 KB	7 MS	C++	1015 B	
2015-04-07 23:27:49
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

vector<pair<int, int> > vec;

int main() {
    int n;
    int a, b;
    
    while (input(n)) {
        vec.clear();
        for (int i = 0; i < n; i++) {
            input(a >> b);
            vec.push_back({a, b});
        }
        sort(vec.begin(), vec.end());

        int busy = 0;
        int idle = 0;
        int start = vec.begin()->first, end = vec.begin()->second;
        for (auto& p: vec) {
            a = p.first;
            b = p.second;

            if (a > end) {
                idle = max(idle, a - end);
                start = a;
                end = b;
                busy = max(busy, end - start);
            } else {
                end = max(end, b);
                busy = max(busy, end - start);
            }
        }

        printf("%d %d\n", busy, idle);
    }
    return 0;
}
