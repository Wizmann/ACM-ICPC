#include <stdio.h>
#include <string.h>

int main()
{
	
	freopen("input.txt","r",stdin);
	
	char string[120];
	scanf("%s",string);
	while(strcmp(string,"#"))
	{
		int len=strlen(string);
		long long sum=0;
		for(int i=0;i<len;i++)
		{
			sum+=(string[i]-'A'+1)*(i+1);
		}
		printf("%lld\n",sum);
		scanf("%s",string);
	}
	return 0;	
}