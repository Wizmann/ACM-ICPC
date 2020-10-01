#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
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

int main() {
    int n, w, s;
    input(n, w, s);

    vector<int> ns(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    vector<llint> dp[2];
    dp[0] = vector<llint>(n + 1, -INFLL);
    dp[1] = vector<llint>(n + 1, -INFLL);

    int p = 0;
    dp[p][0] = 0;

    for (int i = 1; i <= n; i++) {
        int q = p ^ 1;
        dp[q] = vector<llint>(n + 1, -INFLL);

        for (int j = 0; j + 1 <= min(w, i); j++) {
            dp[q][j + 1] = max(dp[q][j + 1], dp[p][j] + 1LL * (j + 1) * ns[i]);
        }

        deque<int> dq;
        for (int j = min(w, i); j >= 1; j--) {
            while (!dq.empty() && dq.back() - j > s - 1) {
                dq.pop_back();
            }
            while (!dq.empty() && dp[p][dq.front()] < dp[p][j]) {
                dq.pop_front();
            }
            dq.push_front(j);
            llint maxi = dq.empty()? -INF: dp[p][dq.back()];
            dp[q][j] = max(dp[q][j], maxi + 1LL * j * ns[i]);
        }
        /*
        for (int j = 0; j <= n; j++) {
            printf("%lld ", dp[q][j]);
        }
        puts("");
        */
        p = q;
    }

    llint ans = -INFLL;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[p][i]);
    }
    print(ans);
    return 0;
}

/*
^^^TEST^^^
1 1 1
1
---
1
$$$TEST$$$

^^^TEST^^^
5 3 3
1 3 2 4 5
---
40
$$$TEST$$$

^^^TEST^^^
5 3 3
1 -3 -2 4 5
---
21
$$$TEST$$$

^^^TEST^^^
7 4 2
-5 3 -1 -4 7 -6 5
---
17
$$$TEST$$$

^^^TEST^^^
5 3 1
-1 -3 -2 -4 -5
---
-15
$$$TEST$$$

^^^TEST^^^
279 160 3
-1681 -1933 5787 -6575 872 -2488 7988 -2248 -4915 291 -4155 2055 -4750 2811 2830 1748 565 -1367 3154 6422 7703 -8557 -8833 -4522 3186 1390 -5828 -3235 -1585 1693 -4147 1384 -2225 7888 -4968 8386 -5386 -3556 7041 -4635 8380 6108 5776 7356 -6463 -1538 -9304 9607 5709 9777 8881 5693 390 3614 7053 3279 -313 1217 5555 -8562 -9327 2697 3697 -8384 2955 4826 9254 -3221 -5 8929 -4726 3301 4433 -8927 5929 -3024 5610 -3931 2996 2933 -6947 -2193 6182 2057 -5975 -3778 -7201 8616 -8168 -632 -9465 9452 5169 -1729 7900 -524 272 6641 -8340 -9542 9368 -1582 -4476 4385 -1040 -2985 8821 1949 -8161 9318 307 5576 5953 3565 2261 -515 -4333 -3623 3597 -3325 -1329 -8378 1469 -7254 7389 4728 -126 -8314 -4185 -9596 -930 6155 -2565 3577 -9142 6105 2790 -7688 8745 -8659 1970 5668 1290 4265 1787 1973 -9505 -4889 5944 -7986 -4738 4390 6534 7214 -8614 1686 -8852 -3365 6570 -9256 -9729 -3316 1418 5334 -4110 3380 -6286 9885 -1154 6537 -1515 8534 3933 995 1816 2523 -9811 4383 -7355 9238 -1342 8881 -3919 3613 -6998 -4068 -2117 6346 4255 -7753 -2703 -7584 -6178 -8430 5941 -563 1994 1882 9716 -3157 -7576 -1849 -3316 -7139 6096 2796 -4642 2810 -7834 -3611 -7457 1857 -7951 1485 -9872 5723 -5304 3437 -9059 -1231 7052 -9833 -4505 384 -2820 507 3845 -3559 5394 6655 -4374 1095 8475 -7183 -8439 -4825 8682 -7817 1761 -9011 -2463 -7891 -5987 -1776 -3644 6403 5526 -9789 7379 6729 -5859 1224 -9503 3693 1702 7975 5878 -3225 -7047 -9474 6926 1679 -3584 -8249 -1441 618 -9140 467 6717 -5842 -9844 8331 -9133 -301 -4989 8859 -1457 -2200 3012 
---
4736002
$$$TEST$$$

*/
