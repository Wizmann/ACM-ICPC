#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

class Manacher {
public:
    Manacher(const string& origin_) : origin(origin_) {
        int n = origin.size();
        for (int i = 0; i < n; i++) {
            s += '#';
            s += origin[i];
        }

        s += '#';
        n = s.size();

        d = vector<int>(n, 0);

        for (int i = 0, j = 1, k; i < n; /* pass */) {
            while (i - j >= 0 && i + j < n &&
                   s[i-j] == s[i+j]) {
                j++;
            }
            d[i] = j - 1;
            k = 1;
            while (k <= d[i] && d[i] - k != d[i - k]) {
                d[i + k] = min(d[i - k], d[i] - k);
                k++;
            }
            i += k;
            j = max(j - k, 0);
        }
    }

    int LongestPalindrome() const {
        int maxi = 1;
        for (auto num : d) {
            maxi = max(maxi, num);
        }
        return maxi;
    }

    int LongestOddLenPalindrome(int pivot) const {
        int idx = pivot * 2 + 1;
        int left = idx / 2 - d[idx] / 2;
        int right = left + d[idx] - 1;
        return right - left + 1;
    }

    int LongestEvenLenPalindrome(int pivot) const {
        int idx = pivot * 2 ;
        int left = idx / 2 - d[idx] / 2;
        int right = left + d[idx] - 1;
        return right - left + 1;
    }

    int LongestPalindrome(int pivot) const {
        return max(LongestOddLenPalindrome(pivot),
                   LongestEvenLenPalindrome(pivot));
    }

private:
    string origin;
    string s;
    vector<int> d;
};

int solve(const string& str) {
    Manacher m(str);
    int n = str.size();

    vector<int> dps(n, 0);
    vector<int> dpe(n, 0);

    for (int i = 0; i < n; i++) {
        int len = m.LongestOddLenPalindrome(i);
        int left = i - len / 2;
        int right = left + len - 1;

        dps[left] = max(dps[left], len);
        dpe[right] = max(dpe[right], len);
    }

    for (int i = 0; i < n; i++) {
        int len = m.LongestEvenLenPalindrome(i);
        int left = i - len / 2;
        int right = left + len - 1;

        dps[left] = max(dps[left], len);
        dpe[right] = max(dpe[right], len);
    }

    /*
    for (int i = 0; i < n; i++) {
        printf("%d ", dps[i]);
    }
    puts("");

    for (int i = 0; i < n; i++) {
        printf("%d ", dpe[i]);
    }
    puts("");
    */

    int cur = 0;

    cur = -INF;
    for (int i = 0; i < n; i++) {
        dps[i] = max(dps[i], cur - 2);
        cur = dps[i];
    }

    cur = -INF;
    for (int i = n - 1; i >= 0; i--) {
        dpe[i] = max(dpe[i], cur - 2);
        cur = dpe[i];
    }

    /*
    for (int i = 0; i < n; i++) {
        printf("%d ", dps2[i]);
    }
    puts("");

    for (int i = 0; i < n; i++) {
        printf("%d ", dpe2[i]);
    }
    puts("");
    */

    int ans = 2;
    for (int i = 1; i < n; i++) {
        ans = max(ans, dpe[i - 1] + dps[i]);
    }
    return ans;
}

int main() {
    string s;
    input(s);

    print(solve(s));

    return 0;
}

/*

^^^TEST^^^
baacaabbacabb
-----
12
$$$TEST$$$

^^^TEST^^^
aa
-----
2
$$$TEST$$$

^^^TEST^^^
ab
-----
2
$$$TEST$$$

^^^TEST^^^
abacc
-----
5
$$$TEST$$$

^^^TEST^^^
xbabaccay
-----
7
$$$TEST$$$

^^^TEST^^^
xcaacx
-----
5
$$$TEST$$$

^^^TEST^^^
xcaacy
-----
5
$$$TEST$$$

^^^TEST^^^
axyzzyxxyza
-----
7
$$$TEST$$$

*/
