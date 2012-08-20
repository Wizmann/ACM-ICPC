//Result:wizmann	3781	Accepted	728K	47MS	G++	427B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int array[12];

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	while(T--)
	{
		int nr;
		input(nr);
		printf("%d ",nr);
		for(int i=0;i<10;i++) input(array[i]);
		nth_element(array,array+7,array+10);
		print(*(array+7));
	}
	return 0;
}

