//Result: wizmann   1017    Accepted    736K    47MS    G++ 1318B   2013-12-20 18:42:51
#include <cstdio>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 6;

int num[SIZE + 5];

int solve()
{
    int res = 0;
    int s1 = 0, s2 = 0;
    res += num[6];
    
    res += num[5];
    s1 += num[5] * 11;
    
    res += num[4];
    s2 += num[4] * 5;
    
    res += num[3] / 4;
    num[3] %= 4;
    if (num[3]) res++;
    switch (num[3]) {
        case 1: {
            s2 += 5;
            s1 += 7;
        }; break;
        case 2: {
            s2 += 3;
            s1 += 6;
        }; break;
        case 3: {
            s2 += 1;
            s1 += 5;
        }; break;
    }
    if (num[2] > s2) {
        num[2] -= s2;
    } else {
        s2 -= num[2];
        s1 += s2 * 4;
        num[2] = 0;
    }
    
    res += num[2] / 9;
    num[2] %= 9;
    if (num[2]) {
        res++;
        s1 += 36 - 4 * num[2];
    }
    
    num[1] -= s1;
    if (num[1] > 0)
        res += (num[1] + 35) / 36;
        
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a;
    while (true) {
        a = 0;
        for (int i = 1; i <= SIZE; i++) {
            input(num[i]);
            a += num[i];
        }
        if (!a) break;
        print(solve());
    }
    return 0;
}
