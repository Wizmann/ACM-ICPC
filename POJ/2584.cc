//Result:wizmann	2584	Accepted	724K	0MS	G++	1526B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define SIZE 24
#define N 5

typedef struct node
{
	int upper,lower;
	bool haben;
	void setnode(int i_u,int i_l)
	{
		haben=false;
		upper=i_u;
		lower=i_l;
	}
}node;

int cmp(const void *a,const void *b)
{
	node *ta=(node*)a,*tb=(node*)b;
	if(ta->lower!=tb->lower) return ta->lower-tb->lower;
	else return ta->upper-tb->upper;
}

node array[SIZE];
map<char,int> sizeMap;

void init()
{
	//S - small, M - medium, L - large, X - extra large, T - extra extra large.
	sizeMap['S']=0;
	sizeMap['M']=1;
	sizeMap['L']=2;
	sizeMap['X']=3;
	sizeMap['T']=4;
}

int main()
{
	freopen("input.txt","r",stdin);
	int n,t;
	char inStr[SIZE];
	init();
	while(1)
	{
		memset(array,0,sizeof(array));
		input(inStr);
		if(*inStr=='E') break;
		else input(n);
		for(int i=0;i<n;i++)
		{
			input(inStr);
			array[i].setnode(sizeMap[*(inStr+1)],sizeMap[*inStr]);
		}
		qsort(array,n,sizeof(node),cmp);
		int sum=n;
		for(int i=0;i<N;i++)
		{
			input(t);
			for(int j=0;j<n&&t;j++)
			{
				if(!array[j].haben&&array[j].upper>=i&&array[j].lower<=i)
				{
					//print(array[j].lower<<' '<<array[j].upper);
					array[j].haben=true;
					t--;
					sum--;
				}
			}
		}
		if(sum<=0) print("T-shirts rock!");
		else print("I'd rather not wear a shirt anyway...");
		input(inStr);
	}
	return 0;
} 
		
		
	
