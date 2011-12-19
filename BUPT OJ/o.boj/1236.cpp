#define LOCAL

#include <stdio.h>
#include <stdlib.h>

int* creat(int n)
{
	int *ret=(int*)calloc(n,sizeof(int));
	return ret;
}

void read(int *line,int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&line[i]);
	}	
}

void cut(int BOSS,int* line,int num,int a,int b)
{
	int flag=0;
	int first=0;
	for(int i=a;i<=b;i++)
	{
		if(line[i]>=BOSS)
		{
			line[i]=BOSS-1;
			if(first==0)
			{
				printf("%d",i+1);
				first=-1;
			}
			else printf(" %d",i+1);
			flag++;
		}
	}
	if(flag==0) printf("No Solution\n");
	else printf("\n");
}

int main()
{
	int num;
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		printf("Case %d:\n",i+1);
		int BOSS;
		int man;
		int time;
		scanf("%d",&BOSS);
		scanf("%d",&man);
		int *IQ=creat(man);
		read(IQ,man);
		scanf("%d",&time);
		for(int come=0;come<time;come++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			cut(BOSS,IQ,man,a-1,b-1);
		}
		int flag=0;
		for(int count=0;count<man;count++)
		{
			if(IQ[count]>=BOSS) flag--;
		}
		if(flag<0) printf("Sorry,Bomb\n");
		else printf("Congratulations,professor\n");
		free(IQ);
	}
	return 0;
}
