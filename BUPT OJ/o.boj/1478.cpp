#include <stdio.h>

#define LOCAL

int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	int min=0,sec=0,hour=0;
	int a,b;
	for(int i=0;i<n;i++)
	{
		scanf("%d:%d",&a,&b);
		min+=a;sec+=b;
	}	
	min+=sec/60;sec%=60;
	hour=min/60;min%=60;
	if(hour<1) printf("120\n");
	else
	{
		if(sec!=0)
		{
			min++;
			printf("%d\n",120*hour+min*2);
		}
		else printf("%d\n",120*hour+min*2);
	}
	return 0;	
}