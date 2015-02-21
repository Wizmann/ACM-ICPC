//Result:wizmann    1699    Accepted    732K    469MS   G++ 1738B   2012-07-25 20:00:55
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
const int SIZE=12;
const int INF=1<<30;

struct node
{
    int dest,val;
    node(){}
    node(int i_dest,int i_val)
    {
        dest=i_dest;val=i_val;
    }
};

char dna[SIZE][24];
vector<node> g[SIZE];
int next[SIZE][24];
char visit[SIZE];

int n;

void kmp_get_next(int nr)
{
    int len=strlen(dna[nr]);
    next[nr][0]=-1;
    for(int i=0,j=-1;i<len;i++,j++,next[nr][i]=j)
    {
        while(j>=0 and dna[nr][i]!=dna[nr][j]) j=next[nr][j];
    }
}


int kmp_do(int a,int b)
{
    int i=0,j=0;
    int la=strlen(dna[a]);
    int lb=strlen(dna[b]);
    while(i<la) //<- This is the WA point
    {
        if(j==-1 or dna[a][i]==dna[b][j])
        {
            i++;j++;
        }
        else j=next[b][j];
    }
    /* 如果采用while(i<la and j<lb)的形式，如果b串有完美匹配，即ACCA与CC这种情况
     * 则循环自动跳出，不能做到“前辍后辍匹配”，所以只用while(i<la)判断
     * 
     * Noted by Moody _"Kuuy"_ Wizmann
     */
    return lb-j;
}

void makeG(int a,int b)
{
    int k=kmp_do(a,b);
    g[a].push_back(node(b,k));
    //printf("%d -> %d (%d)\n",a,b,k);
}

int slove(int nr,int ok=0,int val=0)
{
    if(ok==n-1) return val;

    int res=INF;
    visit[nr]=1;
    for(int i=0;i<(int)g[nr].size();i++)
    {
        node next=g[nr][i];
        if(!visit[next.dest])
        {
            res=min(res,slove(next.dest,ok+1,val+next.val));
        }
    }
    visit[nr]=0;
    return res;
}

int main()
{
    freopen("input.txt","r",stdin);
    int T;
    input(T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",dna[i]);
            kmp_get_next(i);
            g[i].clear();
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) if(i!=j)
            {
                makeG(i,j);
            }
        }
        int ans=INF;
        for(int i=0;i<n;i++)
        {
            memset(visit,0,sizeof(visit));
            ans=min(ans,slove(i)+int(strlen(dna[i])));
        }
        printf("%d\n",ans);
    }
    return 0;
}

