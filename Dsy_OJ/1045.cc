//Result:Wizmann	1045	Accepted	16900 kb	2792 ms	C++/Edit	943 B	2013-05-19 00:06:55
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

typedef long long llint;

const int SIZE = 1000100;

llint candy[SIZE], sum[SIZE];
int n;

int main()
{
    while(input(n))
    {
        llint ave = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",candy+i);
            ave += candy[i];
        }

        ave /= n;

        memset(sum, 0, sizeof(sum));
        for(int i=1;i<n;i++)
        {
            sum[i] = sum[i-1] + candy[i] - ave;
        }

        sort(sum,sum+n);
        llint ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += abs(sum[i] - sum[n/2]);
        }
        print(ans);
    }
    return 0;
}

