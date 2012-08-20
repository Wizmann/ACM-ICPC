//Result:wizmann	1521	Accepted	728K	0MS	G++	1981B	2012-04-19 23:43:48
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 30

inline int ord(char x)
{
	if(x>='A' && x<='Z') return x-'A';
	else return 26;
}

inline char chr(int x)
{
	if(x!=26) return char(x+'A');
	else return '_';
}

struct node
{
	char val;
	int left,right;
	int app;

	node(){}
	node(char i_ch)
	{
		val=i_ch;
		left=right=-1;
		app=0;
	}
	friend bool operator < (const node& a,const node& b)
	{
		return a.app>b.app;
	}
};

node array[SIZE];
int len[SIZE];
vector<node> tree;

void dfs(int x,int l=0)
{
	if(x==-1) return;
	if(tree[x].val!=-1)
	{
		len[ord(tree[x].val)]=l;
	}
	dfs(tree[x].left,l+1);
	dfs(tree[x].right,l+1);
}

int slove()
{
	tree.clear();
	memset(len,0,sizeof(len));
	priority_queue<node> pq;
	for(int i=0;i<SIZE;i++)
	{
		if(array[i].val) pq.push(array[i]);
	}
	while(pq.size()>=2)
	{
		node a=pq.top();
		pq.pop();
		node b=pq.top();
		pq.pop();
		int ptra=tree.size();
		int ptrb=ptra+1;

		tree.push_back(a);
		tree.push_back(b);

		node newNode=node(-1);
		newNode.left=ptra;
		newNode.right=ptrb;
		newNode.app=a.app+b.app;

		pq.push(newNode);
	}
	node root=pq.top();
	tree.push_back(root);
	dfs(tree.size()-1);
	int ans=0;
	for(int i=0;i<SIZE;i++)
	{
		if(array[i].val)
		{
			ans+=array[i].app*max(1,len[ord(array[i].val)]);
		}
	}
	return ans;
}

int main()
{
	string str;
	while(1)
	{
		input(str);
		if(str=="END") break;
		memset(array,0,sizeof(array));
		for(int i=0;i<(int)str.length();i++)
		{
			int pos=ord(str[i]);
			if(!array[pos].val) array[pos]=node(chr(pos));
			array[pos].app++;
		}
		int eins=str.length()*8;
		int zwei=slove();
		double drei=(double)eins/zwei;
		printf("%d %d %.1f\n",eins,zwei,drei);
	}
	return 0;
}
