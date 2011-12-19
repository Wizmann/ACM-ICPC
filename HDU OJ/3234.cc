//Result:2011-10-10 16:08:51	Accepted	3234	234MS	524K	2241 B	G++	Foc_Kuuy
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 20010
#define GOD n
#define pb push_back
#define mp make_pair

typedef struct node
{
	int father;
	int val;
}node;

node array[SIZE];
int n,q;

inline void init(int n)
{
	//初始化
	memset(array,0,sizeof(array));
	for(int i=0;i<=n;i++) array[i].father=i;
}

int find(int a)
{
	if(a==array[a].father) return a;
	else
	{
		int t=array[a].father;
		array[a].father=find(t);
		array[a].val^=array[t].val;
		//带权值的并查集，更新权值
	}
	return array[a].father;
}

bool Lunion(int a,int b,int v)
{
	int fa=find(a);
	int fb=find(b);
	if(fa==fb) return v==(array[a].val^array[b].val);
	//如果a<->b的边存在，则v==(a.val^FATHER ^ FATHER^b.val)==a.val^b.val
	if(fa==GOD) swap(fa,fb);
	//如果fa是上帝节点，则a是有确定值的，变换fa,fb是为了下面操作的统一
	array[fa].father=fb;//上帝节点是不能有父节点的 ;-)
	array[fa].val=(array[a].val^array[b].val^v);
	//fa->fb的权值就为a.val^b.val^v
	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	char cmd[1024];
	int cas=1;
	while(scanf("%d%d",&n,&q)!=EOF&&n&&q)
	{
		print("Case "<<cas<<":");
		cas++;
		int nr=0;
		bool err=false;
		init(n);
		for(int i=0;i<q;i++)
		{
			scanf("%s",cmd);
			if(err)
			{
				gets(cmd);
				continue;
			}
			if(*cmd=='I')
			{
				nr++;
				int x,y,v;
				gets(cmd);

				if(sscanf(cmd,"%d%d%d",&x,&y,&v)==2)
				{
					swap(y,v);
					y=GOD;
					//如果是赋值操作，就转化为a->GOD=v
				}
				
				if(!Lunion(x,y,v))
				{
					err=true;
					print("The first "<<nr<<" facts are conflicting.");
				}
			}
			else
			{
				int k;
				scanf("%d",&k);
				int ans=0;
				vector< pair<int,int> > vec;
				for(int j=0;j<k;j++)
				{
					int x;
					scanf("%d",&x);
					int rx=find(x);
					ans^=array[x].val;
					int l;
					for(l=0;l<(int)vec.size();l++)
					{
						if(vec[l].first==rx) break;
					}
					if(l==(int)vec.size()) vec.pb(mp(rx,1));
					else vec[l].second^=1;
				}
				//求一个集合的XOR值的要求是所有的节点都在一棵树上
				//所以求的值会是和Father进行XOR运算的值，如果Father节点出现两次，就XOR没了
				//余下的Father节点只会是GOD节点，因为GOD节点没有Father
				bool flag=true;
				int sz=vec.size();
				for(int j=0;j<sz;j++)
				{
					if(vec[j].second)
					{
						int rx=find(vec[j].first);
						if(rx!=GOD)
						{
							flag=false;
							break;
						}
					}
				}
				//如果找到的Father节点不是GOD，就BREAK，回报I don't know.
				if(flag) print(ans);
				else print("I don't know.");
			}
		}
		print("");
	}
	return 0;
}
