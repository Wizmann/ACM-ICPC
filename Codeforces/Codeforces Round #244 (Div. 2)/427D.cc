#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5120;
const int INF = 1<<28;

char strab[SIZE * 2];
int len;
int lena, lenb;

struct Info {
    int p, minprefix, belong;

    Info(){}
    Info(int ip, int ipre, int ibe):
            p(ip), minprefix(ipre), belong(ibe){}

    bool operator < (const Info& info) const
    {
        return strcmp(strab + p, strab + info.p) < 0;
    }
};

vector<Info> infovec;

void calc_min_prefix(int a, int b)
{
    Info& infoa = infovec[a];
    Info& infob = infovec[b];
    for (int i = 0; /* pass */; i++) {
        int aa = infoa.p + i;
        int bb = infob.p + i;

        if (strab[aa] != strab[bb]) {
            infoa.minprefix = max(infoa.minprefix, i);
            infob.minprefix = max(infob.minprefix, i);
            break;
        }
    }
}

void scan(int flag)
{
    int pre = -1;
    for (int i = 0; i < (int)infovec.size(); i++) {
        Info& info = infovec[i];
        if (info.belong != flag) {
            continue;
        }

        if (pre != -1) {
            calc_min_prefix(pre, i);
        }
        pre = i;
    }
}

int calc_prefix_len(int a, int b)
{
    int res = 0;
    while (1) {
        if (strab[a] == strab[b]) {
            res++;
        } else {
            break;
        }
        a++; b++;
    }
    return res;
}

int solve()
{
    int ans = INF;
    int sz = infovec.size();
    for (int i = 1; i < sz; i++) {
        Info& infoa = infovec[i - 1];
        Info& infob = infovec[i];

        if (infoa.belong == infob.belong) {
            continue;
        }
        int prefix = calc_prefix_len(infoa.p, infob.p);
        if (prefix > max(infoa.minprefix, infob.minprefix)) {
            /*
            print(strab + infoa.p);
            print(strab + infob.p);
            print( max(infoa.minprefix, infob.minprefix) + 1);
            print("---");
            */
            ans = min(ans, max(infoa.minprefix, infob.minprefix) + 1);
        }
    }
    if (ans == INF) {
        ans = -1;
    }
    return ans;
}
        

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%s", strab);
    lena = strlen(strab);
    strab[lena] = '#';
    scanf("%s", strab + lena + 1);
    lenb = strlen(strab) - lena - 1;
    len = strlen(strab);

    for (int i = 0; i < len; i++) {
        if (i == lena) {
            continue;
        }
        int flag = i < lena? 0 : 1;
        infovec.push_back(Info(i, 0, flag));
    }
    sort(infovec.begin(), infovec.end());
    /*
    for (auto iter = infovec.begin(); iter != infovec.end(); ++iter) {
        print(strab + iter -> p);
    }
    print("---");
    */
    scan(0); scan(1);
    print(solve());
    return 0;
}
