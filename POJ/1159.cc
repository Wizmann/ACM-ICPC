#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void strrev(char *p)
{
	char *q=strlen(p)+p-1;
	char t;
	while(p<=q)
	{
		t=*p;*p=*q;*q=t;
		p++;q--;
	}
}

int len;
unsigned short dp[5010][5010];

int lcs(char *a,char *b)
{
	int res=-1;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(a[i]==b[j])
			{
				dp[i+1][j+1]=dp[i][j]+1;
				if(dp[i+1][j+1]>res) res=dp[i+1][j+1];
			}
			else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&len);
	char a[5010];
	char b[5010];
	scanf("%s",a);
	strcpy(b,a);
	strrev(b);
	
	printf("%d\n",len-lcs(a,b));
	return 0;
}
