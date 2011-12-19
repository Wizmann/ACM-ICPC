#include <cstdio>
#include <cstring>

char array[10010];
int flag=1;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0) break;
		for(int i=0;i<n;i++) scanf("%d",&array[i]);
		
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			if(array[i]==-1) continue;
			while(array[i]==1&&array[i+1]==-1)
			{
				ans++;
				array[i]=-1;
				array[i+1]=1;
				if(i>0)  i--;
			}
		}
		
		printf("Case %d: ",flag++);
		printf("%d\n",ans);
	}
	return 0;
}
