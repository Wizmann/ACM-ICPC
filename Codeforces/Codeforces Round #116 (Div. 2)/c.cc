//Result:Apr 24, 2012 12:16:38 PM	Wizmann	 C - Letter	 GNU C++	Accepted	 30 ms	 2300 KB
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100
#define INF 1<<25

int upper[SIZE],lower[SIZE];


int main()
{
	freopen("c.txt","r",stdin);
	char str[SIZE];
	scanf("%s",str);
	for(int i=0;str[i];i++)
	{
		if(str[i]>='a' && str[i]<='z')
		{
			if(i) lower[i]=lower[i-1]+1;
			else lower[i]=1;
		}
		else
		{
			if(i) lower[i]=lower[i-1];
		}
	}
	for(int i=strlen(str)-1;i>=0;i--)
	{
		if(str[i]>='A' && str[i]<='Z')
		{
			upper[i]=upper[i+1]+1;
		}
		else upper[i]=upper[i+1];
	}
	
	int ans=INF;
	for(int i=-1;i<(int)strlen(str);i++)
	{
		int res=(i<0?0:lower[i])+upper[i+1];
		ans=min(ans,res);
	}
	
	print(ans);
	return 0;
}
