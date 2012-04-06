//Result:Wizmann 	2194 	Accepted 	GNU C++ 	1.33k 	2280 ms 	16800 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000000
#define MOD 1000000007LL

typedef long long llint;

int d[SIZE]={0};//num->position
int preD[SIZE]={0};//position->num

void init()
{
	int Bn[SIZE]={0};
	int prim[SIZE]={0};
	d[1]=1;d[2]=2;
	for(int i=0;i<SIZE;i++)	Bn[i]=i;
	Bn[2]=4;
 
	for(int i=2;i<SIZE;i++)
	{
		if(!prim[i])
		{
			for(int j=1;i*j<SIZE;j++)
			{
				if(prim[i*j]==0) prim[i*j]=i;
			}
		}
	}
	
	int B=2;
	for(int j=2;j<SIZE;j++)
	{
		int k=B;B=SIZE;     //k代表已经找到的an
		while(k!=1)
		{
			int p=prim[k];

			while(d[Bn[p]]!=0&&Bn[p]+p<SIZE)//更新Bn[]
			Bn[p]+=p;
   
			B=B>Bn[p]?Bn[p]:B;
			while(k%p==0) k=k/p;     //去除k的最小因子，继续比较
		}
		d[B]=j+1;
	}
	for(int i=1;i<SIZE;i++)
	{
		preD[d[i]]=i;
	}
}

int pwdLen(int x)
{
	int ans=0;
	while(x)
	{
		ans++;
		x/=10;
	}
	return ans;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T,n;
	int score[10]={0};
	init();
	
	input(T);
	while(T--)
	{
		llint ans=0;
		input(n);
		for(int i=0;i<6;i++) scanf("%d",score+i+1);
		
		for(int i=1;i<n;i++)
		{
			int pwd=preD[i];
			int len=pwdLen(pwd);
			ans+=(llint)score[len]*pwd;
			//print(score[len]<<' '<<pwd);
			ans%=MOD;
		}
		print(ans);
	}
    return 0;
}
