//Result:2012-04-30 16:12:04	 Accepted	1013	C++	490	2236	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define INF 1<<25

#define SIZE 128
#define DP 512

struct weapon
{
	int w,s,d;
	weapon(){}
	weapon(int i_w,int i_s,int i_d)
	{
		w=i_w;s=i_s;d=i_d;
	}
};

struct wagon
{
	int w,s;
	wagon(){}
	wagon(int i_w,int i_s)
	{
		w=i_w;
		s=i_s;
	}
};

int n;
weapon army[3];
wagon trans[SIZE];
int bonus[5];
int dp[2][DP][DP];

int slove()
{
	int ans=0;
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	int ptr=1,pre=0;
	int last1=0,last2=0;
	for(int i=0;i<n;i++)
	{
		memset(dp[ptr],-1,sizeof(dp[ptr]));
		int up1=min(trans[i].w/army[0].w,trans[i].s/army[0].s);
		int up2=min(trans[i].w/army[1].w,trans[i].s/army[1].s);
		for(int j=0;j<=last1;j++)
		{
			for(int k=0;k<=last2;k++)
			{
				if(dp[pre][j][k]==-1) continue;
				for(int x=0;x<=up1;x++)
				{
					for(int y=0;y<=up2;y++)
					{
						if(j+x>DP || k+y>DP) continue;
						
						int w=army[0].w*x+army[1].w*y;
						int s=army[0].s*x+army[1].s*y;
						if(w>trans[i].w || s>trans[i].s) break;
						dp[ptr][j+x][k+y]=max(dp[ptr][j+x][k+y],
									dp[pre][j][k]+min((trans[i].w-w)/army[2].w,(trans[i].s-s)/army[2].s));
					}
				}
			}
		}
		last1+=up1;
		last2+=up2;
		ptr^=1;
		pre=ptr^1;
	}
	int def=army[0].d+army[1].d+army[2].d;
	for(int i=0;i<DP;i++)
	{
		for(int j=0;j<DP;j++)
		{
			if(dp[pre][i][j]==-1) continue;
			else
			{
				int tans=0;
				int res[]={i,j,dp[pre][i][j]};
				int add=INF;
				for(int k=0;k<3;k++)
				{
					add=min(add,res[k]/bonus[k]);
				}
				for(int k=0;k<3;k++)
				{
					res[k]-=add*bonus[k];//WA Point here!
					tans+=res[k]*army[k].d;
				}
				tans+=add*max(bonus[3],def);
				//print(res[0]<<' '<<res[1]<<' '<<res[2]<<' '<<add<<' '<<tans);
				ans=max(ans,tans);
			}
		}
	}
	return ans;
}


int main()
{
	int a,b,c;
	int cas=0;
	while(input(n) && n)
	{
		if(cas) puts("");
		printf("Case %d: ",++cas);
		for(int i=0;i<3;i++)
		{
			input(a>>b>>c);
			army[i]=weapon(a,b,c);
		}
		for(int i=0;i<4;i++) input(bonus[i]);
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			trans[i]=wagon(a,b);
		}
		print(slove());
	}
	return 0;
}




