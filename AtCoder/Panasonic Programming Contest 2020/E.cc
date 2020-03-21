// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_e

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 2020;
const int OFFSET = N * 5;

char buffer[N];

bool match(char a, char b) {
    return (a == '?' || b == '?' || a == b);
}

void find_diff(vector<bool>& diff, const string& A, const string& B) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (!match(A[i], B[j])) {
                assert(i - j + OFFSET >= 0);
                diff[i - j + OFFSET] = false;
            }
        }
    }
}

int main() {
    string A, B, C;

    scanf("%s", buffer);
    A = string(buffer);
    scanf("%s", buffer);
    B = string(buffer);
    scanf("%s", buffer);
    C = string(buffer);

    vector<bool> diff_ab(OFFSET * 2, true);
    vector<bool> diff_bc(OFFSET * 2, true);
    vector<bool> diff_ac(OFFSET * 2, true);
    find_diff(diff_ab, A, B);
    find_diff(diff_ac, A, C);
    find_diff(diff_bc, B, C);

    int ans = A.size() + B.size() + C.size();
    for (int i = -N * 2; i <= N * 2; i++) {
        for (int j = -N * 2; j <= N * 2; j++) {
            assert(i + OFFSET >= 0 && i + OFFSET < diff_ab.size());
            assert(j + OFFSET >= 0 && j + OFFSET < diff_ac.size());
            assert(j - i + OFFSET >= 0 && j - i + OFFSET < diff_bc.size());
            if (diff_ab[i + OFFSET] && diff_ac[j + OFFSET] && diff_bc[j - i + OFFSET]) {
                int L = min(0, min(i, j));
                int R = max(int(A.size()), max(int(B.size()) + i, int(C.size()) + j));
                // print(i << ' ' << j << ' ' << L << ' ' << R << " " << R - L);
                ans = min(ans, R - L);
            }
        }
    }
    print(ans);
    return 0;
}
