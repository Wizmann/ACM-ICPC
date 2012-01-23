#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100240
#define elif else if

char a[SIZE],b[SIZE];

int main()
{
	input(a>>b);
	int ans=0;
	int diffa=0,diffb=0;
	for(int i=0;a[i];i++)
	{
		if(a[i]!=b[i])
		{
			if(a[i]=='7') diffa++;
			elif(a[i]=='4') diffb++;
		}
	}
	ans=abs(diffa-diffb)+min(diffa,diffb);
	print(ans);
	return 0;
}
