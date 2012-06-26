//Result:wizmann	1023	Accepted	740K	0MS	G++	756B	
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100

typedef long long llint;

int n;
bitset<SIZE> ans;

void print_ans()
{
	for(int i=n-1;i>=0;i--)
	{
		printf("%d",int(ans[i]));
	}
	puts("");
}



int main()
{
	freopen("k.txt","r",stdin);
	int T;
	llint val;
	char num[SIZE];
	input(T);
	while(T--)
	{
		ans.reset();
		llint ind=0;
		input(n>>num>>val);
		//print(val);
		for(int i=n-1;i>=0;i--)
		{
			if(val&1)
			{
				if(num[i]=='n') val++;
				ans[ind]=1;
			}
			val>>=1;
			ind++;
		}
		if(val) print("Impossible");
		else print_ans();
	}
	return 0;
}
				
		
