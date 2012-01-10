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

int array[1024];
int leftsum[1024],rightsum[1024];

int main()
{
	int n;
	while(input(n) && n)
	{
		memset(array,0,sizeof(array));
		memset(leftsum,0,sizeof(leftsum));
		memset(rightsum,0,sizeof(rightsum));
		
		for(int i=0;i<n;i++) scanf("%d",array+i);
		for(int i=0;i<n;i++)
		{
			leftsum[i+1]=leftsum[i]+array[i];
		}
		for(int i=n-1;i>=0;i--)
		{
			rightsum[i-1]=rightsum[i]+array[i];
		}
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(leftsum[i]==rightsum[i])
			{
				print(i+1);
				flag=false;
				break;
			}
		}
		if(flag) print("No");
	}
	return 0;
}
