//Result:1768 	Accepted	10MS	212K	G++	534B	2011-11-14 13:42:45
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128

bitset<SIZE> hause;
int n;

int main()
{
	int cas;
	input(cas);
	while(cas--)
	{
		input(n);
		hause.reset();
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j+=i) hause[j]=!hause[j];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(hause[i]) ans++;
		}
		print(ans);
	}
	return 0;
}
