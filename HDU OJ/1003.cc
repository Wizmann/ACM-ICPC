//HDUOJ 1003 Wizmann	G - Max Sum	Accepted	728 KB	46 ms	G++	838 B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define llint long long
#define INF (1LL<<60)

int array[SIZE];
int n;

struct node
{
	int st,end;
	llint val;
	
	node()
	{
		st=end=-1;
		val=-INF;
	}
};

int main()
{
	freopen("g.txt","r",stdin);
	int T;
	int cas=1;
	input(T);
	while(T--)
	{
		input(n);
		memset(array,0,sizeof(array));
		for(int i=0;i<n;i++) input(array[i]);
		llint tmp=0;
		int start=0;
		node ans;
		for(int i=0;i<n;i++)
		{
			if(tmp<0)
			{
				start=i;
				tmp=0;
			}
			tmp+=array[i];
			if(tmp>ans.val)
			{
				ans.st=start;
				ans.end=i;
				ans.val=tmp;
			}

		}
		printf("Case %d:\n",cas++);
		cout<<ans.val<<' '<<ans.st+1<<' '<<ans.end+1<<endl;
		if(T) print("");
	}
	return 0;
}
