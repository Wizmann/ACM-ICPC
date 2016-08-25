/*
Jewel Trading

Time Limit: 4000/2000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)

Problem Description
You want to sell a diamond to a merchant for a good price. You know so much about how merchant likes the diamond that you have even built a mathematical model for it: He will definitely accept the price p if it's not greater than a certain threshold a, but for a price p higher than it, he must have a think. The higher the price, the lower probability he will accept. Precisely, the probability that he accept price p > a is 1/(1 + (p - a)^b) , where b > 1 is a positive constant in your model.

The exact trading process is as follows: you first propose a price (a non-negative integer), then the merchant decides whether to accept. If he accepts, the trade is over and you have no chance to regret. If he does not accept, you propose another price, and so on. You know that the merchant would get angry if you always propose unacceptable high prices, so you promised that the n -th proposal (if there is) is always not greater than a (which he can accept for sure).

Write a program to find an optimal way to propose prices to maximize your expected earning (i.e. the final price).
 
Input
The input consists of several test cases. Each case is described by two positive integers n , a , and a real number b (1<=n<=100, 1<=a<=1000, 1 < b < 10) , b is given to up to three decimal places. The last test case is followed by a single zero, which should not be processed.

Output
For each test case, print the case number and the expected earning, to two decimal places. It is guaranteed that the maximal earning exists.
 

Sample Input
1 10 2 
10 33 3.14 
0
 

Sample Output
Case 1: 10.00 
Case 2: 34.41

*/

//Result:2012-10-19 10:31:43	Accepted	2984	484MS	280K	765 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int mini,n;
double b;

inline double tri(double x,double r)
{
	return (x-r)/(1.+pow(x-mini,b))+r;
}

double slove(int l,double ex)
{
	int r=10000000;
	while(l<r-1)
	{
		int lt=(l+r)/2;
		int rt=(lt+r)/2;
		double ltVal=tri(lt,ex);
		double rtVal=tri(rt,ex);
		if(ltVal>=rtVal) r=rt;
		else l=lt;
	}
	return max(tri(l,ex),tri(r,ex));
}

int main()
{
	freopen("input.txt","r",stdin);
	int cas=1;
	while(input(n>>mini>>b))
	{
		double maxn=mini;
		for(int i=0;i<n-1;i++)
		{
			maxn=slove(mini,maxn);
		}
		printf("Case %d: %.2f\n",cas++,maxn);
	}
	return 0;
}
