/*
Data Structure?
Time Limit: 10000/5000 MS (Java/Others)    Memory Limit: 65536/65536 K (Java/Others)
Total Submission(s): 1805    Accepted Submission(s): 562

Problem Description
Data structure is one of the basic skills for Computer Science students, which is a particular way of storing and organizing data in a computer so that it can be used efficiently. Today let me introduce a data-structure-like problem for you.
Original, there are N numbers, namely 1, 2, 3...N. Each round, iSea find out the Ki-th smallest number and take it away, your task is reporting him the total sum of the numbers he has taken away.
 
Input
The first line contains a single integer T, indicating the number of test cases.
Each test case includes two integers N, K, K indicates the round numbers. Then a line with K numbers following, indicating in i (1-based) round, iSea take away the Ki-th smallest away.

Technical Specification
1. 1 <= T <= 128
2. 1 <= K <= N <= 262 144
3. 1 <= Ki <= N - i + 1
 
Output
For each test case, output the case number first, then the sum.

Sample Input

2 
3 2 
1 1 
10 3
3 9 1

Sample Output

Case 1: 3 
Case 2: 14

*/
/*
树状数组，第K大值
只能处理从1~(1<<20)的第K值问题
查询时间复杂度：O(logN)
*/

//Result:2012-10-19 13:58:44	Accepted	4217	1062MS	1504K	1057 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 300000

typedef long long llint;

struct KthBIT
{
	int baum[SIZE];
	inline int lowbit(int x){return x&(-x);}

	void clear()
	{
		memset(baum,0,sizeof(baum));
	}

	void modify(int pos,int val)
	{
		while(pos<SIZE)
		{
			baum[pos]+=val;
			pos+=lowbit(pos);
		}
	}

	int findkth(int k)
	{
		int cnt=0,cur=0;
		for(int i=18;i>=0;i--)
		{
			cur+=(1<<i);
			if(cur>SIZE || cnt+baum[cur]>=k)
			{
				cur-=(1<<i);
			}
			else cnt+=baum[cur];
		}
		return cur+1;
	}
};

int main()
{
	freopen("input.txt","r",stdin);
	int T,n,q,tmp,cas=1;
	KthBIT kb;
	input(T);
	while(T--)
	{
		llint ans=0;
		kb.clear();
		input(n>>q);
		for(int i=1;i<=n;i++)
		{
			kb.modify(i,1);
		}
		while(q--)
		{
			scanf("%d",&tmp);
			tmp=kb.findkth(tmp);
			ans+=tmp;
			kb.modify(tmp,-1);
		}
		printf("Case %d: ",cas++);
		print(ans);
	}
	return 0;
}





