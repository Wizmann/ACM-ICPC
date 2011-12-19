//Result:267 	Accepted 	107ms 	436kb 	G++	1545B	2011-12-11 22:50:38 	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation

char str[150000];
char orz[150000];

char dict[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
int hash[128];


void init()
{
	memset(hash,0,sizeof(hash));
	for(int i=0;dict[i];i++)
	{
		hash[int(dict[i])]=i;
	}
}

int main()
{
	freopen("h.txt","r",stdin);
	init();
	memset(str,0,sizeof(str));
	while(input(str))
	{
		int tail=strlen(str)-1;
		int pos=0;
		memset(orz,0,sizeof(orz));
		
		for(int i=0;i<tail;i+=4)
		{
			char ord[3]={0};
			char ch[4]={hash[int(str[i])],hash[int(str[i+1])],hash[int(str[i+2])],hash[int(str[i+3])]};

			
			ord[2]=ch[3] | (ch[2]<<6);
			ord[1]=(ch[2]>>2) | (ch[1]<<4);
			ord[0]=(ch[0]<<2) | (ch[1]>>4);
			
			if(ch[3]==64&&ch[2]==64) ord[1]=ord[2]=0;
			else if(ch[3]==64) ord[2]=0;
			
			for(int j=0;j<3;j++) orz[pos++]=ord[j];
		}
		puts(orz);
		memset(str,0,sizeof(str));
	}
	return 0;
}
		
		
