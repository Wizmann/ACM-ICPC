//Result:2012-09-01 16:36:12	Accepted	2454	218MS	500K	716 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024 

int array[SIZE];

bool slove(int n)
{
	int ptr=n-1;
	while(ptr>=1)
	{
		sort(array,array+ptr+1,greater<int>());
		int last=array[ptr];
		if(last>ptr) return false;
		for(int i=0;i<last;i++) array[i]--;
		ptr--;
	}
	if(array[0]==0) return true;
	else return false;
}

int main()
{
	freopen("input.txt","r",stdin); 
	int T,n;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",array+i);
		}
		if(slove(n)) puts("yes");
		else puts("no");
		
		
	}
	return 0;
}
		


