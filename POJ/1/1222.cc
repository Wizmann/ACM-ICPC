//Result:wizmann	1222	Accepted	748K	16MS	G++	2095B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

#define SIZE 30
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define W 6
#define L 5

#define DEBUG

const int mx[]={1,-1,0,0};
const int my[]={0,0,1,-1};

int n;
int g[W][L];
int mat[SIZE][SIZE+1];

int posToNum(int y,int x)
{
	if(y<0 || y>=L || x<0 || x>=W) return -1;
	else return y*W+x;
}

void gToMat()
{
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<W;j++)
		{
			int now=posToNum(i,j);
			mat[now][now]=1;
			for(int k=0;k<4;k++)
			{
				int tx=j-mx[k];
				int ty=i-my[k];
				int t=posToNum(ty,tx);
				if(t>=0) mat[now][t]=1;
			}
		}
	}
}

void printMatrix()
{
	#ifdef DEBUG
	print("------------------------------");
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE+1;j++)
		{
			printf("%d",mat[i][j]);
		}
		print("");
	}
	print("------------------------------");
	#endif
}

void gauss()
{
	//First Step
	for(int i=0;i<SIZE;i++)
	{
		int pos=i;
		for(pos=i;!mat[pos][i]&&pos<SIZE;pos++);//PASS:
		//for(int j=0;j<SIZE+1;j++) printf("%d ",mat[pos][j]); print("");
		
		for(int j=0;j<SIZE;j++)
		{
			if(j!=pos &&  mat[j][i])
			{
				for(int k=0;k<SIZE+1;k++)
				{
					mat[j][k]^=mat[pos][k];
				}
			}
		}
		if(i!=pos)
		{
			for(int j=0;j<SIZE+1;j++)
			{
				mat[i][j]^=mat[pos][j];
			}
			for(int j=0;j<SIZE+1;j++)
			{
				mat[pos][j]^=mat[i][j];
			}
		}
	}
}	

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	input(n);
	int cas=1;
	while(n--)
	{
		memset(g,0,sizeof(g));
		memset(mat,0,sizeof(mat));
		for(int i=0;i<L;i++)
		{
			for(int j=0;j<W;j++)
			{
				input(g[i][j]);
				if(g[i][j])
				{
					mat[posToNum(i,j)][SIZE]=1;
				}
			}
		}
		gToMat();
		gauss();
		print("PUZZLE #"<<cas++);
		for(int i=0;i<L;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(!j) printf("%d",mat[posToNum(i,j)][SIZE]);
				else printf(" %d",mat[posToNum(i,j)][SIZE]);
			}
			print("");
		}
	}
	return 0;
}
