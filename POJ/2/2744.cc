//Result:wizmann	2744	Accepted	332K	0MS	C++	1025B
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

double ans[110];
double disTime[10010];
int check[110];
double b,v,e,f;
int n,r;

void calDis()
{
	memset(disTime,0,sizeof(disTime));
	for(int i=0;i<=check[n];i++)
	{
		disTime[i+1]=disTime[i];
		if(i>r) disTime[i+1]+=1.0/(v-e*(i-r));
		else disTime[i+1]+=1.0/(v-f*(r-i));
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		for(int i=1;i<=n;i++) input(check[i]);
		input(b>>r>>v>>e>>f);
		calDis();
		
		for(int i=1;i<=n;i++)
		{
			ans[i]=disTime[check[i]];
			for(int j=1;j<i;j++)
			{
				ans[i]=min(ans[i],ans[j]+b+disTime[check[i]-check[j]]);
			}
		}
		printf("%.4lf\n",ans[n]);
	}
	return 0;
}
		
