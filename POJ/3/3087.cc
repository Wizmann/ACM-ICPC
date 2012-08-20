//Result:wizmann	3087	Accepted	204K	0MS	C++	1297B	

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl

typedef struct node
{
	string str;
	int step;
	
	void setnode(string t,int s)
	{
		str=t;step=s;
	}
}node;

queue<node> q;
set<string> hash;
int len;
string ans;

string cross(string &a,string &b)
{
	string res;
	for(int i=0;i<len;i++)
	{
		res+=b[i];
		res+=a[i];
	}
	return res;
}

int bfs()
{
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.str==ans) return t.step;
		if(hash.find(t.str)!=hash.end()) continue;
		else hash.insert(t.str);
		
		string ta=t.str.substr(0,len);
		string tb=t.str.substr(len,len);
		node p;
		p.setnode(cross(ta,tb),t.step+1);
		q.push(p);
		//p.setnode(cross(tb,ta),t.step+1);
		//q.push(p);
	}
	return -1;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&len);
		printf("%d ",i);
		while(!q.empty()) q.pop();
		hash.clear();
		string a,b;
		cin>>a>>b;
		node p;
		p.setnode(cross(a,b),1);
		q.push(p);
		//p.setnode(cross(b,a),1);
		//q.push(p);
		cin>>ans;
		printf("%d\n",bfs());
	}
	return 0;
}

		
