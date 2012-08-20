//Result:wizmann	1152	Accepted	724K	47MS	G++	1061B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 63

typedef long long llint;

int hash[256];

void init()
{
	for(int i=0;i<10;i++) hash['0'+i]=i;
	for(int i=0;i<26;i++)
	{
		hash['A'+i]=10+i;
		hash['a'+i]=36+i;
	}
}

int toBase(char *str)
{
	int b=0;
	for(int i=0;str[i];i++)
	{
		b=max(b,hash[str[i]]);
	}
	return b+1;
}

bool toDecAndBack(char *str,int b)
{
	int len=strlen(str);
	llint x=0;
	llint mul=1;
	for(int i=len-1;i>=0;i--)
	{
		x+=mul*hash[str[i]];
		mul*=b;
		mul%=(b-1);
	}
	return x%(b-1)==0;
}


int main()
{
	freopen("input.txt","r",stdin);
	init();
	char cmd[32000];
	while(input(cmd))
	{
		bool flag=true;
		int base=toBase(cmd);
		if(base==1)
		{
			print(2);
			continue;
		}
		for(int i=base;i<SIZE;i++)
		{
			if(toDecAndBack(cmd,i))
			{
				print(i);
				flag=false;
				break;
			}
		}
		if(flag) print("such number is impossible!");
	}
	return 0;
}

