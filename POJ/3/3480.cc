//Result:wizmann	3480	Accepted	240K	16MS	C++	609B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
	int T,n,inData;
	input(T);
	while(T--)
	{
		int tp=0;
		input(n);
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			input(inData);
			if(inData>1) flag=true;
			tp^=inData;
		}
		if(flag&&tp) print("John");
		else if(flag&& !tp) print("Brother");
		else if(!flag&&(n&1)) print("Brother");
		else if(!flag&& !(n&1)) print("John");
		else print("Moody \"Kuuy\" Wizmann");
	}
	return 0;
}
