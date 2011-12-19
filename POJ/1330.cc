//Result:wizmann	1330	Accepted	780K	16MS	G++	660B

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl

int father[10010];
int mem[10010];
int n;

int main()
{
	freopen("input.txt","r",stdin);
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		memset(father,0,sizeof(father));
		memset(mem,0,sizeof(mem));
		scanf("%d",&n);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			father[b]=a;
		}
		
		scanf("%d%d",&a,&b);
		int t=a;
		while(t)
		{
			mem[t]=1;
			t=father[t];
		}
		t=b;
		while(t)
		{
			if(mem[t])
			{
				print(t);
				break;
			}
			else t=father[t];
		}
	}
	return 0;
}
		
