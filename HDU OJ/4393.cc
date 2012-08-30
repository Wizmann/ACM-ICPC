//Result:2012-08-23 23:53:00	Accepted	4393	484MS	1996K	1680 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128
#define pq priority_queue
#define INF 1<<30

struct player
{
    int fi,si,nr;
    player(){}
    player(int ifi,int isi,int inr)
    {
        fi=ifi;si=isi;nr=inr;
    }
    int getdis(int x)
    {
        return fi+si*x;
    }
    friend bool operator < (const player& a,const player& b)
    {
        if(a.fi!=b.fi) return a.fi<b.fi;
        else return a.nr>b.nr;
    }
};

pq<player> team[SIZE];
player array[50010];

int main()
{
    int ans[50010];
    int T,n,a,b,cas=1;
    input(T);
    while(T--)
    {
        printf("Case #%d:\n",cas++);
        input(n);
        for(int i=0;i<SIZE;i++)
        {
            while(!team[i].empty()) team[i].pop();
        }
        int dis=-INF;
        int ptr=INF;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            array[i]=player(a,b,i);
            if(a>dis)
            {
                dis=a;
                ptr=i;
            }
            else if(a==dis)
            {
                ptr=min(ptr,i);
            }
        }
        ans[0]=ptr;
        for(int i=0;i<n;i++) if(i!=ptr)
        {
            int a=array[i].si;
            team[a].push(array[i]);
        }
        for(int i=1;i<n;i++)
        {
            ptr=INF;
            dis=-INF;
            for(int j=0;j<SIZE;j++) if(!team[j].empty())
            {
                player t=team[j].top();
                int tmp=t.getdis(i);
                if(tmp>dis)
                {
                    dis=tmp;
                    ptr=j;
                }
                else if(tmp==dis)
                {
                    if(ptr!=INF && team[ptr].top().nr>t.nr)
                    {
                        ptr=j;
                    }
                }
            }
            ans[i]=team[ptr].top().nr;
            team[ptr].pop();
        }
        for(int i=0;i<n;i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]+1);
        }
        puts("");
    }
    return 0;
}
