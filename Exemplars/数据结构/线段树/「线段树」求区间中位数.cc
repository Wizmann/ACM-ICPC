/*
Minimum Sum
Time Limit:5000MS  	  Memory Limit:65536KB

Description

You are given N positive integers, denoted as x1, x2 ... xN. Then give you some intervals [l, r]. For each interval, you need 
to find a number x to make |x-xl| + |x-x2| + … + |x-xr| as small as possible!

Input

The first line is an integer T (T <= 6), indicating the number of test cases. For each test case, an integer N 
(1 <= N <= 100,000) comes first. Then comes N positive integers x (1 <= x <= 1,000, 000,000) in the next line. 
Finally, comes an integer Q (1 <= Q <= 5,000), indicting there are Q queries. Each query consists of two 
integers l, r (1 <= l <= r <= N), meaning the interval you should deal with.

Output

For the k-th test case, first output “Case #k:” in a separate line. Then output Q lines, each line 
is x, which make  as small as possible. If there are several integers x satisfying it, please output 
the minimum x. Output a blank line after every test case.




Sample Input
2
5
3 6 2 2 4
2
2 5
1 3
2
7 7
2
1 2
1 1

Sample Output
Case #1:
2
3

Case #2:
7
7
*/

//Result:24 	Accepted 	1880ms 	14988kb 	G++	3238B	2012-07-23 22:46:05 	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

inline int mul(int x){return x*x;}
inline int left(int x){return (x<<1)+1;}
inline int right(int x){return left(x)+1;}
const int SIZE=100010;
const int LOGSIZE=30;
const int INF=1000000000;


struct node
{
	int l,r;
	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
	}

	bool get_next()
	{
		return l!=r;
	}

	bool equal(int ival)
	{
		return l==ival && r==ival;
	}
	
	int getmid()
	{
		return (l+r)>>1;
	}
	
	bool equal(int ist,int iend)
	{
		return l==ist && r==iend;
	}
};

node stree[SIZE*4];
int ST[LOGSIZE][SIZE];

const int ROOT=0;

void init_stree(int st,int end,int pos=ROOT)
{
	stree[pos]=node(st,end);
	if(st<end)
	{
		int mid=(st+end)>>1;
		init_stree(st,mid,left(pos));
		init_stree(mid+1,end,right(pos));
	}
}

void init(int n)
{
	memset(ST,0,sizeof(ST));
	memset(stree,0,sizeof(stree));
	init_stree(0,n-1);
}

void insert(int inj,int val,int pos=ROOT,int deep=0)
{
	if(stree[pos].equal(inj))
	{
		ST[deep][inj]=val;
	}
	else
	{
		int mid=stree[pos].getmid();
		if(inj<=mid) insert(inj,val,left(pos),deep+1);
		else insert(inj,val,right(pos),deep+1);
	}
}

void makeST(int pos=ROOT,int deep=0)
{
	if(!stree[pos].get_next()) return;
	else
	{
		makeST(left(pos),deep+1);
		makeST(right(pos),deep+1);
		int l=left(pos);
		int r=right(pos);
		int lst=stree[l].l,lend=stree[l].r;
		int rst=stree[r].l,rend=stree[r].r;

		for(int i=stree[pos].l;i<=stree[pos].r;i++)
		{
			if(lst>lend)
			{
				ST[deep][i]=ST[deep+1][rst];
				rst++;
			}
			else if(rst>rend)
			{
				ST[deep][i]=ST[deep+1][lst];
				lst++;
			}
			else
			{
				if(ST[deep+1][lst]<ST[deep+1][rst])
				{
					ST[deep][i]=ST[deep+1][lst];
					lst++;
				}
				else
				{
					ST[deep][i]=ST[deep+1][rst];
					rst++;
				}
			}
		}
	}
}


int query(int st,int end,int val,int pos=ROOT,int deep=0)
{
	if(stree[pos].equal(st,end))
	{
		int res=0;
		int *p=upper_bound(ST[deep]+st,ST[deep]+end+1,val);
		res+=p-(ST[deep]+st);
		return res;
	}
	else
	{
		int mid=stree[pos].getmid();
		if(end<=mid) return query(st,end,val,left(pos),deep+1);
		else if(st>mid) return query(st,end,val,right(pos),deep+1);
		else
		{
			return query(st,mid,val,left(pos),deep+1)
					+ query(mid+1,end,val,right(pos),deep+1);
		}
	}
}

	

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int cas=1;
	int T,n,a,b;
	input(T);
	while(T--)
	{
		printf("Case #%d:\n",cas++);
		input(n);
		init(n);
		int mini=INF,maxi=-INF;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			insert(i,a);
			mini=min(a,mini);
			maxi=max(a,maxi);
		}
		makeST();
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int l=mini,r=maxi;
			scanf("%d%d",&a,&b);
			int val=(b-a)/2+1;
			//print("val"<<' '<<val);
			while(l<=r)
			{
				//print(l<<' '<<r);
				int mid=(l+r)>>1;
				if(query(a-1,b-1,mid)>=val) r=mid-1;
				else l=mid+1;
			}
			printf("%d\n",l);
		}
		puts("");
	}
	return 0;
}
