//Result:Wizmann	1623	Accepted	1420Kb	750ms	C++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010

struct node
{
	int st,end;
	node(){}
	node(int i_st,int i_end)
	{
		st=i_st;end=i_end;
	}
	friend bool operator < (const node& a,const node& b)
	{
		if(a.end!=b.end) return a.end<b.end;
		else return a.st<b.st;
	}
};

int n;
node array[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	int cas=1;
	while(T--)
	{
		printf("Case #%d: ",cas++);
		int a,b;
		input(n);
		for(int i=0;i<n;i++)
		{
			input(a>>b);
			array[i]=node(min(a,b),max(a,b));
		}
		sort(array,array+n);
		
		int ind=0;
		int day=0;
		bool flag=true;
		while(ind<n)
		{
			day=max(day,array[ind].st);
			int cross=array[ind].end-array[ind].st+1;
			if(cross&1) cross=(cross+1)>>1;
			else cross=(cross>>1)+1;
			
			day+=(cross-1);
			
			if(day>array[ind].end)
			{
				flag=false;
				break;
			}
			ind++;
			//day++;
			//print(day);
		}
		
		if(flag) print("Yes");
		else print("No");
	}
	return 0;
}
			
