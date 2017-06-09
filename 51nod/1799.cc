#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint MOD = 1000000007;
const llint MAG = 10000000;

const int FAC[] = {1, 682498929, 491101308, 76479948, 723816384, 67347853, 27368307, 625544428, 199888908, 888050723, 927880474, 281863274, 661224977, 623534362, 970055531, 261384175, 195888993, 66404266, 547665832, 109838563, 933245637, 724691727, 368925948, 268838846, 136026497, 112390913, 135498044, 217544623, 419363534, 500780548, 668123525, 128487469, 30977140, 522049725, 309058615, 386027524, 189239124, 148528617, 940567523, 917084264, 429277690, 996164327, 358655417, 568392357, 780072518, 462639908, 275105629, 909210595, 99199382, 703397904, 733333339, 97830135, 608823837, 256141983, 141827977, 696628828, 637939935, 811575797, 848924691, 131772368, 724464507, 272814771, 326159309, 456152084, 903466878, 92255682, 769795511, 373745190, 606241871, 825871994, 957939114, 435887178, 852304035, 663307737, 375297772, 217598709, 624148346, 671734977, 624500515, 748510389, 203191898, 423951674, 629786193, 672850561, 814362881, 823845496, 116667533, 256473217, 627655552, 245795606, 586445753, 172114298, 193781724, 778983779, 83868974, 315103615, 965785236, 492741665, 377329025, 847549272, 698611116};

llint fac(llint x)
{
    if (x == 0)
    {
        return 1;
    }
    llint res = FAC[x / MAG];
    for (llint i = x / MAG * MAG + 1; i <= x; i++)
    {
        res = (res * i) % MOD;
    }
    return res;
}

class Solution {
public:
    Solution(int n_, int m_, int k_): 
            n(n_), m(m_), k(k_) {
        // pass
    }

    llint solve() {
        int lt = 0;
        int gt = 0;

        llint l = 1;
        llint r = n;
        while (l <= r) {
            llint mid = (l + r) >> 1;

            if (mid > k) {
                gt++;
                r = mid - 1;
            } else {
                lt++;
                l = mid + 1;
            }
        }

        llint res = 1;
        for (int i = m - lt + 1; i <= m; i++) {
            res = (res * i) % MOD;
        }

        for (int i = n - m - gt + 1; i <= n - m; i++) {
            res = (res * i) % MOD;
        }

        res = (res * fac(n - lt - gt)) % MOD;
        return res;
    }
private:
    int n, m, k;
};

int main() {
    freopen("input.txt", "r", stdin);
    
    llint n, m, k;
    input(n >> m >> k);
    print(Solution(n, m, k).solve());
    return 0;
}
