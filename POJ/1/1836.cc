//Result:wizmann	1836	Accepted	220K	47MS	C++	998B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using std::set;

#define eps 1e-6
#define ext 1e6
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

int left[1200],right[1200];
int g[1200],n;

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	double t;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&t);
		g[i]=(int)ext*(t+eps);
	}
	
	set<int> s;
	set<int>::iterator iter;
	s.insert(g[0]);
	left[0]=1;
	for(int i=1;i<n;i++)
	{
		iter=s.end();--iter;
		if(*iter<g[i]) s.insert(g[i]);
		else
		{
			iter=s.lower_bound(g[i]);
			s.erase(iter);
			s.insert(g[i]);
		}
		left[i]=s.size();
	}
	
	s.clear();
	s.insert(g[n-1]);
	right[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		iter=s.end();--iter;
		if(*iter<g[i]) s.insert(g[i]);
		else
		{
			iter=s.lower_bound(g[i]);
			s.erase(iter);
			s.insert(g[i]);
		}
		right[i]=s.size();
	}
	
	int ans=-1;
	for(int i=0;i<n-1;i++) ans=max(ans,left[i]+right[i+1]);
	printf("%d\n",n-ans);
	return 0;
}	
