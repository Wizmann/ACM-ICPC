#include <cstdio>
#include <cstdlib>
#include <cstring>

long long array[10010];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int n,st;
	double input;
	while(scanf("%d%d",&n,&st)!=EOF)
	{
		memset(array,0,sizeof(array));
		long long sum=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&input);
			array[i]=(int)(100*(input+0.005));
			if(sum<array[i]) sum=array[i];
		}
		
		long long upper=sum;
		long long lower=1;
		int num=0;
		//long long max=-1;
		
		while(upper-lower>5)
		{
			long long mid=(upper+lower)/2;
			num=0;
			if(mid==0)
			{
				lower=mid+1;
				continue;
			}
			for(int i=0;i<n;i++) num+=array[i]/mid;
			
			if(num>=st) lower=mid;		
			else upper=mid-1;
		}
		long long res=-1;
		//printf("%lld %lld\n",lower,upper);
		for(int i=lower;i<=upper;i++)
		{
			num=0;
			for(int j=0;j<n;j++) num+=array[j]/i;
			
			if(num>=st&&res<i) res=i;
		}
		if(res<0) printf("0.00\n");
		else printf("%.2lf\n",res*0.01);
	}
	return 0;
}
			
		
		
