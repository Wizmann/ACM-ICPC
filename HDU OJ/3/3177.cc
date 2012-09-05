//Result:Accepted	3177	0MS	316K	749 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024

struct node
{
	int move,need;
};

int n,v;
node array[SIZE];

bool cmp(const node& x,const node& y)
{
	return x.need+y.move<y.need+x.move;
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		input(v>>n);
		for(int i=0;i<n;i++) input(array[i].need>>array[i].move);
		sort(array,array+n,cmp);
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(v<array[i].move || v<array[i].need)
			{
				flag=false;
				break;
			}
			else v-=array[i].need;
		}
		if(flag) print("Yes");
		else print("No");
	}
	return 0;
}
