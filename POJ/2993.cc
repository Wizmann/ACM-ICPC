//Result:wizmann	2993	Accepted	172K	0MS	C++	1205B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define pb push_back
#define mp make_pair

char chess[50][50];

int main()
{
	freopen("input.txt","r",stdin);
	char buffer[1024];
	for(int i=0;i<=16;i+=2) strcpy(chess[i],"+---+---+---+---+---+---+---+---+");
	for(int i=1;i<=16;i+=4) strcpy(chess[i],"|...|:::|...|:::|...|:::|...|:::|");
	for(int i=3;i<=16;i+=4) strcpy(chess[i],"|:::|...|:::|...|:::|...|:::|...|");
	for(int i=0;i<=1;i++)
	{
		scanf("%s",buffer);
		scanf("%s",buffer);
		char val;
		int x,y;
		for(int j=0;buffer[j];j++)
		{
			if(buffer[j]==',') continue;
			if(buffer[j]>='A'&&buffer[j]<='Z')
			{
				val=buffer[j];
				j++;
			}
			else val='P';
			if(i) val^=32;
			x=buffer[j]-'a';
			j++;
			y=buffer[j]-'0';
			x=x*4+2;
			y=(9-y)*2-1;
			//print(x<<' '<<y);
			chess[y][x]=val;
		}
	}
	for(int i=0;i<=16;i++) print(chess[i]);
	return 0;
}
