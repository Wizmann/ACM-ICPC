//Result: Nov 15, 2013 1:40:21 PM   Wizmann  C - Insertion Sort  GNU C++    Accepted     546 ms  0 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 5120;
const int INF = 0x3f3f3f3f;

inline int lowbit(int x)
{
    return x&(-x);
}

struct BIT//点更新，区间查询
{
    int baum[SIZE];
    inline void init()
    {
        memset(baum,0,sizeof(baum));
    }
    void add(int x,int val)
    {
        while(x<SIZE)
        {
            baum[x]+=val;
            x+=lowbit(x);
        }
    }
    int sum(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=baum[x];
            x-=lowbit(x);
        }
        return res;
    }
    int sum(int a,int b)//查询区间和
    {
        return sum(b)-sum(a-1);
    }
};

int n;
int A[SIZE];

int main()
{
    freopen("input.txt", "r", stdin);
    BIT bit;
    input(n);
    for (int i = 0; i < n; i++) {
        input(A[i]);
        A[i]++;
    }
    int ans = -INF;
    int ans_cnt = -1;
    for (int i = 0; i < n; i++) {
        bit.init();
        bit.add(A[i], 1);
        for (int j = i + 1; j < n; j++) {
            int adv = 0;
            bit.add(A[j], 1);
            adv -= bit.sum(0, A[j] - 1);
            adv += bit.sum(A[j] + 1, n);
            
            adv += bit.sum(0, A[i] - 1);
            adv -= bit.sum(A[i] + 1, n);
            
            if (adv == ans) {
                ans_cnt++;
            } else if (adv > ans) {
                ans = adv;
                ans_cnt = 1;
            }
        }
    }
    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i]) {
                inv++;
            }
        }
    }
    print(inv - ans + 1<< ' ' << ans_cnt);
    return 0;
}
