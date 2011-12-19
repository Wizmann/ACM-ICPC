#include <cstdio>
#include <cstring>

int bitset[32];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,temp;
	while(scanf("%d",&n)!=EOF)
	{
		memset(bitset,0,sizeof(bitset));
		for(int i=0;i<3*n-1;i++)
		{
			scanf("%d",&temp);
			if(temp<0)
			{
				bitset[31]++;
				temp=-temp;
			}

			for(int j=0;j<31&&temp>0;j++)
			{
				bitset[j]+=(temp%2);
				temp/=2;
			}
		}
		int ans=0;
		for(int i=0;i<31;i++)
		{
			if(bitset[i]%3!=0)
			{
				ans+=1<<i;
			}
		}
		
		if(bitset[31]%3!=0) ans=-ans;
		printf("%d\n",ans);
	}
	return 0;
}
		
