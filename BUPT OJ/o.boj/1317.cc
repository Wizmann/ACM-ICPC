#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MOD 32768
#define SIZE 24578
#define LOOP 24576

int up[SIZE],down[SIZE];

void init()
{
	up[1]=3;down[1]=2;
	for(int i=2;i<SIZE;i++)
	{
		up[i]=(up[i-1]*2+down[i-1])%MOD;
		down[i]=(up[i-1]+down[i-1])%MOD;
		//if(up[i]==up[1]&&down[i]==down[1]) printf("%d\n",i);
	}
}

int main()
{
	init();
	int n,cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		n%=LOOP;
		if(!n) n=LOOP;
		printf("Case %d:\n",cas++);
		printf("%d\n",up[n]);
	}
	return 0;
}
