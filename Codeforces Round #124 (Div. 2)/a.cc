#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define eps 1e-5

int main()
{
	double a,b,r;
	input(a>>b>>r);
	if(a<2*r || b<2*r) print("Second");
	else print("First"); 
	return 0;
}
