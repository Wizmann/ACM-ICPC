//Result: Apr 24, 2012 11:59:17 AM	Wizmann	 F - Mathematical Analysis Rocks!	 GNU C++	Accepted	 130 ms	 1800 KB
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100100

int n;
int array[SIZE];

int main()
{
	freopen("f.txt","r",stdin);
	input(n);
	int t;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		array[t]=i+1;
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(i) printf(" ");
		
		printf("%d",array[t]);
	}
	puts("");
	return 0;
}

