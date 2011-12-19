#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	while(x1!=-1&&x2!=-1&&y1!=-1&&y2!=-1)
	{
		double dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		double sq=sqrt(dis);
		double t=sqrt(dis/2);
		int temp=(int)sq;
		int tt=(int)t;
		if(temp==sq)
		{
			printf("%d\n",temp*temp);
		}
		else if(tt==t) printf("%d\n",tt*tt);
		else printf("Impossible\n");
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	}
	return 0;
}