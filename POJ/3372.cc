//Result:wizmann	3372	Accepted	376K	0MS	G++	126B
#include <cstdio>

int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		puts(x&(x-1)?"NO":"YES");
	}
	return 0;
}
