//Result:2012-08-15 14:35:13	Accepted	4364	125MS	304K	1148 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 4

const int MAXN=0xFF;
const int MOD=0x1B;

const int mat[4][4]={{2,3,1,1},
			         {1,2,3,1},
					 {1,1,2,3},
					 {3,1,1,2}};
int me[4][4],ans[4][4];

int leftshift(int x)
{
	int res=x<<1;
	if(res>MAXN) res^=MOD;
	
	return res;
}

int cal(int a,int b)
{
	int res;
	if(a==1) res=b;
	else if(a==2) res=leftshift(b);
	else res=leftshift(b)^b;
	return res;
}

void slove()
{
	memset(ans,0,sizeof(ans));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				ans[i][j]^=cal(mat[i][k],me[k][j])%(MAXN+1);
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				scanf("%X",&me[i][j]);
			}
		}
		slove();
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				if(j) printf(" ");
				printf("%02X",ans[i][j]);
			}
			puts("");
		}
		if(T) puts("");
	}
	return 0;
}
