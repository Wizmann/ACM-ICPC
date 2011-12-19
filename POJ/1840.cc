#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 25000000

char hash[SIZE];

int main()
{
	int a1,a2,a3,a4,a5;
	while(scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)==5)
	{
		int cnt=0;
		memset(hash,0,sizeof(hash));
		for(int i=-50;i<=50;i++)
		{
			for(int j=-50;j<=50;j++)
			{
				int t=a1*i*i*i+a2*j*j*j;
				if(i&&j) hash[t+SIZE/2]++;
			}
		}
		
		for(int i=-50;i<=50;i++)
		{
			for(int j=-50;j<=50;j++)
			{
				for(int k=-50;k<=50;k++)
				{
					int t=a3*i*i*i+a4*j*j*j+a5*k*k*k;
					if(i&&j&&k) if(t<=SIZE/2&&t>=-SIZE/2) cnt+=hash[SIZE/2-t];
				}
			}
		}
		
		printf("%d\n",cnt);
	}
	return 0;
}
						
