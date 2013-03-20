//Result:   10300   Ecological Premium  Accepted    C++ 0.008   2013-03-15 16:27:44
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
    int T,n;
    int a,b,c;

    input(T);
    while(T--)
    {
        input(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            input(a>>b>>c);
            sum += a*c;
        }
        print(sum);
    }
    return 0;
}


