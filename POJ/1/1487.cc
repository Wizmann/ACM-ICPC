//Result:wizmann	1487	Accepted	784K	0MS	G++	3034B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define MAT 32
#define SIZE 1024
#define pb push_back

const double eps=1e-8;

inline bool zero(double x){return fabs(x)<eps;}

struct node
{
	int type;
	int val;
	
	node(){}
	node(int i_type,int i_val)
	{
		type=i_type;
		val=i_val;
	}
};

vector<int> g[SIZE];
double mat[MAT][MAT];
node array[SIZE];
int n;
int ind;
char *p;

void build(int now)
{
	int t,m;
	while(*p)
	{
		while(*p==' ' && *p) p++;
		if(!*p) break;
		if( (*p>='0' && *p<='9') || *p=='-')
		{
			ind++;
			sscanf(p,"%d%n",&t,&m);
			p+=m;
			array[ind]=node(0,t);
			g[now].pb(ind);
		}
		else if(*p=='(')
		{
			ind++;
			array[ind]=node(-1,0);
			p++;
			g[now].pb(ind);
			build(ind);
		}
		else if(*p==')')
		{
			p++;
			return;
		}
		else
		{
			ind++;
			array[ind]=node(1,*p-'a');
			p++;
			g[now].pb(ind);
		}
	}
}
			
void toMatrix(int now,double tp,int var)
{
	double p;
	if(g[now].size()) p=tp/g[now].size();
	
	//写入Matrix的基本原理：
	//例如a = (2 , b)
	//a的E(a)期望等于 1/2 * 2 + 1/2 * E(b)
	//所以，对于Mat[ord(a)]来说，即为：
	//		1*E(A) -1/2*E(B) = 1/2*2
	for(int i=0;i<(int)g[now].size();i++)
	{
		int x=g[now][i];
		if(array[x].type==-1)
		{
			toMatrix(x,p,var);
		}
		else
		{
			if(array[x].type==0)
			{
				mat[var][n]+=array[x].val*p;
			}
			else
			{
				mat[var][array[x].val]-=p;
			}
		}
	}
}

void init()
{
	ind=0;
	memset(array,0,sizeof(array));
	for(int i=0;i<SIZE;i++) g[i].clear();
}

void gauss_line(int a,int b,int col)
{
	double mul_a=mat[a][col];
	double mul_b=mat[b][col];
	for(int i=0;i<=n;i++)
	{
		mat[b][i]=mat[b][i]-mat[a][i]*mul_b/mul_a;
	}
}

void gauss()
{
	for(int row=0,col=0;row<n && col<n;row++,col++)
	{
		int ptr=-1;
		for(int i=row;i<n;i++)
		{
			if(!zero(mat[i][col]))
			{
				ptr=i;
				break;
			}
		}
		if(ptr==-1) continue;
		else
		{
			for(int i=0;i<=n;i++)
			{
				swap(mat[row][i],mat[ptr][i]);
			}
			for(int i=0;i<n;i++) if(i!=row)
			{
				gauss_line(row,i,col);
			}
		}
	}
}

double getans(int x)
{
	return mat[x][n]/mat[x][x];
}

bool check_exist(int x)
{
	for(int i=0;i<n;i++) if(i!=x)
	{
		if(!zero(mat[x][i])) return false;
	}
	return !zero(mat[x][x]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	char cmd[SIZE];
	while(input(n) && n)
	{
		memset(mat,0,sizeof(mat));
		printf("Game %d\n",cas++);
		for(int i=0;i<n;i++)
		{
			init();
			do
			{
				gets(cmd);
			}while(*cmd=='\0');
			p=cmd;
			while(*p!='(') p++;
			//p++;
			build(0);
			toMatrix(0,1.,i);
			mat[i][i]+=1.0;
		}
		gauss();
		for(int i=0;i<n;i++)
		{
			if(check_exist(i)) printf("Expected score for %c = %.3f\n",i+'a',getans(i));
			else printf("Expected score for %c undefined\n",i+'a');
		}
		puts("");
	}
	return 0;
}
		
