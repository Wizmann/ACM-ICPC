//Result:10071  Back to High School Physics Accepted    C++ 0.136   2013-03-15 15:35:53
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
    int a,b;
    while(input(a>>b))
    {
        print((long long)a*b*2);
    }
    return 0;
}