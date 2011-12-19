#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[15],b[15];
	scanf("%s%s",a,b);
	while(*a!='0'&&*b!='0')
	{
		long long result=0;
		char *p=a;
		char *q=b;
		
		while(*p!='\0')
		{
			while(*q!='\0')
			{
				result+=(*p-'0')*(*q-'0');
				q++;
			}
			p++;
			q=b;
		}		
		
		printf("%lld\n",result);
		scanf("%s%s",a,b);
	}
	return 0;
}