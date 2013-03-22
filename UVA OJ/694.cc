//Result:694	The Collatz Sequence	Accepted	C++	0.060	2013-03-21 04:03:06
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

int solve(llint a,llint b)
{
    int step=0;
    while(true)
    {
        if(a>b) break;
        step++;
        if(a==1) break;
        else if(!(a%2)) a=a/2;
        else if(a%2) a=a*3+1;
    }
    return step;
}


int main()
{
    freopen("input.txt","r",stdin);
    llint a,b;
    int cas=1;
    while(input(a>>b) && a+b>=0)
    {
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",
                    cas++, a,b,solve(a,b));
    }
    return 0;
}

