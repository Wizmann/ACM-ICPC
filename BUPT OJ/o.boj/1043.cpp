#include <stdio.h>
//#include <time.h>
#include <string.h>

#define N 100000//100KB的内存开销 

char road[N];

void ruin(char* road,int start,int end)
{
	for(int i=start;i<end;i++)
	{
		if(road[i]!=-1) road[i]=-1;//-1为毁坏状态; 
	}
}

int check(char *road)
{
	int ret=0;
	for(int i=0;i<N;i++)
	{
		if(road[i]==-1) ret++;
	}
	return ret;
}

int main()
{
	int a,b;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	memset(road,0,sizeof(road));
	while(scanf("%d%d",&a,&b)!=-1)
	{		
		ruin(road,a,b);
	}	
	printf("%d\n",check(road));
	//printf("TME TIME USED:%lf\n",(double)clock()/CLOCKS_PER_SEC);
}