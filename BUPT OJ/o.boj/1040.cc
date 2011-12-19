#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

int mul[N];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	char input[N];
	memset(mul,0,sizeof(mul));
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",input);
		if(*input=='*')
		{
			if(input[1]>0&&input[1]<='9') mul[input[1]-'0']++;
			else if(input[1]=='0')
			{
				printf("0\n");
				exit(0);
			}
			else
			{
				mul[input[1]-'A'+10]++;
			}
		}
		else
		{
			if(input[1]>0&&input[1]<='9') mul[input[1]-'0']--;
			else mul[input[1]-'A'+10]--;
		}
	}
	
	long long ans=1;
	for(int i=0;i<N;i++)
	{
		if(mul[i]>0)
		{
			for(int j=0;j<mul[i];j++) ans*=i;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		if(mul[i]<0)
		{
			for(int j=0;j>mul[i];j--) ans/=i;
		}
	}
	
	printf("%lld\n",ans);
	return 0;
}