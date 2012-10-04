//Result:wizmann	3487	Accepted	252K	16MS	C++	1646B	2012-10-03 11:15:17

//稳定婚姻问题：
//有一个社团里有n个女生和n个男生，每位女生按照她的偏爱程度将男生排序，
//同时每位男生也按照自己的偏爱程度将女生排序。然后将这n个女生和n个男生配成完备婚姻。
//如果存在两位女生A和B，两位男生a和b，使得A和a结婚，B和b结婚，
//但是A更偏爱b而不是a，b更偏爱A而不是B，则这个婚姻就是不稳定的，
//A和b可能背着别人相伴而走，因为他俩都认为，与当前配偶比起来他们更偏爱各自的新伴侣。


//输入：
//n个男士姓名(a..z)，n个女士姓名(A..Z)
//n个男士喜欢的女生的优先度排名
//n个女士喜欢的男生的排名

//输出：
//稳定婚姻，按男士名字的字典序排列

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 32

int n;
int m_name[SIZE],f_name[SIZE];
int m_like[SIZE][SIZE],f_like[SIZE][SIZE];
int m_visit[SIZE],f_visit[SIZE];

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	char str[36];
	input(T);
	while(T--)
	{
		scanf("%d",&n);
		memset(m_name,0,sizeof(m_name));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			m_name[i]=*str-'a'+1;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			f_name[i]=*str-'A'+1;
		}
		
		sort(m_name,m_name+n);//重新编号，使字典序小的在先
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			for(int j=1;j<=n;j++)
			{
				m_like[i][j]=str[j+1]-'A'+1;
			}
		}

		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			for(int j=1;j<=n;j++)
			{
				f_like[i][str[j+1]-'a'+1]=n-j+1;
			}
			f_like[i][n+1]=-1;//虚拟人物，所有女生对它的喜爱度为-1
		}

		memset(m_visit,0,sizeof(m_visit));
		memset(f_visit,0,sizeof(f_visit));
		queue<int> q;
		for(int i=1;i<=n;i++) q.push(m_name[i]);
		for(int i=1;i<=n;i++) f_visit[i]=n+1;

		while(!q.empty())
		{
			int male=q.front();
			int female=m_like[male][m_visit[male]];
			if(f_like[female][male]>f_like[female][f_visit[female]])
			{
				q.pop();
				if(f_visit[female]!=n+1)
				{
					q.push(f_visit[female]);
					m_visit[f_visit[female]]++;
				}
				f_visit[female]=male;
			}
			else m_visit[male]++;
		}

		for(int i=1;i<=n;i++)
		{
			printf("%c %c\n",m_name[i]+'a'-1,m_like[m_name[i]][m_visit[i]]+'A'-1);
		}
		if(T) puts("");
	}
	return 0;
}
