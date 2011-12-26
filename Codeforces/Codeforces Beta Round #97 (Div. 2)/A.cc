#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

int array[SIZE];

int main()
{
	int n;
	input(n);
	for(int i=0;i<n;i++)
	{
		int t;
		input(t);
		t--;
		array[t]=i;
	}
	
	printf("%d",array[0]+1);
	for(int i=1;i<n;i++)
	{
		printf(" %d",array[i]+1);
	}
	return 0;
}
