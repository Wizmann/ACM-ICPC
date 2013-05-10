//Result:Wizmann	2218	Accepted	GNU C++	1.60k	0ms	1280KB	2013-04-23 20:02:59
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 2048

int n,m;
int trans[SIZE];
int idx;
string str_hash[SIZE];
int msg_idx[SIZE];
map<string,int> mp;
char str[SIZE];

char *getline() 
{ 
    while(true) 
    { 
        gets(str); 
        if(*str && *str!='\n') break; 
    }
    return str; 
} 

int get_idx(string s)
{
    int p;
    if(mp.find(s)==mp.end())
    {
        mp[s] = idx;
        p = idx++;
        str_hash[p] = s;
    }
    else p=mp[s];
    return p;
}

void solve(int len)
{
    while(--n)
	{
		for(int i=0;i<len;i++)
		{
			int x = msg_idx[i];
			if(trans[x]!=-1)
			{
				msg_idx[i]=trans[x];
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		if(i) printf(" ");
		printf("%s", str_hash[msg_idx[i]].c_str());
	}
	puts("");
}
		

int main()
{
    int T;
    input(T);
    char a[SIZE],b[SIZE];
    int cas=1;
    while(T--)
    {
        input(n>>m);
        mp.clear();
        memset(trans,-1,sizeof(trans));
        idx=0;
        for(int i=0;i<m;i++)
        {
            scanf("%s%s",a,b);
            int pa,pb;
            pa=get_idx(a);
            pb=get_idx(b);
            trans[pa]=pb;
        }
        char *p=getline();
        p=strtok(p," ");
        int ptr=0;
        while(p)
        {
            //print(p);
            msg_idx[ptr]=get_idx(p);
            //print(msg_idx[ptr]);
            ptr++;
            p=strtok(NULL," ");
        }
        printf("Case #%d: ",cas++);
        solve(ptr);
    }
    return 0;
}
