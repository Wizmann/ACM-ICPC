//Result:2012-09-21 12:32:03	Accepted	3714	562MS	616K	1149 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 10240
#define eps 1e-8
#define inf 1e128

inline double mul(double x){return x*x;}

struct node
{
	int a,b,c;
	node(){}
	node(int ia,int ib,int ic)
	{
		a=ia;b=ib;c=ic;
	}

	inline double getval(double x) const
	{
		return mul(x)*(double)a+x*(double)b+(double)c;
	}
};

node array[SIZE];
int n;

double tri(double x)
{
	double maxi=-inf;
	for(int i=0;i<n;i++)
	{
		maxi=max(maxi,array[i].getval(x));
	}
	return maxi;		
}

double slove()
{
	double r=1000,l=0,lt,rt,ltVal,rtVal;
	while(fabs(tri(r)-tri(l))>eps)
	{
		double mid=(r-l)/3;
		lt=l+mid;
		rt=r-mid;
		ltVal=tri(lt);
		rtVal=tri(rt);
		if(ltVal<rtVal) r=rt;
		else l=lt;
	}
	return tri(l);
}

int main()
{
	freopen("input.txt","r",stdin);
	int T,a,b,c;
	input(T);
	while(T--)
	{
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			array[i]=node(a,b,c);
		}
		printf("%.4lf\n",slove());
	}
	return 0;
}
	


