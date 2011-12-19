#include <cstdio>
#include <cstdlib>
#include <cstring>

#define left(x) (2*x)
#define right(x) (2*x+1)
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)

long long baum[140000];
long long temp[140000];
int n,total;

long long cal()
{
	for(int i=total/2;i>=1;i--)
	{
		temp[i]=min(temp[left(i)],temp[right(i)])+baum[i];
	}
	return temp[1];
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	int a,b,c;
	scanf("%d",&n);
	total=(1<<n)-1;
	for(int i=1;i<=(1<<n)-1;i++) scanf("%lld",&baum[i]);
	memcpy(temp,baum,sizeof(temp));
	printf("%lld\n",cal());

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		total=(1LL<<(a-1))-1+b;
		temp[total]+=(c-baum[total]);
		baum[total]=c;

		total/=2;
		while(total>=1)
		{
			temp[total]=min(temp[left(total)],temp[right(total)])+baum[total];
			if(total==1) break;
			total/=2;
		}
		printf("%lld\n",temp[1]);
	}
	return 0;
}
	
