#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int mul(int n)
{
	unsigned int res=1;
	while(n--) res*=2;
	return res;
}

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=-1)
	{
		int high;
		for(int i=0;i<32;i++)
		{
			if(mul(i)>num)
			{
				high=i;
				break;
			}
			else if(mul(i)==num)
			{
				high=-1;
				break;
			}
		}
		if(high==-1) printf("PERFECT\n");
		else
		{
			unsigned int low=mul(high-1);
			high=mul(high);
			
			if(num-low==high-num) printf("%u %u\n",low,high);
			else if(num-low>high-num) printf("%u\n",high);
			else printf("%u\n",low);
		}
	}
	return 0;
}