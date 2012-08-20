//Result:wizmann	1704	Accepted	252K	16MS	C++	630B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10010

int array[SIZE];
int n;

int main()
{
	int T;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=1;i<=n;i++) scanf("%d",array+i);
		sort(array,array+n+1);
		int ans=0;
		if(n&1)
		{
			for(int i=n;i>0;i-=2) ans^=(array[i]-array[i-1]-1);
		}
		else
		{
			for(int i=1;i<=n;i+=2) ans^=(array[i+1]-array[i]-1);
		}
		if(!ans) print("Bob will win");
		else print("Georgia will win");
	}
	return 0;
}


