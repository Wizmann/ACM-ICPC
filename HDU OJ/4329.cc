//Result:2012-08-03 15:39:21	Accepted	4329	0MS	356K	2291 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 128


struct node
{
	set<int> website;

	node()
	{
		website.clear();
	}
	inline void clear()
	{
		website.clear();
	}
	
	bool find(int x)
	{
		if(website.find(x)==website.end()) return false;
		else return true;
	}
	
	double avep(const vector<int>& vec)
	{
		double ans=0;
		int sz=vec.size();
		if(sz==0) return 0;
		for(int i=0;i<sz;i++)
		{
			ans+=(double)(i+1)/vec[i];
		}
		return ans/website.size();
	}

};

map<string,int> keyword;
map<string,int> add;
int ptr_word,ptr_add;
node array[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int T,n;
	input(T);
	int cas=1;
	char instr[10120];
	char word[128];
	while(T--)
	{
		printf("Case #%d: ",cas++);
		add.clear();
		keyword.clear();
		ptr_word=ptr_add=0;
		double ans=0.0;
		input(n);
		for(int i=0;i<n;i++)
		{
			memset(instr,0,sizeof(instr));
			array[i].clear();
			int ptr=0,t;
			do
			{
				fgets(instr,sizeof(instr),stdin);
			}while(*instr=='\n' || *instr=='\r' || *instr==' ');
			sscanf(instr+ptr,"%s%n",word,&t);
			ptr+=t;
			keyword[word]=i;
			while(sscanf(instr+ptr,"%s%n",word,&t)!=EOF)
			{
				ptr+=t;
				if(add.find(word)==add.end())
				{
					add[word]=ptr_add;
					array[i].website.insert(ptr_add);
					ptr_add++;
				}
				else array[i].website.insert(add[word]);
			}
		}

		for(int i=0;i<n;i++)
		{
			memset(instr,0,sizeof(instr));
			int ptr=0,t;
			do
			{
				fgets(instr,sizeof(instr),stdin);
			}while(*instr=='\n' || *instr=='\r' || *instr==' ');
			sscanf(instr+ptr,"%s%n",word,&t);
			ptr+=t;

			int now=keyword[word];

			vector<int> res;
			int nr=0;

			while(sscanf(instr+ptr,"%s%n",word,&t)!=EOF)
			{
				nr++;
				ptr+=t;
				int a=-1;
				if(add.find(word)!=add.end()) a=add[word];
				if(array[now].find(a))
				{
					res.push_back(nr);
				}
				
			}
			ans+=array[now].avep(res);
			//print(ans);
			//print(array[now].avep(res));
		}
		printf("%.6lf\n",ans/n);
	}
	return 0;
}


	

