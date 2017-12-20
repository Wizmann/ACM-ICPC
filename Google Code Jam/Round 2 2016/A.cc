#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const string IMPOSSIBLE = "ZZZ";

const char moves[] = {'P', 'R', 'S'};
int rem[3];

string gen(int n, int winner) {
    if (n == 1) {
        rem[winner]--;
        return string() + moves[winner];
    }

    string w = gen(n / 2, winner);
    string l = gen(n / 2, (winner + 1) % 3);

    return min(w + l, l + w);
}

string solve(int r, int p, int s) {
    string best = IMPOSSIBLE;
    for (int i = 0; i < 3; i++) {
        rem[0] = p;
        rem[1] = r;
        rem[2] = s;

        string cur = gen(r + p + s, i);
        if (rem[0] == 0 && rem[1] == 0 && rem[2] == 0) {
            best = min(best, cur);
        }
    }
    return best;
}

int main() {
    // freopen("input.txt", "r", stdin);
    
    int T;
    int n, r, p, s;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        printf("Case #%d: ", case_ + 1);
        input(n >> r >> p >> s);

        string ss = solve(r, p, s);

        if (ss == IMPOSSIBLE) {
            print("IMPOSSIBLE");
        } else {
            print(ss);
        }
    }
    return 0;
}
