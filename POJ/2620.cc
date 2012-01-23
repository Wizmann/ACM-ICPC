//Result:wizmann	2620	Accepted	1532K	125MS	G++	1360B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 101000
#define INF 1<<26
#define pb push_back

struct line
{
	int st,end;

	void setline(int a,int b)
	{
		st=min(a,b);
		end=max(a,b);
	}

	friend bool operator < (const line& a,const line& b)
	{
		if(a.st!=b.st) return a.st<b.st;
		else return a.end<b.end;
	}
};

line array[SIZE];
int m,ind;

int main()
{
	freopen("input.txt","r",stdin);
	input(m);
	ind=0;
	int a,b;
	vector<int> ans;
	while(scanf("%d%d",&a,&b)!=EOF && (a!=0 || b!=0) )
	{
		array[ind++].setline(a,b);
	}
	array[ind].setline(INF,INF);
	sort(array,array+ind);
	int maxPos=0,nowPos=0;
	int ptr=-1;
	bool flag=false;
	for(int i=0;i<=ind;i++)
	{
		if(nowPos>=m)
		{
			flag=true;
			break;
		}
		
		if(array[i].st<=nowPos)
		{
			if(array[i].end>maxPos)
			{
				maxPos=array[i].end;
				ptr=i;
			}
		}
		else
		{
			if(ptr==-1)
			{
				flag=false;
				break;
			}
			else
			{
				ans.pb(ptr);
				ptr=-1;
				nowPos=maxPos;
			}
			i--;
		}
	}
	
	if(!flag) print("No solution");
	else
	{
		print(ans.size());
		for(int i=0;i<(int)ans.size();i++)
		{
			print(array[ans[i]].st<<' '<<array[ans[i]].end);
		}
	}
	return 0;
}

