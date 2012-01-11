//Result:1450	Accepted	28MS	208K	G++	 464B	2012-01-11 12:00:01	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define eps 1e-5
#define print(x) cout<<x<<endl
#define input(x) cin>>x

int calC(int a,int b) //Cal C(a,b)
{
    float tmp=1;
    int c=min(b,a-b);
    for(int i=1;i<=c;i++)
    {
        tmp*=a-i+1;
        tmp/=i;
    }
    return int(tmp+eps);
}

int main()
{
    int a,b;
    input(a>>b);
    print(calC(b,a-1));
    return 0;
}
