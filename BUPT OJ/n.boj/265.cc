//Result:265 	Accepted 	735ms 	7512kb 	G++	1418B	2011-12-12 23:18:33
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
#define SIZE 100010

llint n,s,q,w,r;
llint a[SIZE],f[SIZE];

void gen()
{
	llint g=s; 
	for (int i=1;i<=n;i++)
	{
		a[i]=(g/7)%10;
		if(g%2==0) g=(g/2);
		else g=(g/2)^w; 
	}
}

int main()
{
	while(input(n>>s>>w>>q>>r) && n+s+w+q+r)
	{
		// n => the len of the gen_array(a[i])
		// s => used for the function gen()
		// w => used for the function gen()
		// q,r => subarray % q == r
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		gen();
		llint ans=0;
		if(q==2 || q==5)
		{
			int sum=0;
			for (int i=1; i<=n; i++)
			{
				if (a[i]!=0) sum++;//首位不为0的时候，才有可能更新答案
				if (a[i]%q==r) ans+=sum;
				//当末位符合条件时，更新答案
			}
		}
        if (q!=2 && q!=5)
		{
			f[n]=1;
			for(int i=n-1;i>=1;i--) f[i]=(f[i+1]*10)%q;
			//预处理出 10^i % q 的值
			map<int,int> m;
			m[r]=1;
			llint x=0;
			
			for(int i=n;i>=1;i--)
			{
				x=(x+a[i]*f[i])%q;
				if(a[i]!=0) ans+=m[x];
				m[(r*f[i-1]+x)%q]++;
			}
		}
        printf("%lld\n",ans);
    }
    return 0;
}
