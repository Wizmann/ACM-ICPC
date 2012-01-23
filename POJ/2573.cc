//Result:wizmann	2573	Accepted	732K	79MS	G++	1576B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define OUTSIZE 10240
#define elif else if

int array[SIZE];

int getAns(int n)
{
	int tmp[SIZE];
	int ans=0;
	memcpy(tmp,array,sizeof(tmp));
	while(n)
	{
		if(n<=3)
		{
			if(n==1) ans+=array[0];
			elif(n==2) ans+=array[1];
			elif(n==3) ans+=array[0]+array[1]+array[2];
			n=0;
		}
		else
		{
			int a=array[1]+array[0]+array[n-1]+array[1];
			int b=array[n-1]+array[0]+array[n-2]+array[0];
			ans+=min(a,b);
			n-=2;
		}
	}
	return ans;
}

int main()
{
	int n;
	while(input(n) && n)
	{
		for(int i=0;i<n;i++) input(array[i]);
		sort(array,array+n);
		print(getAns(n));
		while(n)
		{
			if(n<=3)
			{
				if(n==1)
				{
					print(array[0]);
				}
				elif(n==2)
				{
					print(array[0]<<' '<<array[1]);
				}
				elif(n==3)
				{
					print(array[0]<<' '<<array[1]);
					print(array[0]);
					print(array[0]<<' '<<array[2]);
				}
				n=0;
			}
			else
			{
				int a=array[1]+array[0]+array[n-1]+array[1];
				int b=array[n-1]+array[0]+array[n-2]+array[0];
				if(a<b)
				{
					print(array[0]<<' '<<array[1]);
					print(array[0]);
					print(array[n-1]<<' '<<array[n-2]);
					print(array[1]);
				}
				else
				{
					print(array[0]<<' '<<array[n-1]);
					print(array[0]);
					print(array[0]<<' '<<array[n-2]);
					print(array[0]);
				}
				n-=2;
			}
		}
	}
	return 0;
}
