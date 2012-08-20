//Result:wizmann	1200	Accepted	14532K	141MS	C++	839B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 111111111

typedef long long llint;

bitset<SIZE+5> hash;
int n,m;
char str[16000100];

//Karp-Rabin算法

int main()
{
	int sz,ans=0;
	input(n>>m);
	scanf("%s",str);
	sz=strlen(str);
	str[sz]='#';
	llint val=0;
	llint t=1;
	for(int i=0;i<n;i++)
	{
		val=(val*26)+llint(str[i]-'a');
		val%=SIZE;
	}
	for(int i=0;i<n-1;i++) t=(t*26)%SIZE;
	for(int i=n;i<=sz;i++)
	{
		//print(str[i]);
		if(!hash[val])
		{
			hash[val]=1;
			ans++;
		}
		val-=(llint(str[i-n]-'a'))*t;
		val=((val*26)+(llint(str[i]-'a')))%SIZE+SIZE;
		val%=SIZE;
		//print(val);
	}

	print(ans);
	return 0;
}
		



