#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1000

typedef struct point
{
	int x,y;
	
	void setpoint()
	{
		scanf("%d%d",&x,&y);
	}
}point;

point anta[N];
point antb[N];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int counter,end,a,b;
	scanf("%d",&counter);
	while(counter--)
	{
		scanf("%d",&end);
		scanf("%d%d",&a,&b);
		int low=1<<30;
		
		anta[0].x=0;anta[0].y=0;
		for(int i=1;i<=a;i++)
		{
			anta[i].setpoint();
			if(anta[i].y<low) low=anta[i].y;
		}
		anta[a+1].x=end;anta[a+1].y=0;
		
		antb[0].x=end;antb[0].y=0;
		for(int i=1;i<=b;i++)
		{
			antb[i].setpoint();
			if(antb[i].y<low) low=antb[i].y;
		}
		antb[b+1].x=0;antb[b+1].y=0;
		
		double ans=0;
		for(int i=1;i<=a+1;i++)
		{
			ans+=((anta[i-1].y-low)+(anta[i].y-low))*abs(anta[i-1].x-anta[i].x);
		}
		
		for(int i=1;i<=b+1;i++)
		{
			ans-=((antb[i-1].y-low)+(antb[i].y-low))*abs(antb[i-1].x-antb[i].x);
		}
		ans/=2;
		
		printf("%.2lf\n",fabs(ans));
	}
	return 0;
}
			
		
