//Result:wizmann	1014	Accepted	824K	0MS	G++	1387B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100000

int array[12];
char dp[SIZE];

//多重背包
//w - 重量  c - 费用  amount - 数量  v - 背包大小
//By Moody _"Kuuy"_ Wizmann
void CompletePack(int w,int c,int v) 
{
	for(int i=0;i<=v;i++)  
	{  
		if(dp[i]) dp[i+w]=dp[i]+c;  
	}
}

void ZeroOnePack(int w,int c,int v)
{
	for(int i=v;i>=0;i--)
	{
		if(dp[i] && i+w<=v) dp[i+w]=dp[i]+c;
	}
}

void MultiplePack(int w,int c,int amount,int v)
{
	dp[0]=1;
	if(w*amount>=v)
	{
		CompletePack(w,c,v);
		return;
	}
	else
	{
		int k=1;  
		while(k<amount)  
		{  
			ZeroOnePack(k*w,k*c,v);  
			amount-=k;  
			k<<=2;  
		}
		ZeroOnePack(amount*w,amount*c,v);
	}
}  
  

int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	int sum=0;
	while(1)
	{
		sum=0;
		for(int i=1;i<=6;i++)
		{
			input(array[i]);
			sum+=array[i]*i;
		}
		if(!sum) break;
		print("Collection #"<<cas++<<":");

		if(sum%2) print("Can't be divided.");
		else
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=6;i++)
			{
				MultiplePack(i,i,array[i],sum/2);
				if(dp[sum/2]) break;
			}
			
			if(dp[sum/2]) print("Can be divided.");
			else print("Can't be divided.");
		}
		puts("");
	}
	return 0;
}
				
			
