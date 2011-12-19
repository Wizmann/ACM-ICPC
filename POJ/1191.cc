//Result:wizmann	1191	Accepted	936K	0MS	G++	1657B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define N 8
#define MAX 15

inline int mul(int x){return x*x;}
inline double mul(double x){return x*x;}

int mat[N][N];
int sum[N][N][N][N];
int dp[MAX][N][N][N][N];
int cnt;

int main()
{
	freopen("input.txt","r",stdin);
	double ave=0;
	scanf("%d",&cnt);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&mat[i][j]);
			ave+=(double)mat[i][j];
		}
	}
	ave/=(double)cnt;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			for(int k=i;k<N;k++)
			{
				int s=0;
				for(int l=j;l<N;l++)
				{
					s+=mat[k][l];
					if(k==i) sum[i][j][k][l]=s;
					else sum[i][j][k][l]=s+sum[i][j][k-1][l];
					dp[0][i][j][k][l]=mul(sum[i][j][k][l]);
				}
			}
		}
	}

	for(int i=1;i<cnt;i++)
	{
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<N;k++)
			{
				for(int l=j;l<N;l++)
				{
					for(int m=k;m<N;m++)
					{
						dp[i][j][k][l][m]=1<<25;
						for(int n=j;n<l;n++)
						{
							int t=min(dp[i-1][j][k][n][m]+mul(sum[n+1][k][l][m]),
										dp[i-1][n+1][k][l][m]+mul(sum[j][k][n][m]));
							dp[i][j][k][l][m]=min(dp[i][j][k][l][m],t);
						}
						for(int n=k;n<m;n++)
						{
							int t=min(dp[i-1][j][k][l][n]+mul(sum[j][n+1][l][m]),
										dp[i-1][j][n+1][l][m]+mul(sum[j][k][l][n]));
							dp[i][j][k][l][m]=min(dp[i][j][k][l][m],t);
						}
						//printf("%d\n",dp[i][j][k][l][m]);
					}
				}
			}
		}
	}
	//printf("%d\n",dp[cnt-1][0][0][7][7]);
	double ret=sqrt((double)dp[cnt-1][0][0][7][7]/(double)cnt-mul(ave));
	printf("%.3f\n",ret);
	return 0;
}
