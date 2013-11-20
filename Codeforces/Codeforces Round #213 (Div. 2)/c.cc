#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 4444;

llint a;
int len;
char val[SIZE];
map<llint, int> mp;

int main()
{
    freopen("input.txt", "r", stdin);
    while (input(a)) {
        llint ans = 0;
        input(val);
        len = strlen(val);
        mp.clear();
        int sumall = 0;
        for (int i = 0; i < len; i++) {
            val[i] -= '0';
        }

        for (int i = 1; i <= len; i++) {
            llint t = 0;
            for (int j = 0; j < i; j++) {
                t += val[j];
            }
            mp[t]++;
            sumall++;
            for (int j = i; j < len; j++) {
                t -= val[j - i];
                t += val[j];
                mp[t]++;
                sumall++;
            }
        }
        for (map<llint, int>::iterator iter = mp.begin();
                iter != mp.end();
                ++iter) {
            llint x = iter -> first;
            int y = iter -> second;
            //print(x << ' ' << y);
            if (!x) {
                if (!a) {
                    ans += (llint)sumall * y;
                }
                continue;
            }
            if (a % x == 0) {
                int z = mp[a / x];
                ans += (llint)y * z;
            }
        }
        print(ans);
    }
    
    return 0;
}

