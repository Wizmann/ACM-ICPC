//Result:266 	Accepted 	106ms 	316kb 	G++	2301B	2011-12-11 22:49:36 	Wizmann
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#include <algorithm>
#include <string>

using namespace std;

#define llint long long
#define uint unsigned int
#define input(x) cin>>x
#define print(x) cout<<x<<endl
#define elif else if
#define INF 1<<25
#define eps 1e-5
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define np next_permutation

#define A 1
#define B 2
#define D 4

#define SIZE 1024

typedef struct node
{
	int father;
	int son[5];
	int res;
	vector<int> next;
	
	void __init()
	{
		father=0;
		son[A]=son[B]=son[D]=0;
		res=0;
		next.clear();
	}
}node;

node tree[SIZE];
int n;


void zip(int pos=1,int mark=1)
{
	
	int sz=tree[pos].next.size();
	for(int i=0;i<sz;i++)
	{
		zip(tree[pos].next[i],mark+1);
	}
	if(!tree[pos].res && mark%2)
	{
		if(tree[pos].son[A]) tree[pos].res=A;
		else if(tree[pos].son[D]) tree[pos].res=D;
		else if(tree[pos].son[B]) tree[pos].res=B;
		else print("ERROR OCCOR");
	}
	else if(!tree[pos].res)
	{
		if(tree[pos].son[B]) tree[pos].res=B;
		else if(tree[pos].son[D]) tree[pos].res=D;
		else if(tree[pos].son[A]) tree[pos].res=A;
		else print("ERROR OCCOR");
	}
	//if(tree[pos].son[B]) printf("B ");
	//if(tree[pos].son[A]) printf("A ");
	//if(tree[pos].son[D]) printf("D ");
	//print(pos<<' '<<mark<<' '<<tree[pos].res);
	tree[tree[pos].father].son[tree[pos].res]=1;
}

int main()
{
	/* TODO:
	 * 1.Build the tree
	 * 2.zip the leaf node to the root
	 * 3.just print the ans
	 */
	freopen("g.txt","r",stdin);
	char tmpin[4];
	int f;
	while(input(n))
	{
		for(int i=0;i<=n;i++) tree[i].__init();
		
		for(int i=2;i<=n;i++)
		{
			input(tmpin);
			if(*tmpin=='L')
			{
				input(f);
				tree[i].father=f;
				tree[f].next.pb(i);
				input(tmpin);
				tree[i].res=*tmpin-'A'+1;
			}
			else if(*tmpin=='N')
			{
				input(f);
				tree[i].father=f;
				tree[f].next.pb(i);
			}
		}
		
		zip();
		//printf("ANS: ");
		if(tree[1].res==A) print('A');
		else if(tree[1].res==B) print('B');
		else if(tree[1].res==D) print('D');
	}
	return 0;
}
			
