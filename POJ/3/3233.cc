//Result:wizmann	3233	Accepted	1712K	1735MS	G++	2072B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

#define SIZE 35

int MOD;

typedef struct matrix
{
	long long m[SIZE][SIZE];
	int x,y;
	
	matrix(){x=y=0;memset(m,0,sizeof(m));}
	matrix(int a,int b){memset(m,0,sizeof(m));setMatrix(a,b);}
	matrix(int a){memset(m,0,sizeof(m));setMatrix(a);}
	
	inline void setMatrix(int a,int b){x=a;y=b;}
	inline void setMatrix(int &a){x=y=a;}
	inline void clear(){x=y=0;memset(m,0,sizeof(m));}
	inline void setOne()
	{
		if(x==y)
		{
			for(int i=0;i<x;i++) m[i][i]=1;
		}
	}
	friend matrix operator * (matrix &a,matrix &b)
    {
        matrix c(a.x,b.y);
        for(int i=0;i<b.y;i++)
        {
            for(int j=0;j<a.x;j++)
            {
                c.m[i][j]=0;
                for(int k=0;k<b.x;k++)
                {
                    c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
                }
            }
        }
        return c;
    }
	friend matrix operator ^ (matrix a,int k)
    {
        matrix res(a.x,a.y);
        res.setOne();
        while(k)
        {
            if(k&1) res=res*a;
            a=a*a;k>>=1;
        }
        return res;
    }
    friend matrix operator + (matrix a,matrix &b)
    {
		for(int i=0;i<a.y;i++)
		{
			for(int j=0;j<a.x;j++)
			{
				a.m[i][j]+=b.m[i][j];
				a.m[i][j]%=MOD;
			}
		}
		return a;
	}
	
	void printMatrix()
	{
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++)
			{
				if(j) printf(" ");
				printf("%lld",m[i][j]);
			}
			print("");
		}
	}
}matrix;

matrix MulUndSum(matrix s,int tk)
{
	if (tk==1) return s;
	matrix tmp(s.x);//用来保存答案
	matrix t;
	tmp.setOne();
	t=s^(tk>>1);
	tmp=tmp+t;
	t=MulUndSum(s,tk>>1);
	tmp=tmp*t;
	if(tk&1)
	{
		t=s^tk;
		tmp=tmp+t;
	}
	return tmp ;//返回前n项的值
}

int n,k;

int main()
{
	while(scanf("%d%d%d",&n,&k,&MOD)==3)
	{
		matrix now(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				input(now.m[i][j]);
				now.m[i][j]%=MOD;
			}
		}
		matrix ans=MulUndSum(now,k);
		ans.printMatrix();
	}
	return 0;
}
