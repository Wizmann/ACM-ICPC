//Result:268 	Accepted 	156ms 	144kb 	G++	1155B	2011-12-11 22:57:28 	Wizmann
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

//#define llint long long
#define ullint unsigned long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF (1LL<<63)
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation

int main()
{
	ullint a,b;
	while(input(a>>b))
	{
		ullint sum=a*b;
		ullint l=0;
		ullint r=INF;
		while(l<=r)
		{
			ullint mid=(l+r)>>1;
			ullint t=0;
			ullint la,lb;
			if(mid%2)
			{
				lb=mid/2+1;
				la=mid/2;
			}
			else
			{
				la=lb=mid/2;
			}
			//print(la<<' '<<lb);
			if(b<lb) r=mid-1;
			else if((a-1)<la) r=mid-1;
			else
			{
				t+=(2*b-lb+1)*lb/2;
				t+=(2*(a-1)-la+1)*(la)/2;
				if(t>=sum) r=mid-1;
				else l=mid+1;
			}
		}
		print(l-1);
	}
	return 0;
}
