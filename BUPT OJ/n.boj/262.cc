//Result:18645 	262 	Accepted 	352ms 	532kb 	G++	1261B	2011-12-10 14:10:58 	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#include <algorithm>
#include <string>

using namespace std;

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation

#define SIZE 50010

int pos[SIZE<<1];


int main()
{
	//TODO:
	//1.make the array to:
	//    [ (sum(0,0),0) , (sum(0,1),1) ... (sum(0,n-1),n-1) ]
	//2.qsort it by the value of sum
	//3.cal the longest subarray who has the same value
	//4.output
	freopen("c.txt","r",stdin);
	int n,T;
	input(T);
	while(T--)
	{
		memset(pos,-1,sizeof(pos));
		int ans=0;
		int sum=0,t;
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(t+sum==0) pos[SIZE]=i+1;
			else if(pos[t+sum+SIZE]==-1) pos[t+sum+SIZE]=i+1;
			else ans=max(ans,i+1-pos[t+sum+SIZE]);
			sum+=t;
		}
		ans=max(ans,pos[SIZE]);
		if(ans-1<=0) ans=-1;
		else ans--;
		print(ans);
	}
	return 0;
}
	
