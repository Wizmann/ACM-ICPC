#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 301000

int father[SIZE];
int num[SIZE];
int n,m;


int findfather(int x)
{
	if(father[x]==x) return x;
	else return father[x]=findfather(father[x]);
}

void init()
{
	for(int i=0;i<SIZE;i++) father[i]=i;
	memset(num,0,sizeof(num));
}

void makeUnion(int a,int b)
{
	father[findfather(a)]=findfather(b);
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(input(n>>m))
	{
		init();
		int ans=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			makeUnion(a,b);
		}
		
		for(int i=1;i<=n;i++)
		{
			num[findfather(i)]++;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(num[i])
			{
				ans+=num[i]/8;
				num[i]%=8;
				if(num[i]>=5) ans++;
			}
		}
		
		print(ans);
	}
	return 0;
}
