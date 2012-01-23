#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 64
#define elif else if

char number[SIZE];
int n;

int main()
{
	input(n);
	input(number);
	bool flag=true;
	for(int i=0;number[i];i++)
	{
		if(number[i]!='4' && number[i]!='7')
		{
			flag=false;
			break;
		}
	}
	if(!flag) print("NO");
	else
	{
		int sumup=0,sumdown=0;
		for(int i=0;i<n/2;i++)
		{
			sumdown+=number[i]-'0';
			sumup+=number[n-1-i]-'0';
		}
		if(sumup==sumdown) print("YES");
		else print("NO");
	}
	return 0;
}
