//Result:489    Hangman Judge   Accepted    C++ 0.588   2013-03-22 11:01:26
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 1024;

char str[SIZE];
int hash[30];

int main()
{
    int n;
    while(input(n) && n!=-1)
    {
        printf("Round %d\n",n);
        memset(hash,0,sizeof(hash));
        scanf("%s",str);
        for(int i=0;str[i];i++)
        {
            hash[str[i]-'a']=1;
        }
        int alpha=0;
        for(int i=0;i<30;i++) alpha+=hash[i];

        scanf("%s",str);
        int kill=0,ok=0;
        int step=0;
        bool flag=true;
        set<int> ss;
        for(int i=0;str[i];i++)
        {
            int x = str[i]-'a';
            if(ss.find(x)!=ss.end()) continue;
            else ss.insert(x);
            if(hash[x]) ok++;
            else kill++;
            step++;

            if(kill==7)
            {
               flag=false;
               break;
            }
            if(ok == alpha)
            {
                flag=true;
                break;
            }
        }
        if(!flag) puts("You lose.");
        else
        {
            if(ok!=alpha) puts("You chickened out.");
            else puts("You win.");
        }
    }
    return 0;
}
