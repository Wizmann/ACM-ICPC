//Result:Accepted	1290	0MS	476K	471 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

int ans[SIZE];

void init()
{
	ans[1]=2;
	int plus=2;
	for(int i=2;i<SIZE;i++)
	{
		ans[i]=ans[i-1]+plus;
		plus+=i;
	}
}

int main()
{
	init();
	int n;
	while(input(n))
	{
		print(ans[n]);
		//print("ANS= "<<(n*n*n+5*n+6)/6);
	}
	return 0;
}
