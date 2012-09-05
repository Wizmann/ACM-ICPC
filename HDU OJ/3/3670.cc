//Result:2012-08-18 14:29:32	Accepted	3670	375MS	8536K	1226 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE=(1<<16)+128,LEN=16;
struct BIT
{
	int baum[SIZE];
	inline int lowbit(int x){return (x)&(-x);}
	inline void init(){memset(baum,0,sizeof(baum));}
	inline void add(int pos,int val){while(pos<SIZE){baum[pos]+=val;pos+=lowbit(pos);}}
	inline int sum(int pos){int res=0;while(pos>0){res+=baum[pos];pos-=lowbit(pos);}return res;}
	inline int sum(int a,int b){return sum(b)-sum(a-1);}
}bit[2][16];
int main()
{
	int n,tmp,cas=1; char cmd[5];
	long long ans,add;
	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		for(int i=0;i<2;i++) for(int j=0;j<16;j++) bit[i][j].init();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			for(int j=0;j<LEN;j++) bit[(tmp&(1<<j))==0?0:1][j].add(tmp%(1<<j)+1,1);
		}
		add=ans=0;
		while(1)
		{
			scanf("%s",cmd);
			if(*cmd=='C'){scanf("%d",&tmp);add+=tmp;}
			else if(*cmd=='Q')
			{
				scanf("%d",&tmp);
				int tail=add%(1<<tmp),ptr=(add&(1<<tmp))==0?0:1;
				ans+=bit[ptr][tmp].sum((1<<tmp)-tail+1,SIZE-1)+bit[!ptr][tmp].sum(1,(1<<tmp)-tail);
			}
			else break;
		}
		cout<<"Case "<<cas++<<": "<<ans<<endl;
	}
	return 0;
}
