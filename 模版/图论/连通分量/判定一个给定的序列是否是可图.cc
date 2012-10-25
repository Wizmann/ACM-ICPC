/*
Frogs' Neighborhood
Time Limit: 5000MS		Memory Limit: 10000KB

Description
未名湖附近共有N个大小湖泊L1, L2, ..., Ln(其中包括未名湖)，每个湖泊Li里住着一只青蛙Fi(1 ≤ i ≤ N)。如果湖泊Li和Lj之间有水路相连，则青蛙Fi和Fj互称为邻居。现在已知每只青蛙的邻居数目x1, x2, ..., xn，请你给出每两个湖泊之间的相连关系。

Input
第一行是测试数据的组数T(0 ≤ T ≤ 20)。每组数据包括两行，第一行是整数N(2 < N < 10)，第二行是N个整数，x1, x2,..., xn(0 ≤ xi ≤ N)。

Output
对输入的每组测试数据，如果不存在可能的相连关系，输出"NO"。否则输出"YES"，并用N×N的矩阵表示湖泊间的相邻关系，即如果湖泊i与湖泊j之间有水路相连，则第i行的第j个数字为1，否则为0。每两个数字之间输出一个空格。如果存在多种可能，只需给出一种符合条件的情形。相邻两组测试数据之间输出一个空行。

Sample Input
3
7
4 3 1 5 4 2 1 
6
4 3 1 4 2 0 
6
2 3 1 1 2 1 
Sample Output
YES
0 1 0 1 1 0 1 
1 0 0 1 1 0 0 
0 0 0 1 0 0 0 
1 1 1 0 1 1 0 
1 1 0 1 0 1 0 
0 0 0 1 1 0 0 
1 0 0 0 0 0 0 

NO

YES
0 1 0 0 1 0 
1 0 0 1 1 0 
0 0 0 0 0 1 
0 1 0 0 0 0 
1 1 0 0 0 0 
0 0 1 0 0 0 
*/


/*
* Havel-Hakimi定理
    * 判定一个给定的序列是否是可图的。
    * 判定过程
      1. 对当前数列排序，使其呈递减
      2. 从S[2] 开始对其后S[1]个数字-1
      3. 一直循环直到当前序列出现负数（即不是可图的情况）或者当前序列全为0 （可图）时退出
*/


//Result:wizmann	1659	Accepted	736K	0MS	G++	1168B	2012-09-19 16:11:12
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 12

int main()
{
	freopen("input.txt","r",stdin);
	int T,n;
	pair<int,int> array[SIZE];
	int g[SIZE][SIZE];
	input(T);
	while(T--)
	{
		memset(g,0,sizeof(g));
		input(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&(array[i].first));
			array[i].second=i;
		}
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(!flag) break;
			sort(array,array+n,greater<pair<int,int> >());
			if(array[0].first>n-1)
			{
				flag=false;
				break;
			}
			
			for(int j=1;j<=array[0].first;j++)
			{
				array[j].first--;
				if(array[j].first<0)
				{
					flag=false;
					break;
				}
				g[array[0].second][array[j].second]=g[array[j].second][array[0].second]=1;
			}
			array[0].first=0;
		}

		if(flag)
		{
			puts("YES");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(j) printf(" ");
					printf("%d",g[i][j]);
				}
				puts("");
			}
		}
		else puts("NO");
		puts("");
	}
	return 0;
}

