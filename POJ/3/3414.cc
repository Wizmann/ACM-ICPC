//Result:wizmann	3414	Accepted	824K	0MS	G++	2421B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <iostream>

using namespace std;

#define pb push_back
#define print(x) cout<<x<<endl

int sa,sb,ans;

int hash[250][250];


class action
{
	private:
	int a,b;
	string act;
	int father,step;
	
	public:
	action()
	{
		a=b=step=0;
		father=-1;
	}
	action(int ta,int tb)
	{
		a=ta;b=tb;
		step=0;
		father=-1;
	}
	void filla(int f)
	{
		step++;
		a=sa;
		act="FILL(1)";
		father=f;
	}
	void fillb(int f)
	{
		step++;
		b=sb;
		act="FILL(2)";
		father=f;
	}
	void poura(int f)
	{
		step++;
		father=f;
		b=a+b;
		a=0;
		if(b>sb)
		{
			a=b-sb;
			b=sb;
			
		}
		act="POUR(1,2)";
	}
	void pourb(int f)
	{
		step++;
		father=f;
		a=a+b;
		b=0;
		if(a>sa)
		{
			b=a-sa;
			a=sa;
		}
		act="POUR(2,1)";
	}
	void dropa(int f)
	{
		step++;
		father=f;
		a=0;
		act="DROP(1)";
	}
	void dropb(int f)
	{
		step++;
		father=f;
		b=0;
		act="DROP(2)";
	}
	inline int getStep(){return step;}
	inline bool getAns()
	{
		//cout<<a<<" "<<b<<endl;
		if(a==ans||b==ans) return true;
		else return false;
	}
	inline int getA(){return a;}
	inline int getB(){return b;}
	inline int getFather(){return father;}
	inline string getAct(){return act;}
};

queue<action> q;
vector<action> v;

int final=1<<20;
int pos;

void bfs()
{
	action t;
	int f;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(hash[t.getA()][t.getB()]||t.getStep()>=final) continue;
		else hash[t.getA()][t.getB()]=1;
		v.pb(t);
		f=v.size()-1;
		if(t.getAns())
		{
			final=min(final,t.getStep());
			pos=f;
		}		
		
		action temp=t;
		temp.filla(f);
		q.push(temp);
		
		temp=t;
		temp.fillb(f);
		q.push(temp);
		
		temp=t;
		temp.poura(f);
		q.push(temp);
		
		temp=t;
		temp.pourb(f);
		q.push(temp);
		
		temp=t;
		temp.dropa(f);
		q.push(temp);
		
		temp=t;
		temp.dropb(f);
		q.push(temp);
	}
	if(!v[f].getAns())
	{
		print("impossible");
		return;
	}
	f=pos;
	print(v[f].getStep());
	stack<string> st;
	while(v[f].getFather()!=-1)
	{
		st.push(v[f].getAct());
		f=v[f].getFather();
	}
	while(!st.empty())
	{
		print(st.top());
		st.pop();
	}
}
		
int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d%d%d",&sa,&sb,&ans);
	action start(0,0);
	q.push(start);
	bfs();
	return 0;
}
