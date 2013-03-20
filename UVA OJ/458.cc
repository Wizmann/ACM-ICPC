//Result:458    The Decoder Accepted    C++ 0.020   2013-03-16 11:24:04
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 10240;

int main()
{
    char str[SIZE];
    while(fgets(str,SIZE,stdin))
    {
        for(int i=0;str[i];i++) 
        {
            str[i]= str[i]=='\n'? 0 : str[i]-7;
        }
        puts(str);
    }
    return 0;
}
