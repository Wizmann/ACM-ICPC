//Result:168 	Accepted 	2ms 	144kb 	G++	601B	2012-07-21 11:48:23
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long llint;

char hash[32];
void init()
{
	for(int i=0;i<32;i++)
	{
		if(i<10) hash[i]='0'+i;
		else hash[i]='A'+i-10;
	}
}

inline char chr(int x){return hash[x];}

int main()
{
	freopen("input.txt","r",stdin);
	init();
	char out[16];
	llint x;
	int ind;
	while(scanf("%lld",&x)!=EOF)
	{
		if(x==0)
		{
			puts("0");
			continue;
		}
		ind=0;
		while(x)
		{
			int t=x&31;
			x>>=5;
			out[ind++]=chr(t);
		}
		for(int i=ind-1;i>=0;i--)
		{
			printf("%c",out[i]);
		}
		puts("");
	}
	return 0;
}

