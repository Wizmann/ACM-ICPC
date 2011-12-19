//Result:261 	Accepted 	12ms 	144kb 	G++	938B	2011-12-11 22:47:15 	Wizmann
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

int main()
{
	freopen("b.txt","r",stdin);
	llint all;
	int month;
	llint t;
	while(input(all>>month))
	{
		all*=3;
		int ans=0;;
		for(int i=0;i<month;i++)
		{
			input(t);
			all-=t;
			if(all>=0) ans++;
		}
		if(ans==month) print("There are no single pretty female engineer in B**DU.");
		else print("Free after "<<ans+1<<" months.");
	}
	return 0;
}
