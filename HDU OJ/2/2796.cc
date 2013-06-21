//Result:2013-06-02 22:41:59	Accepted	2796	15MS	364K	1457 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 56;
int coin[SIZE];
char visit[SIZE];
int n;

bool judge(int p,int step,int mfill=0)
{
    int i, j;
    for(i=0, j=0;i<p && j<step;i++)
    {
        if(!visit[i] && coin[i]<coin[p])
        {
            if(mfill) visit[i]=1;
            j++;
        }
    }
    if(j==step) return true;
    else return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(input(n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
        }
        memset(visit,0,sizeof(visit));
        sort(coin, coin+n);
        int step = 0, p = 0, pre = 0;
        while(p<n)
        {
            for(int i = 0;i < n; i++)
            {
                if(!visit[i] && coin[i]>pre)
                {
                    p = i;
                    break;
                }
            }
            while(!judge(p,step) && p<n)
            {
                p++;
            }
            if(p<n)
            {
                judge(p,step,1);
                pre=coin[p];
                step++;
                visit[p]=1;
                p++;
            }
            else break;
        }
        print(step);
    }
    return 0;
}

