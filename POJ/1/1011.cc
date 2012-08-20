#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int array[70];
int n,sum;
int max=-1;
char used[70];

int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

bool dfs(int len,int goal,int rest,char index)
{
	if(!rest)return true;
	if(len==goal) return dfs(0,goal,rest-goal,0);
	else
	{
		int ws=-1;
		for(int i=index;i<n;i++)
		{
			if(!used[i]&&len+array[i]<=goal&&array[i]!=ws)
			{
				used[i]=1;
				//printf("GOAL:%d -> %d\n",goal,len+array[i]);
				if(dfs(len+array[i],goal,rest,i+1)) return true;	

				ws=array[i];
				used[i]=0;
				if(index==0) break;
			}
		}
	}
	return false;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	while(scanf("%d",&n)!=EOF&&n)
	{
		sum=0;
		max=-1;
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++)
		{
			scanf("%d",array+i);
			sum+=array[i];
		}
		qsort(array,n,sizeof(int),cmp);
		for(int i=n;i>=1;i--)
		{
			if(sum%i==0)
			{
				memset(used,0,sizeof(used));
				used[0]=1;
				if(dfs(array[0],sum/i,sum,1))
				{
					max=sum/i;break;
				}
			}
		}
		printf("%d\n",max);
	}
	printf("The time used %.4lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
