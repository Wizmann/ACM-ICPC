//Result:1250	Accepted	0MS	212K	G++	 660B	2012-06-12 19:26:00	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int slove(int a,int b,int c=0)
{
	int ans=0;
	if(a==0&&b==0&&c==0) return 0;
	else
	{
		int ax=a%10;
		int bx=b%10;
		if(ax+bx+c>=10)
		{
			c=1;
			ans++;
		}
		else c=0;
		ans+=slove(a/10,b/10,c);
	}
	return ans;
}

int main()
{
	int a,b;
	while(input(a>>b) && a+b)
	{
		int ans=slove(a,b);
		if(!ans) print("No carry operation.");
		else if(ans==1) print(ans<<" carry operation.");
		else print(ans<<" carry operations.");
	}
	return 0;
}
