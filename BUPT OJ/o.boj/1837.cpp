#include <stdio.h>

#define ZHU 0.658854166667

int main()
{
	double g;
	scanf("%lf",&g);
	g/=ZHU;
	
	int weight[5];
	
	if(g-(int)g>=0.5) weight[4]=(int)g+1;
	else weight[4]=(int)g;
	
	weight[3]=weight[4]/24;
	weight[4]%=24;
	
	weight[2]=weight[3]/16;
	weight[3]%=16;
	
	weight[1]=weight[2]/30;
	weight[2]%=30;
	
	weight[0]=weight[1]/4;
	weight[1]%=4;
	
	printf("%d %d %d %d %d\n",weight[0],weight[1],weight[2],weight[3],weight[4]);
	return 0;
}