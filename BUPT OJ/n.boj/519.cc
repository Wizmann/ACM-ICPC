//Result:519	Accepted	65ms	148kb	G++	807B	2012-06-22 21:11:09	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1000

int MOD[SIZE];

bool can_mod(int a,int b,int x)
{
	int ans=MOD[b]*a%x;
	return !ans;
}

void print_ans(int a,int b)
{
	for(int i=0;i<b;i++) printf("%d",a);
	puts("");
}

int slove(int x)
{
	int num=1;
	while(num<SIZE)
	{
		for(int i=1;i<=9;i++)
		{
			if(can_mod(i,num,x))
			{
				print_ans(i,num);
				return 1;
			}
		}
		num++;
	}
	return -1;
}

void init(int x)
{
	int a=1;
	for(int i=1;i<SIZE;i++)
	{
		MOD[i]=a%x;
		a=(MOD[i]*10+1)%x;
	}
}		

int main()
{
	int x;
	while(input(x))
	{
		init(x);
		int ans=slove(x);
		if(ans<0) print("No Solution");
	}
	return 0;
}
