//Result:wizmann	1026	Accepted	940K	47MS	G++	1033B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

//#define input(x) cin>>x
//#define print(x) cout<<x<<endl

int n;
int trans[256];
int mod[256];
int mem[256][256];

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(trans,0,sizeof(trans));
		memset(mod,0,sizeof(mod));
		memset(mem,0,sizeof(mem));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&trans[i]);
			trans[i]--;
		}
		for(int i=0;i<n;i++)
		{
			int pos=i;
			mem[i][0]=i;mod[i]=1;
            for(pos=trans[pos];pos!=i;pos=trans[pos]) mem[i][mod[i]++]=pos;
        }

		int cov;
		char strin[512],strout[512];
		memset(strin,0,sizeof(strin));
		memset(strout,0,sizeof(strout));
		while(scanf("%d",&cov)!=EOF && cov)
		{
			getchar();
			gets(strin);
			for(int i=strlen(strin);i<n;i++) strin[i]=' ';
			for(int i=0;i<n;i++)
			{
				strout[mem[i][cov%mod[i]]]=strin[i];
			}
			puts(strout);
		}
		puts("");
	}
	return 0;
}

