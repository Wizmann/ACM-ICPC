#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>

using namespace std;

#define MAX 1000001

int ans[255000];
bitset<255000> prim;

void init()
{
	for(int i=1;i*4+1<=MAX;i++)
	{
		for(int j=1;j*4+1<=MAX;j++)
		{
			unsigned long long p=(i*4+1)*(j*4+1);
			if(p>MAX+5) break;
			if(!ans[i]&&!prim[i]) ans[(p-1)/4]=1;
			else
			{
				ans[(p-1)/4]=0;
				prim[(p-1)/4]=1;
			}
		}
	}
	
	long long p=0;
	for(int i=1;i*4+1<=MAX;i++)
	{
		if(ans[i]>0) p++;
		ans[i]=p;
	}
}

int main()
{
	int num;
	init();
	while(scanf("%d",&num),num)
	{
		if((num-1)%4==0) printf("%d %d\n",num,ans[(num-1)/4]);
		else printf("%d 0\n",num);
	}
	return 0;
}
		
