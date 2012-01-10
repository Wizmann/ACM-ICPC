#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl


const long long mat[2][2]={{1,1},{1,0}};

long long res[2][2];
long long MOD;

void mul(long long a[][2],const long long b[][2])
{
	long long temp[4];
	temp[0]=(a[0][0]*b[0][0])%MOD+(a[0][1]*b[1][0])%MOD;
	temp[1]=(a[0][0]*b[0][1])%MOD+(a[0][1]*b[1][1])%MOD;
	temp[2]=(a[1][0]*b[0][0])%MOD+(a[1][1]*b[1][0])%MOD;
	temp[3]=(a[1][0]*b[0][1])%MOD+(a[1][1]*b[1][1])%MOD;
	
	a[0][0]=temp[0]%MOD;
	a[0][1]=temp[1]%MOD;
	a[1][0]=temp[2]%MOD;
	a[1][1]=temp[3]%MOD;
}

void fab(long long n)
{
	if(n==1) return;
	else
	{
		if(n%2==0)
		{
			fab(n/2);
			mul(res,res);
		}
		else
		{
			fab(n/2);
			mul(res,res);
			mul(res,mat);
		}
	}
}

int main()
{
	freopen("D.txt","r",stdin);
	long long T;
	input(T);
	while(T--)
	{
		long long n;
		scanf("%lld%lld",&n,&MOD);
		if(n==0) puts("0");
		else
		{
			res[0][0]=res[0][1]=res[1][0]=1;
			res[1][1]=0;
			fab(n);
			printf("%lld\n",res[0][1]%MOD);
		}
	}
	return 0;
}
