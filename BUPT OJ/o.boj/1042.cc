//Result:1042 	Accepted	10MS	212K	G++	563B	2011-11-04 09:22:43
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
    int n,m,t;
    char buffer[64];
    long long sum=0;
    bool flag=true;
    input(n>>m);
    for(int i=0;i<n;i++)
    {
        input(t);sum+=t;
    }
    
    for(int i=0;i<m;i++)
    {
        int s=0;
        input(buffer);
        for(int j=0;j<n;j++)
        {
            s+=buffer[j]-'0';
        }
        if(flag && (s==0 || s==n) )
        {
            flag=false;
        }
    }
    if(!flag) print("Poor Wing!");
    else print(sum);
    return 0;
}
    
