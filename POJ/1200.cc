//Result:wizmann	1200	Accepted	5328K	47MS	G++	1003B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32131177

int n,nc;
char tmpStr[SIZE];
bitset<SIZE> hash;
int alpha[256];

unsigned int Hash(char *str)
{
    unsigned int hash = 0;
 
    for(int i=0;i<n;i++)
    {
		//printf("%c",*str);
        // equivalent to: hash = 65599*hash + (*str++);
        hash = alpha[int(*(str+i))]+hash*nc;
    }
	//print("");
    return (hash & 0x7FFFFFFF)%SIZE;
}

int main()
{
	freopen("input.txt","r",stdin);
	int ans=0,alphanum=1;
	scanf("%d%d",&n,&nc);
	scanf("%s",tmpStr);
	int len=strlen(tmpStr);
	for(int i=0;tmpStr[i];i++)
	{
		if(!alpha[int(tmpStr[i])])
		{
			alpha[int(tmpStr[i])]=alphanum++;
		}
	}
	for(int i=0;i+n<=len;i++)
	{
		int hasha=Hash(tmpStr+i);
		if(!hash[hasha])
		{
			hash[hasha]=1;
			ans++;
		}
	}
	print(ans);
	return 0;
}
