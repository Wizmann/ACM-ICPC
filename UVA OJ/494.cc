//Result:494    Kindergarten Counting Game  Accepted    C++ 0.012   2013-03-16 11:46:09
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>


using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 10240;

bool isWord(char *p)
{
    for(int i=0;p[i];i++)
    {
        if(isalpha(p[i])) return true;
    }
    return false;
}

int main()
{
    char str[SIZE];
    while(fgets(str,SIZE,stdin))
    {
        char *p = str;
        int ans=0;
        for(int i=0;p[i];i++)
        {
            if(!isalpha(p[i])) p[i]=' ';
        }
        p = strtok(p," ");
        while(p)
        {
            if(isWord(p)) ans++;
            p = strtok(NULL," ");
        }
        print(ans);
    }
    return 0;
}

