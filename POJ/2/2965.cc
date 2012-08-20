//Result:wizmann	2965	Accepted	232K	922MS	C++	1062B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl

int convert(int g,int t)
{
	for(int i=0;i<16;i++)
	{
		if(t&(1<<i))
		{
			int x=i%4;
			int y=i/4;
			//print(x<<' '<<y);
			g^=(1<<i);
			for(int i=0;i<4;i++)
			{
				int t=i*4+x;
				g^=(1<<t);
				t=i+4*y;
				g^=(1<<t);
			}
		}
	}
	return g;
}

int cal(int g)
{
	int res=0;
	while(g)
	{
		if(g%2) res++;
		g/=2;
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	int g=0;
	char buffer[16];
	for(int i=0;i<4;i++)
	{
		scanf("%s",buffer);
		for(int j=0;j<4;j++)
		{
			if(buffer[j]=='-')
			{
				g<<=1;
				g|=1;
			}
			else g<<=1;
		}
	}
	int ans=1<<20;
	int tmp=-1;
	for(int i=0;i<=0xFFFF;i++)
	{
		int t=convert(g,i);
		if(t==0xFFFF)
		{
			ans=min(ans,cal(i));
			tmp=i;
		}
	}
	if(ans>=1<<20) print("Impossible");
	else
	{
		print(ans);
		for(int i=0;i<16;i++)
		{
			if(tmp&1) print(4-i/4<<" "<<4-i%4);
			tmp>>=1;
		}
	}
	return 0;
}
