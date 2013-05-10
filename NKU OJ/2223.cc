//Result:Wizmann	2223	Accepted	GNU C++	0.74k	380ms	1280KB	2013-04-23 21:29:05
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int SIZE = 10240;

int n,m;
int mod[SIZE];

int main()
{
    freopen("input.txt","r",stdin);
    int x;
    while(input(n>>m))
    {
        memset(mod,0,sizeof(mod));
        for(int i=0;i<n;i++)
        {
            input(x);
            mod[x%m]++;
        }

        llint res=0;
        for(int i=0;i<m;i++)
        {
            if(mod[i])
            {
                res += llint(mod[i])*(mod[i]-1)/2;
                if(i<m-i)
                {
                    res += llint(mod[i])*mod[m-i];
                }
            }
        }
        print(res);
    }
    return 0;
}


