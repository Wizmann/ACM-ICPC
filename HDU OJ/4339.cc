//Result:2012-08-02 20:59:45	Accepted	4339	2531MS	6184K	1877 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000010

inline int lowbit(int x)
{
    return x&(-x);
}

char a[SIZE],b[SIZE];
int baum[SIZE];
int sz;

void add(int pos,int val=1)
{
    while(pos<SIZE)
    {
        baum[pos]+=val;
        pos+=lowbit(pos);
    }
}

int sum(int pos)
{
    int s=0;
    while(pos>0)
    {
        s+=baum[pos];
        pos-=lowbit(pos);
    }
    return s;
}

void init()
{
    memset(baum,0,sizeof(baum));
    for(int i=0;a[i] && b[i];i++)
    {
        if(a[i]==b[i]) add(i+1);
    }
}

int sum(int st,int end)
{
    return sum(end)-sum(st-1);
}

int ask(int pos)
{
    int l=pos,r=sz;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int res=sum(pos+1,mid+1);
        if(res==mid-pos+1) l=mid+1;
        else r=mid-1;
    }
    return l-pos;
}


int main()
{
    int T,query;
    int cmd,h1,h2;
    char str[4];
    input(T);
    int cas=1;
    while(T--)
    {
        printf("Case %d:\n",cas++);
        scanf("%s%s",a,b);
        init();
        sz=min(strlen(a),strlen(b));
        input(query);
        while(query--)
        {
            scanf("%d",&cmd);
            if(cmd==2)
            {
                scanf("%d",&h1);
                printf("%d\n",ask(h1));
            }
            else
            {
                int val=0;
                scanf("%d%d%s",&h1,&h2,str);
                if(a[h2]==b[h2]) val=1;
                if(h1==1) a[h2]=*str;
                if(h1==2) b[h2]=*str;

                if(!val && a[h2]==b[h2]) add(h2+1,1);
                else if(val && a[h2]!=b[h2]) add(h2+1,-1);
            }
        }
    }
    return 0;
}

