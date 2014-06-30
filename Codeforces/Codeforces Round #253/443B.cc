#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

string str;
int k;

int main()
{
    freopen("input.txt", "r", stdin);
    input(str >> k);
    for (int i = 0; i < k; i++) {
        str += '?';
    }
    int len = str.length();

    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '?') {
            break;
        }
        for (int j = 1; i + j < len; j += 2) {
            int slip = (j + 1) / 2;
            for (int k = 0; k < slip; k++) {
                if (str[i + k] == str[i + k + slip] || str[i + k + slip] == '?') {
                    /* pass */;
                }
                else {
                    goto fail;
                }
            }
            ans = max(ans, j + 1);
fail:       /*pass*/;
        }
    }
    print(ans);
    return 0;
}
