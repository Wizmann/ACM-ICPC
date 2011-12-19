//Result: wizmann	2886	Accepted	26400K	1375MS	C++	1875B	

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define left(x) ((x<<1)+1)
#define right(x) (left(x)+1)
#define SIZE 510000
#define START 0

typedef struct child
{
	int card;
	char name[15];
	
	void setchild()
	{
		scanf("%s%d",name,&card);
	}
}child;

typedef struct node
{
	int l,r,m,val;
	
	void setnode(int a,int b,int c)
	{
		l=a;r=b;val=c;
		m=(l+r)>>1;
	}
}node;

const int maxpos[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,500001};
const int maxval[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521};

int n,k;
child q[SIZE];
node stree[SIZE<<3];

void init(int pos,int l,int r)
{
	stree[pos].setnode(l,r,r-l+1);
	
	if(l<r)
	{
		int m=(l+r)>>1;
		init(left(pos),l,m);
		init(right(pos),m+1,r);
	}
}

int insert(int pos,int p,int pass)
{
	stree[pos].val--;
	if(stree[pos].l==stree[pos].r&&(p==pass+1)) return stree[pos].l;
	else
	{
		int t=stree[left(pos)].val;
		if(t+pass>=p) return insert(left(pos),p,pass);
		else return insert(right(pos),p,pass+t);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	int t;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++) q[i].setchild();
		init(START,1,n);
		
		int res=upper_bound(maxpos,maxpos+sizeof(maxpos)-1,n)-maxpos-1;
		for(int i=1;i<=maxpos[res];i++)
		{
			t=insert(START,k,0);
			//printf("%d\n",t);
			if(i!=n)
			{
				if(q[t].card>0) k=((k+q[t].card-2)%(n-i)+(n-i))%(n-i)+1;
				//k-1是使编号从０开始，再减一个１是减去已经出队的小孩子
				else k=((k+q[t].card-1)%(n-i)+(n-i))%(n-i)+1;
				//k-1使编号从０开始，由于是向前找，所以不用减去１。。。
				//This is the WA und RE point...
			}
		}
		printf("%s %d\n",q[t].name,maxval[res]);
	}
	return 0;
}

