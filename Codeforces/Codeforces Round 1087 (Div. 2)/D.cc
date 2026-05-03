#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static inline int upperBoundLen(const array<int, 3>& c) {
    int total = c[0] + c[1] + c[2];
    int mx = max(c[0], max(c[1], c[2]));
    return min(total, 2 * (total - mx) + 1);
}

static string solveOne(int r, int g, int b) {
    array<int, 3> rem = {r, g, b};
    const int target = upperBoundLen(rem);
    if (target == 0) return "";

    string s;
    s.reserve(target);

    // Iterative DFS/backtracking states per depth.
    vector<array<int, 3>> cands(target + 1);
    vector<int> candN(target + 1, 0);
    vector<int> nextIdx(target + 1, -1);  // -1 means uninitialized at this depth.
    vector<int> chosen(target + 1, -1);   // chosen color at depth d (to go d -> d+1).

    int d = 0;
    while (true) {
        if (d == target) {
            return s;
        }

        if (nextIdx[d] == -1) {
            // Build candidates at current depth, trying larger remainder first.
            array<int, 3> ord = {0, 1, 2};
            sort(ord.begin(), ord.end(), [&](int x, int y) {
                if (rem[x] != rem[y]) return rem[x] > rem[y];
                return x < y;
            });

            int n = 0;
            for (int k = 0; k < 3; k++) {
                int c = ord[k];
                if (rem[c] == 0) continue;
                char ch = "RGB"[c];
                if (!s.empty() && s.back() == ch) continue;
                if (d >= 3 && s[d - 3] == ch) continue;

                rem[c]--;
                int need = target - (d + 1);
                if (upperBoundLen(rem) >= need) {
                    cands[d][n++] = c;
                }
                rem[c]++;
            }
            candN[d] = n;
            nextIdx[d] = 0;
        }

        if (nextIdx[d] >= candN[d]) {
            // This depth fails, backtrack.
            nextIdx[d] = -1;
            if (d == 0) {
                // Should not happen because target is achievable, but keep safe fallback.
                return s;
            }
            d--;
            int c = chosen[d];
            rem[c]++;
            s.pop_back();
            continue;
        }

        int c = cands[d][nextIdx[d]++];
        chosen[d] = c;
        rem[c]--;
        s.push_back("RGB"[c]);
        d++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int r, g, b;
        cin >> r >> g >> b;
        cout << solveOne(r, g, b) << '\n';
    }
    return 0;
}
