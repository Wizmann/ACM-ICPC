//Result:1079 	Accepted	131MS	308K	G++	2008B	2011-11-24 22:01:36	Wizmann 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

char hash[24][24][24];
int A,B,C;

typedef struct node
{
	int a,b,c;

	void setnode(int i_a,int i_b,int i_c)
	{
		a=i_a;b=i_b;c=i_c;
	}

	bool inHash()
	{
		return hash[a][b][c];
	}

	void insertHash()
	{
		hash[a][b][c]=1;
	}
	
	void printNode()
	{
		print(a<<' '<<b<<' '<<c);
	}
}node;

queue<node> q;

void makeNode(const node &iNode)
{
	node t;

	t=iNode;
	t.a+=t.b;
	if(t.a>A)
	{
		t.b=t.a-A;
		t.a=A;
	}
	else t.b=0;
	if(!t.inHash())
	{
		q.push(t);
		t.insertHash();
	}

	t=iNode;
	t.a+=t.c;
	if(t.a>A)
	{
		t.c=t.a-A;
		t.a=A;
	}
	else t.c=0;
	if(!t.inHash())
	{
		q.push(t);
		t.insertHash();
	}

	t=iNode;
	t.b+=t.a;
	if(t.b>B)
	{
		t.a=t.b-B;
		t.b=B;
	}
	else t.a=0;
	if(!t.inHash())
	{
		q.push(t);
		t.insertHash();
	}

	t=iNode;
	t.b+=t.c;
	if(t.b>B)
	{
		t.c=t.b-B;
		t.b=B;
	}
	else t.c=0;
	if(!t.inHash())
	{
		q.push(t);
		t.insertHash();
	}

	t=iNode;
	t.c+=t.a;
	if(t.c>C)
	{
		t.a=t.c-C;
		t.c=C;
	}
	else t.a=0;
	if(!t.inHash())
	{
		q.push(t);
		t.insertHash();
	}

	t=iNode;
	t.c+=t.b;
	if(t.c>C)
	{
		t.b=t.c-C;
		t.c=C;
	}
	else t.b=0;
	if(!t.inHash())
	{
		q.push(t);
		t.insertHash();
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(input(A>>B>>C) && A+B+C)
	{
		set<int> st;
		node t;
		t.setnode(0,0,C);
		memset(hash,0,sizeof(hash));
		while(!q.empty()) q.pop();
		q.push(t);
		while(!q.empty())
		{
			t=q.front();
			//t.printNode();
			q.pop();
			if(t.c==0 && t.a) st.insert(t.a);
			makeNode(t);
		}
		if(!st.size()) print("Poor Boy");
		else
		{
			set<int>::iterator iter=st.begin();
			printf("%d",*iter);
			iter++;
			for(;iter!=st.end();iter++)
			{
				printf(" %d",*iter);
			}
			print("");
		}
	}
	return 0;
}
