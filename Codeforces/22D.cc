//Result:1876338	 Jul 8, 2012 4:49:24 PM	Wizmann	 22D - Segments	 GNU C++	Accepted	 30 ms	 1400 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024
#define INF 1<<30

struct line
{
	int a,b;
	line(){}
	line(int i_a,int i_b)
	{
		if(i_a>i_b) swap(i_a,i_b);
		a=i_a;b=i_b;
	}
};

line array[SIZE];
int n;
vector<int> ans;

int cmp(const line& x,const line &y)
{
	if(x.b==y.b) return x.a<y.a;
	else return x.b<y.b;
}

void slove()
{
	int ptr=-INF;
	for(int i=0;i<n;i++)
	{
		if(!(ptr>=array[i].a && ptr<=array[i].b))
		{
			ans.push_back(array[i].b);
			ptr=array[i].b;
		}
	}
}

int main()
{
	int a,b;
	input(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		array[i]=line(a,b);
	}
	sort(array,array+n,cmp);
	slove();
	print(ans.size());
	for(int i=0;i<(int)ans.size();i++)
	{
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}
