//Result:Wizmann	2222	Accepted	GNU C++	1.25k	0ms	1248KB	2013-04-23 21:03:52
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int SIZE = 256;
const llint INF = 1LL << 54;


struct CWork
{
    llint A,B,pre,num;

    CWork(){}
    CWork(int iA,int iB)
    {
        A=iA;B=iB;
        pre=0;
        num=0;
    }

    int next()
    {
        llint now = A;
        num++;
        for(int i=0;i<B;i++)
        {
            now *= num;
        }
        llint res = now - pre;
        pre = now;
        return res;
    }
};

CWork work[SIZE];
llint array[SIZE];
int n,m;

int main()
{
    llint a,b;
    while(input(n>>m))
    {
        llint res=0;
        for(int i=0;i<m;i++)
        {
            input(a>>b);
            work[i]=CWork(a,b);
            array[i]=work[i].next();
        }

        for(int i=0;i<n;i++)
        {
            llint mini=INF;
            int p=-1;
            for(int j=0;j<m;j++)
            {
                if(array[j]<mini)
                {
                    mini=array[j];
                    p=j;
                }
            }
            res+=mini;
            array[p]=work[p].next();
        }
        print(res);
    }
    return 0;
}
            


