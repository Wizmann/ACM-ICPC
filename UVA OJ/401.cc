//Result:401	Palindromes	Accepted	C++	0.024	2013-03-24 12:45:24
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int ALPHA = 256;
const int SIZE = 54;

char mirror[ALPHA];
char str[SIZE];

void init()
{
    memset(mirror,-1,sizeof(mirror));
    char dic[]="AAMMYYZ5OO112SE33ES25ZHHTTIIUUJLVV88WWLJXX";
    for(int i=0;dic[i];i+=2)
    {
        mirror[(int)dic[i]]=dic[i+1];
    }
}

bool isMirror()
{
    char mstr[SIZE]={0};
    int ptr=strlen(str)-1;
    for(int i=0;str[i];i++)
    {
        if(mirror[(int)str[i]]!=-1)
        {
            mstr[ptr--]=mirror[(int)str[i]];
        }
        else return false;
    }
    if(!strcmp(mstr,str)) return true;
    else return false;
}

bool isPal()
{
    int p=0,q=strlen(str)-1;
    while(p<=q)
    {
        if(str[p]==str[q])
        {
            p++;q--;
        }
        else return false;
    }
    return true;
}

int main()
{
    init();
    while(scanf("%s",str)!=EOF)
    {
        printf("%s -- ",str);
        for(int i=0;str[i];i++)
        {
            if(str[i]=='0') str[i]='O';
        }
        bool mirror = isMirror();
        bool pal    = isPal();
        if(mirror and pal) puts("is a mirrored palindrome.");
        else if(!mirror and pal) puts("is a regular palindrome.");
        else if(mirror and !pal) puts("is a mirrored string.");
        else puts("is not a palindrome.");
        puts("");
    }
    return 0;
}

