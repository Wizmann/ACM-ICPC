//Result:wizmann	2345	Accepted	984K	250MS	G++	1302B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256

int mat[SIZE][SIZE];
int ans[SIZE];
int n;

int main()
{
	while(input(n))
	{
		memset(mat,0,sizeof(mat));
		memset(ans,0,sizeof(ans));
		int t;
		for(int i=1;i<=n;i++)
		{
			while(input(t) && t!=-1)
			{
				mat[t][i]=1;
			}
			mat[i][n+1]=1;
		}
		/*
		 * Sample Input
		 * 4
		 * 1 2 -1
		 * 2 3 4 -1
		 * 2 -1
		 * 4 -1
		 * 
		 * =>
		 *  Light  | Status
		 * 1 0 0 0 |	1
		 * 1 1 1 0 |	1
		 * 0 0 1 0 |	1
		 * 0 0 0 1 |	1
		 */
		 
		for(int i=1;i<=n;i++)
		{
			int pos=-1;
			for(int j=i;j<=n;j++)
			{
				if(mat[j][i]){pos=j;break;}
			}
			for(int j=i;j<=n+1;j++)
			{
				swap(mat[i][j],mat[pos][j]);
			}

			
			for(int j=i+1;j<=n;j++)
			{
				if(mat[j][i]==1)
				{
					for(int k=i;k<=n+1;k++)
					{
						mat[j][k]^=mat[i][k];
					}
				}
			}
		}
		
		for(int i=n;i>=1;i--)
		{
			ans[i]=mat[i][n+1];
			for(int j=i-1;j>=1;j--)
			{
				mat[j][n+1]^=(ans[i]*mat[j][i]);
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(ans[i])
			{
				if(flag)
				{
					printf("%d",i);
					flag=false;
				}
				else printf(" %d",i);
			}
		}
		if(flag) puts("No solution");
		else puts("");
	}
	return 0;
}
			
