//Result:445    Marvelous Mazes Accepted    C++ 0.016   2013-03-22 01:59:21
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 1024;

char str[SIZE];

void show(int x,char s)
{
    if(s=='b') s=' ';
    for(int i=0;i<x;i++)
    {
        putchar(s);
    }
}

int main()
{
    while(fgets(str,SIZE,stdin))
    {
        int sum=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='!' || str[i]=='\n') 
            {
                puts("");
                sum=0;
            }
            else
            {
                if(isdigit(str[i]))
                {
                    sum+=str[i]-'0';
                }
                else
                {
                    show(sum,str[i]);
                    sum=0;
                }
            }
        }
    }
    return 0;
}
