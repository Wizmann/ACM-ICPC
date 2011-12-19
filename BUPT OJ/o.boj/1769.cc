#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int t1,t2;
	int l1,l2;
	scanf("%d%d%d%d",&t1,&t2,&l1,&l2);
	while(t1||t2)
	{
		double ans=0;
		int length=(t1>t2?t1-t2:t2-t1)*60;
		
		double y=length*length;
		
		ans+=(l1>=length?0:(length-l1)*(length-l1))/2.0+(l2>=length?0:(length-l2)*(length-l2))/2.0;
		
		printf("%.3lf\n",(double)(y-ans)/y);
		scanf("%d%d%d%d",&t1,&t2,&l1,&l2);
	}
	return 0;
}