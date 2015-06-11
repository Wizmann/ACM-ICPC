#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 100001;

struct Bus {
    int tm;
    int prob;
};

int n, s;
vector<Bus> buses;
vector<double> ps;

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int a, b;
    input(T);
    ps.resize(SIZE * 2);
    while (T--) {
        buses.clear();
        input(n >> s);
        for (int i = 0; i < n; i++) {
            input(a >> b);
            buses.push_back({a, b});
        }
        fill(ps.begin(), ps.end(), 0);
        ps[0] = 1;

        for (int i = 0; i < s; i++) {
            for (auto& bus: buses) {
                ps[i + bus.tm] += ps[i] * bus.prob / 100.;
            }
        }

        double expect = 0;
        for (int i = s + 1; i < SIZE * 2; i++) {
            expect += ps[i] * (i - s);
        }
        printf("%.4f\n", expect);
    }
    return 0;
}

