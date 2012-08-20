#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 26
#define N 1024

typedef struct node
{
	string word;
	int last;
	int nr;

	node(string istr_word,int i_last,int i_nr)
	{
		word=istr_word;
		last=i_last;
		nr=i_nr;
	}

	friend bool operator < (const node& a,const node& b)
	{
		return a.word<b.word;
		//return a.word[a.word.length()-1]<b.word[b.word.length()-1];
	}
}node;

vector<node> g[SIZE];
int in[SIZE],out[SIZE];
int n,ind;
stack<string> st;
char visit[N];

bool check(int &source)
{
	int res=0;
	for(int i=0;i<SIZE;i++)
	{
		if(in[i]-out[i]==1) source=i;
		if(abs(in[i]-out[i])==1) res++;
		else if(abs(in[i]-out[i])>1) return false;
	}
	if(res==2 || res==0) return true;
	else return false;
}

void dfs(int now)
{
	int sz=g[now].size();
	for(int i=0;i<sz;i++)
	{
		if(!visit[g[now][i].nr])
		{
			visit[g[now][i].nr]=1;
			//print(g[now][i].word<<' '<<char(g[now][i].last+'a'));
			dfs(g[now][i].last);
			st.push(g[now][i].word);			
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	string str;
	string sourceStr;
	int source;
	input(T);
	while(T--)
	{
		input(n);
		ind=source=0;
		sourceStr="zzzzzzzzzzzzzzzzzzz";
		memset(visit,0,sizeof(visit));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i=0;i<SIZE;i++) g[i].clear();
		for(int i=0;i<n;i++)
		{
			input(str);
			int begin,end;
			begin=str[0]-'a';
			end=str[str.length()-1]-'a';
			g[begin].push_back(node(str,end,ind));
			ind++;
			in[begin]++;
			out[end]++;
			if(sourceStr>str)
			{
				sourceStr=str;
				source=begin;
			}
		}
		if(!check(source)) print("***");
		else
		{
			while(!st.empty()) st.pop();
			for(int i=0;i<SIZE;i++) sort(g[i].begin(),g[i].end());
			dfs(source);
			if((int)st.size()!=n) print("***");
			else
			{
				printf("%s",st.top().c_str());
				st.pop();
				while(!st.empty())
				{
					printf(".%s",st.top().c_str());
					st.pop();
				}
				print("");
			}
		}
	}
	return 0;
}
