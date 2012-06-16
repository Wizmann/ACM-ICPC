//Result:wizmann	1830	Accepted	736K	32MS	G++	1411B	2012-06-17 01:01:45
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32

int mat[SIZE][SIZE];
int n;

/*
void printMatrix()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%d ",mat[i][j]);
		}
		puts("");
	}
	puts("");
}
* */

int gauss()
{
	int i,j;
	for(i=0,j=0;i<n&&j<n;j++)
	{
		int k=i;
		for(;k<n;k++)
		{
			if(mat[k][j]) break;
		}
		
		if(mat[k][j])
		{
			for(int l=j;l<=n;l++)
			{
				swap(mat[i][l],mat[k][l]);
			}
			//printMatrix();
			for(int l=i+1;l<n;l++)
			{
				if(l!=i && mat[l][j])
				{
					for(int r=j;r<=n;r++)
					{
						mat[l][r]^=mat[i][r];
					}
				}
			}
			i++;
		}
	}
	for(int k=i;k<n;k++)
	{
		if(mat[k][n]) return -1;
	}
	return 1<<(n-i);
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	int start[SIZE],end[SIZE];
	while(T--)
	{
		int a,b;
		input(n);
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++) input(start[i]);
		for(int i=0;i<n;i++) input(end[i]);
		for(int i=0;i<n;i++) start[i]^=end[i];
		while(input(a>>b) && a+b)
		{
			mat[b-1][a-1]=1;
		}
		for(int i=0;i<n;i++)
		{
			mat[i][n]=start[i];
			mat[i][i]=1;
		}
		int res=gauss();
		if(res==-1) print("Oh,it's impossible~!!");
		else print(res);
	}
	return 0;
}
		
