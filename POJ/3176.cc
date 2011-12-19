#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int g[400][400];

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) scanf("%d",&g[i][j]);
	}
	
	for(int i=n-1;i>0;i--)
	{
		for(int j=1;j<=i;j++) g[i][j]+=max(g[i+1][j],g[i+1][j+1]);
	}
	
	printf("%d\n",g[1][1]);
	return 0;
}
	
