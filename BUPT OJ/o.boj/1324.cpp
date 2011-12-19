#include <stdio.h>

#define LOCAL

int main()
{
	char sign;
	double num;
	double ret=0;
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	while(scanf("%c%lf\n",&sign,&num)!=-1)
	{
		if(sign=='+') ret+=num;
		else if(sign=='#') ret=num;
		else if(sign=='-') ret-=num;
		int temp=(int)(ret*1000);
		printf("%.2lf\n",(double)temp/1000);
	}
	return 0;
}
