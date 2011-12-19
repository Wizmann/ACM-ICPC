//Result:wizmann	1753	Accepted	712K	250MS	G++	1133B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl

const int suc[]={0x0000,0xFFFF};

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
			if(x-1>=0)
			{
				int t=(x-1)+y*4;
				g^=(1<<t);
			}
			if(x+1<4)
			{
				int t=(x+1)+y*4;
				g^=(1<<t);
			}
			if(y-1>=0)
			{
				int t=(y-1)*4+x;
				g^=(1<<t);
			}
			if(y+1<4)
			{
				int t=(y+1)*4+x;
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
			if(buffer[j]=='b')
			{
				g<<=1;
				g|=1;
			}
			else g<<=1;
		}
	}
	int ans=1<<20;
	for(int i=0;i<=0xFFFF;i++)
	{
		int t=convert(g,i);
		if(t==0x0000 || t==0xFFFF) ans=min(ans,cal(i));
	}
	if(ans>=1<<20) print("Impossible");
	else print(ans);
	return 0;
}
