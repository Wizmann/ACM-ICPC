#define LOCAL

#include <stdio.h>
#include <string.h>

#define L 32

int mul(int n)//2µÄn´Î·½ 
{
	int res=1;
	for(int i=0;i<n;i++) res*=2;
	return res;		
}

void convert(char *ip)
{
	int IP[4];
	char *cp=ip+strlen(ip)-1;
	for(int i=0;i<4;i++)
	{
		int temp=0;
		for(int n=0;n<8;n++)
		{
			temp+=(*cp-'0')*mul(n);
			cp--;			
		}
		IP[3-i]=temp;
	}
	for(int i=0;i<4;i++)
	{
		printf("%d",IP[i]);
		if(i<3) printf(".");
	}
	printf("\n");
}

int main()
{
	int n;
	char temp[L+1];
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",temp);
		convert(temp);
	}
	return 0;
}
