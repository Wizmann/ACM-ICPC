//Result:wizmann	2975	Accepted	732K	391MS	G++	601B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

int n;
int num[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	while(input(n) && n)
	{
		int xorSum=0;
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			input(num[i]);
			xorSum^=num[i];
		}
		int ans=0;
		if(!xorSum) print(0);
		else
		{
			for(int i=0;i<n;i++)
			{
				if((xorSum^num[i])<=num[i]) ans++;
			}
			print(ans);
		}
	}
	return 0;
}
