//Result:wizmann	3440	Accepted	268K	235MS	C++	945B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define mul(x) ((x)*(x))
#define pi acos(-1.0)

double m,n,t,d;

int main()
{
	freopen("input.txt","r",stdin);
	int cas;
	input(cas);
	for(int i=1;i<=cas;i++)
	{
		input(m>>n>>t>>d);
		print("Case "<<i<<":");
		double area=m*n*t*t;
		double zwei=(m-1)*n*t*d+(n-1)*m*t*d-2*(m-1)*(n-1)*d*d;
		double drei=(m-1)*(n-1)*d*d*(1-pi/4);
		double vier=(m-1)*(n-1)*d*d*pi/4;
		
		zwei/=area;
		drei/=area;
		vier/=area;
		
		double eins=1.0-zwei-drei-vier;
		
		printf("Probability of covering 1 tile  = %.4lf%%\n",eins*100);
		printf("Probability of covering 2 tiles = %.4lf%%\n",zwei*100);
		printf("Probability of covering 3 tiles = %.4lf%%\n",drei*100);
		printf("Probability of covering 4 tiles = %.4lf%%\n",vier*100);
		print("");
	}
	return 0;
}
