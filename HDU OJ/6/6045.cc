/*$$$
[Description]
Alice and Bob are answering some questions. 

For each question, there are three answers "A", "B" and "C". 
And it's guaranteed that there are one and only one correct answer for each question.

Alice tell Bob that herself get score X and Bob get score Y. 
But Alice might be telling lies. Could you please find out if Alice is lying or not?

[Tags]
implementation, enumeration

[Difficulty]
3

[Url]
https://vjudge.net/contest/236338#overview
$$$*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

bool solve(int n, int x, int y, const string& sa, const string& sb) {
    if (x > y) {
        swap(x, y);
    }
    int diff = y - x;
    int same = 0;
    for (int i = 0; i < n; i++) {
        same += (sa[i] == sb[i]);
    }

    for (int i = 0; same + 2 * i + diff <= n; i++) {
        int b = i;
        int c = i + diff;

        if (same + b >= x && b <= x && same + c >= y && c <= y) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("a.txt", "r", stdin);

    assert(solve(3, 1, 3, "AAA", "ABC") == true);
    assert(solve(3, 1, 1, "AAA", "ABC") == true);
    assert(solve(3, 1, 2, "AAA", "ABC") == true);
    assert(solve(3, 0, 0, "AAA", "ABC") == true);
    assert(solve(3, 3, 0, "AAA", "ABC") == false);
    assert(solve(3, 3, 3, "AAA", "ABC") == false);
    assert(solve(3, 2, 2, "AAA", "ABC") == true);

    int T;
    int n, x, y;
    string sa, sb;
    input(T);
    while (T--) {
        scanf("%d%d%d", &n, &x, &y);
        input(sa);
        input(sb);

        if (solve(n, x, y, sa, sb)) {
            puts("Not lying");
        } else {
            puts("Lying");
        }
    }
    return 0;
}
