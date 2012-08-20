//Result:wizmann	2418	Accepted	880K	4125MS	G++	759B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

#define SIZE 10010

typedef struct str
{
	char s[35];
	
	friend bool operator < (const str a,const str b)
	{
		if(strcmp(a.s,b.s)==-1) return true;
		else return false;
	}
}str;

int num[SIZE],all;

int main()
{
	freopen("input.txt","r",stdin);
	int pad=0;
	map<str,int> mp;
	str temp;
	while(gets(temp.s))
	{
		if(*temp.s=='\0') continue;
		all++;
		if(mp.find(temp)==mp.end())
		{
			mp[temp]=++pad;
			num[pad]++;
		}
		else num[mp[temp]]++;
	}
	
	map<str,int>::iterator iter;
	iter=mp.begin();
	while(iter!=mp.end())
	{
		printf("%s %.4f\n",(iter->first).s,(double)num[iter->second]/all*100.0);
		++iter;
	}
	return 0;
}
		
