#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int t=1;

int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

typedef struct stu
{
	int grade[8];
	int nr;
	
	void setstu(int n,float a,float b,float c)
	{
		nr=n;
		grade[0]=(int)((a+0.001)*100);
		grade[1]=(int)((b+0.001)*100);
		grade[2]=(int)((c+0.001)*100);
		grade[3]=grade[0]+grade[1];
		grade[4]=grade[1]+grade[2];
		grade[5]=grade[0]+grade[2];
		grade[6]=grade[3]+grade[2];
		grade[7]=0;
		
		qsort(grade,8,sizeof(int),cmp);
	}
	
	int search(int n,int g)
	{
		if(n<nr)
		{		
			for(int i=0;i<8;i++)
			{
				if(grade[i]<=g) return grade[i];
			}
		}
		else
		{
			for(int i=0;i<8;i++)
			{
				if(grade[i]<g) return grade[i];
			}
		}
		return -100;
	}
}stu;

stu array[20000];

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n)
	{
		memset(array,0,sizeof(array));
		float a,b,c;
		for(int i=0;i<n;i++)
		{
			scanf("%f%f%f",&a,&b,&c);
			array[i].setstu(i+1,a,b,c);
		}
		
		int no=0;
		int ans=1<<20;
		int nr=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&nr);
			if(ans<0) continue;
			ans=array[nr-1].search(no,ans);
			no=nr;
		}
		printf("Case %d: ",t++);
		if(ans>=0) printf("%.2lf\n",(double)ans/100);
		else printf("No solution\n");
		scanf("%d",&n);
	}
	return 0;
}