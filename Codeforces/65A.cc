//Result:Jul 8, 2012 5:31:27 PM	Wizmann	 65A - Harry Potter and Three Spells	 GNU C++	Accepted	 30 ms	 1400 KB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const double X=1000;
const double inf=1e10;
const double eps=1e-9;
double g[3];
inline int zero(double x)
{
	if(fabs(x)<eps) return 0;
	else if(x>eps) return 1;
	else return -1;
}

double makePath(int a,int b)
{
	if(b==0) return 0;
	else if(a==0) return inf;
	else return (double)b/a;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	for(int i=0;i<3;i++)
	{
		input(a>>b);
		g[i]=makePath(a,b);
	}
	double now=X;
	double ans[3];
	for(int i=0;i<3;i++)
	{
		now*=g[i];
		ans[i]=now;
	}
	if(zero(now-X)>0 || ans[1]>=inf || g[1]>=inf) print("Ron");

	else print("Hermione");
	return 0;
}
