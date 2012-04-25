//Result:Apr 24, 2012 3:20:46 PM	Wizmann	 A - Defragmentation	 GNU C++	Accepted	 30 ms	 1400 KB
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <ctime>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 256

//#define DEBUG

int n,k;
int disk[SIZE];
vector<int> file[SIZE];
vector< pair<int,int> > ans;
bitset<SIZE> visit;

void move(int from,int to)
{
	if(from == to) return;
    ans.push_back(make_pair(from,to));
    if(disk[from])
    {
		for(int i=0;i<(int)file[disk[from]].size();i++)
		{
			if(file[disk[from]][i]==from)
			{
				file[disk[from]][i]=to;
			}
		}
	}
	swap(disk[to],disk[from]);
}

void doSwap(int now,int next)
{
	if(now==next) return;
	int ptr=-1;
	for(int i=1;i<=n;i++)
	{
		if(!disk[i])
		{
			ptr=i;
			break;
		}
	}
	move(next,ptr);
	move(now,next);
	disk[now]=0;
}

int main()
{
	freopen("a.txt","r",stdin);
	input(n>>k);
	srand(time(NULL));
	for(int i=0;i<k;i++)
	{
		int t,a;
		input(t);
		for(int j=0;j<t;j++)
		{
			input(a);
			disk[a]=i+1;
			file[i+1].push_back(a);
		}
		//sort(file[i+1].begin(),file[i+1].end());
	}
	int ptr=1;
	for(int i=1;i<=k;i++)
	{
		int now=i;
		for(int j=0;j<(int)file[now].size();j++)
		{
			doSwap(file[now][j],ptr);
			ptr++;
			
		}
	}
	print(ans.size());
	for(int i=0;i<(int)ans.size();i++)
	{
		print(ans[i].first<<' '<<ans[i].second);
	}
	#ifdef DEBUG
	for(int i=1;i<=n;i++)
	{
		printf("%d ",disk[i]);
	}
	puts("");
	#endif
	return 0;
}


		

	
