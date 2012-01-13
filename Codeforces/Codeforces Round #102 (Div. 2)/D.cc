#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
    long long m,n;
    input(m>>n);
    if(m>n) swap(m,n);
    //print(m<<' '<<n);
    if(m>2) print((m*n+1)/2);
    else if(m==1) print(n);
    else if(m==2)
    {
        print( (n/4)*4 + min(n%4,2LL)*2);
    }
    else print("ERROR");
    return 0;
}
