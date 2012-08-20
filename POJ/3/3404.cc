//Problem: 3404		User: wizmann
//Memory: 736K		Time: 0MS
//Language: G++		Result: Accepted

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 55
#define elif else if

int array[SIZE];

int main()
{
	int n;
	while(input(n) && n)
	{
		int ans=0;
		for(int i=0;i<n;i++) input(array[i]);
		sort(array,array+n);
		while(n)
		{
			if(n==1)
			{
				ans+=array[0];
				n-=1;
			}
			elif(n==2)
			{
				ans+=array[1];
				n-=2;
			}
			elif(n==3)
			{
				ans+=array[0]+array[1]+array[2];
				n-=3;
			}
			else
			{
				int a=array[0]*2+array[n-1]+array[n-2];
				int b=array[0]+2*array[1]+array[n-1];
				ans+=min(a,b);
				n-=2;
			}
		}
		print(ans);
	}
}
		
