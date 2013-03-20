//Result:488    Triangle Wave   Accepted    C++ 0.420   2013-03-20 14:27:13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

void show(int x)
{
    for(int i=0;i<x;i++) printf("%d",x);
    puts("");
}

int main()
{
    int T;
    int w,h;
    input(T);
    while(T--)
    {
        input(h>>w);
        for(int i=0;i<w;i++)
        {
            for(int j=1;j<h;j++) show(j);
            show(h);
            for(int j=h-1;j>=1;j--) show(j);
            if(i<w-1) puts("");
        }
        if(T) puts("");
    }
    return 0;
}
