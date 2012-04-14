//Result:Wizmann 1042. Central Heating	C++ Accepted 0.078 456 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256

int matrix[SIZE][SIZE];
int ans[SIZE];
int n;

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n))
	{
		int t;
		memset(matrix,0,sizeof(matrix));
		memset(ans,0,sizeof(ans));
		
		for(int i=1;i<=n;i++)
		{
			while(input(t) && t!=-1)
			{
				matrix[t][i]=1;
			}
			matrix[i][n+1]=1;
		}

		for(int i=1;i<=n;i++)
		{
			int pos=-1;
			for(int j=i;j<=n;j++)
			{
				if(matrix[j][i])
				{
					pos=j;
					break;
				}
			}

			for(int j=i;j<=n+1;j++)
			{
				swap(matrix[i][j],matrix[pos][j]);
			}

			for(int j=i+1;j<=n;j++)
			{
				if(matrix[j][i])
				{
					for(int k=i;k<=n+1;k++)
					{
						matrix[j][k]^=matrix[i][k];
					}
				}
			}
		}


		for(int i=n;i>=1;i--)
		{
			ans[i]=matrix[i][n+1];
			for(int j=i-1;j>=1;j--)
			{
				matrix[j][n+1]^=(ans[i] & matrix[j][i]);
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
				else
				{
					printf(" %d",i);
				}
			}
		}
		puts("");
	}
	return 0;
}
