#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

#define mpii(a, b) make_pair<llint, llint>(llint(a), llint(b)) 
typedef pair<llint, llint> pii;


const int SIZE = 128;
enum{A = 0, B, C};

char dp[SIZE + 5][SIZE + 5][3][3];

int k, x, n, m;

void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
    for (int x = A; x <= C; x++)
    for (int y = A; y <= C; y++) 
    {
        if (i <= 2) {
            dp[i][j][x][y] = (j == (int)(i == 2 && x == A && y == C));
            continue;
        }
        for (int z = A; z <= C; z++) {
            int prej = j - (x == A && z == C ? 1 : 0);
            if (prej >= 0) {
                dp[i][j][x][y] |= dp[i - 1][prej][z][y];
            }
        }
    }
}

void mkString(int len, int v, int head, int tail, string& ss)
{
    if (len == 1) {
        ss = ss + char('A' + head);
        return;
    }
    if (len == 2) {
        ss = ss + char('A' + head) + char('A' + tail);
        return;
    }
    for (int i = A; i <= C; i++) {
        int nextv = v;
        if (head == A && i == C) {
            nextv = v - 1;
        }
        if (dp[len - 1][nextv][i][tail]) {
            ss += 'A' + head;
            mkString(len - 1, nextv, i, tail, ss);
            return;
        }
    }
}
        

bool solve(llint sum, llint a, llint b, int head1, int tail1, int head2, int tail2)
{
    int rx = x - sum;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i * a + j * b != rx) continue;
            if (!dp[n][i][head1][tail1] || !dp[m][j][head2][tail2]) {
                continue;
            }
            string aa;
            string bb;
            aa = bb = "";
            mkString(n, i, head1, tail1, aa);
            mkString(m, j, head2, tail2, bb);
            print(aa);
            print(bb);            
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    init();
    while (input(k >> x >> n >> m)) {
        for (int head1 = A; head1 <= C; head1++)
        for (int tail1 = A; tail1 <= C; tail1++)
        for (int head2 = A; head2 <= C; head2++)
        for (int tail2 = A; tail2 <= C; tail2++) {
            if (n < 2 && head1 != tail1) continue;
            if (m < 2 && head2 != tail2) continue;
            pii a = mpii(head1, tail1);
            pii b = mpii(head2, tail2);
            pii cnta = mpii(1, 0);
            pii cntb = mpii(0, 1);
            llint suma = 0, sumb = 0;
            for (int i = 3; i <= k; i++) {
                pii c = mpii(a.first, b.second);
                llint sumc = suma + sumb;
                if (a.second == A && b.first == C) sumc++;
                pii cntc = mpii(cnta.first + cntb.first, 
                        cnta.second + cntb.second);
                a = b;
                b = c;
                cnta = cntb;
                cntb = cntc;
                suma = sumb;
                sumb = sumc;
            }
            bool flag = solve(sumb, cntb.first, cntb.second, head1, tail1, head2, tail2);
            if (flag) {
                goto END_LINE;
            }
        }
        print("Happy new year!");
END_LINE: /*pass*/;
    }
    
    return 0;
}
