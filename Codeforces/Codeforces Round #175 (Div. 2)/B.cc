//Result:Mar 23, 2013 9:19:27 AM    Wizmann  B - Find Marble     GNU C++    Accepted    46 ms   504 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 102400;

int mirror[SIZE];
char visit[SIZE];
int n,st,end;

int shuffle()
{
    int x = st;
    int step = 0;
    bool flag=true;
    while(1)
    {
        if(visit[x])
        {
            flag=false;
            break;
        }
        else visit[x]=1;

        if(x==end) break;
        else x = mirror[x];
        step++;
    }
    if(flag) return step;
    else return -1;
}


int main()
{
    while(input(n>>st>>end))
    {
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&mirror[i]);
        }
        print(shuffle());
    }
    return 0;
}

