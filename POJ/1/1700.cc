//Result:wizmann	1700	Accepted	260K	0MS	C++	757B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define elif else if

char array[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int T,n;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++) scanf("%d",array+i);
		sort(array,array+n);
		int ans=0;
		while(n)
		{
			if(n==1)
			{
				n--;
				ans+=array[0];
			}
			elif(n==2)
			{
				n-=2;
				ans+=array[1];
			}
			elif(n==3)
			{
				n-=3;
				ans+=array[0]+array[1]+array[2];
			}
			else
			{
				ans+=min(2*array[0]+array[n-1]+array[n-2],array[0]+2*array[1]+array[n-1]);
				n-=2;
			}
		}
		print(ans);
	}
	return 0;
}
