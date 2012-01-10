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
	int T;
	scanf("%d",&T);
	while(T--)
	{
		bool flag=true;
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		if(hh>=12) flag=false;
		hh%=12;
		//if(hh==0) hh=12;
		if(flag) printf("AM ");
		else printf("PM ");
		printf("%02d:%02d:%02d\n",hh,mm,ss);
	}
	return 0;
}
