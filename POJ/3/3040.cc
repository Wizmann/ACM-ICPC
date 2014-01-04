//Result: wizmann   3040    Accepted    744K    313MS   G++ 1709B   2013-12-20 17:10:17
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Coin {
    int val, num;
    Coin(){}
    Coin(int ival, int inum): \
            val(ival), num(inum) {}

    bool operator > (const Coin& x) const {
        return val > x.val;
    }
    
    
};

int n, c;
vector<Coin> coins;

int solve()
{
    int res = 0;
    while (true) {
        int t = c;
        if (coins[0].val >= t && coins[0].num) {
            coins[0].num--;
        } else {
            for (int i = 0; i < n; i++) {
                while (t > 0 && coins[i].num) {
                    if (t >= coins[i].val) {
                        t -= coins[i].val;
                        coins[i].num--;
                    } else {
                        break;
                    }
                }
            }
            if (t > 0) {
                for (int i = n - 1; i >= 0; i--) {
                    while (t > 0 && coins[i].num) {
                        t -= coins[i].val;
                        coins[i].num--;
                    }
                }
                if (t > 0) break;
            }
        }
        res++;
        
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    while (input(n >> c)) {
        coins = vector<Coin>();
        for (int i = 0; i < n; i++) {
            input(a >> b);
            coins.push_back(Coin(a, b));
        }
        sort(coins.begin(), coins.end(), greater<Coin>());
        print(solve());
    }
    return 0;
}

