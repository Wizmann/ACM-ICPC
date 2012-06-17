//Result:wizmann	2065	Accepted	876K	250MS	G++	1915B	2012-06-17 14:07:07
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

typedef long long llint;

llint p,n;
llint mat[SIZE][SIZE];
char word[SIZE];
llint ans[SIZE];

int ord(char x)
{
	if(x>='a' && x<='z') return x-'a'+1;
	else if(x=='*') return 0;
	else
	{
		print("ord() Error!");
		return -1;
	}
}

void printMatrix()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%lld ",mat[i][j]);
		}
		puts("");
	}
}

void initMatrix()
{
	memset(mat,0,sizeof(mat));
	for(int i=0;i<n;i++)
	{
		llint x=1;
		for(int j=0;j<n;j++)
		{
			mat[i][j]=x;
			x*=(i+1);
			x%=p;
		}
		mat[i][n]=ord(word[i])%p;
	}
}

void gauss_line(int a,int b,int col)
{
	llint ax=mat[a][col];
	llint bx=mat[b][col];
	for(int i=0;i<=n;i++)
	{
		mat[b][i]=((mat[b][i]*ax-mat[a][i]*bx)%p+p)%p;
	}
}

llint find(int a,int b)
{
	int res=1;
	while(a*res%p!=b) res++;
	return res;
}
	

void gauss()
{
	memset(ans,0,sizeof(ans));
	int row,col;
	for(row=col=0;row<n && col<n;col++)
	{
		int ptr=-1;
		for(int i=row;i<n;i++)
		{
			if(mat[i][col])
			{
				ptr=i;
				break;
			}
		}
		//print(ptr);
		if(ptr!=-1)
		{
			for(int i=0;i<=n;i++)
			{
				swap(mat[ptr][i],mat[row][i]);
			}
			for(int i=0;i<n;i++)
			{
				if(i!=row && mat[i][col])
				{
					gauss_line(row,i,col);
				}
			}
			row++;
		}
	}
	//printMatrix();
	for(int i=0;i<n;i++)
	{
		ans[i]=find(mat[i][i],mat[i][n])%p;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		input(p);
		scanf("%s",word);
		n=strlen(word);
		initMatrix();
		gauss();
		for(int i=0;i<n;i++)
		{
			if(i) printf(" ");
			printf("%lld",ans[i]);
		}
		puts("");
	}
	return 0;
}
