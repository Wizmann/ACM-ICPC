//求区间中位数

inline int mul(int x){return x*x;}
inline int left(int x){return (x<<1)+1;}
inline int right(int x){return left(x)+1;}
const int SIZE=100010;
const int LOGSIZE=30;
const int INF=1000000000;


struct node
{
	int l,r;
	node(){}
	node(int il,int ir)
	{
		l=il;r=ir;
	}

	bool get_next()
	{
		return l!=r;
	}

	bool equal(int ival)
	{
		return l==ival && r==ival;
	}
	
	int getmid()
	{
		return (l+r)>>1;
	}
	
	bool equal(int ist,int iend)
	{
		return l==ist && r==iend;
	}
};

node stree[SIZE*4];
int ST[LOGSIZE][SIZE];

const int ROOT=0;

void init_stree(int st,int end,int pos=ROOT)
{
	stree[pos]=node(st,end);
	if(st<end)
	{
		int mid=(st+end)>>1;
		init_stree(st,mid,left(pos));
		init_stree(mid+1,end,right(pos));
	}
}

void init(int n)
{
	memset(ST,0,sizeof(ST));
	memset(stree,0,sizeof(stree));
	init_stree(0,n-1);
}

void insert(int inj,int val,int pos=ROOT,int deep=0)
{
	if(stree[pos].equal(inj))
	{
		ST[deep][inj]=val;
	}
	else
	{
		int mid=stree[pos].getmid();
		if(inj<=mid) insert(inj,val,left(pos),deep+1);
		else insert(inj,val,right(pos),deep+1);
	}
}

void makeST(int pos=ROOT,int deep=0)
{
	if(!stree[pos].get_next()) return;
	else
	{
		makeST(left(pos),deep+1);
		makeST(right(pos),deep+1);
		int l=left(pos);
		int r=right(pos);
		int lst=stree[l].l,lend=stree[l].r;
		int rst=stree[r].l,rend=stree[r].r;

		for(int i=stree[pos].l;i<=stree[pos].r;i++)
		{
			if(lst>lend)
			{
				ST[deep][i]=ST[deep+1][rst];
				rst++;
			}
			else if(rst>rend)
			{
				ST[deep][i]=ST[deep+1][lst];
				lst++;
			}
			else
			{
				if(ST[deep+1][lst]<ST[deep+1][rst])
				{
					ST[deep][i]=ST[deep+1][lst];
					lst++;
				}
				else
				{
					ST[deep][i]=ST[deep+1][rst];
					rst++;
				}
			}
		}
	}
}


int query(int st,int end,int val,int pos=ROOT,int deep=0)
{
	if(stree[pos].equal(st,end))
	{
		int res=0;
		int *p=upper_bound(ST[deep]+st,ST[deep]+end+1,val);
		res+=p-(ST[deep]+st);
		return res;
	}
	else
	{
		int mid=stree[pos].getmid();
		if(end<=mid) return query(st,end,val,left(pos),deep+1);
		else if(st>mid) return query(st,end,val,right(pos),deep+1);
		else
		{
			return query(st,mid,val,left(pos),deep+1)
					+ query(mid+1,end,val,right(pos),deep+1);
		}
	}
}

void slove()
{
	input(n);
	init(n);
	int mini=INF,maxi=-INF;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(i,a);
		mini=min(a,mini);
		maxi=max(a,maxi);
	}
	makeST();

	int l=mini,r=maxi;
	scanf("%d%d",&a,&b);
	int val=(b-a)/2+1;
	while(l<=r)//用二分求答案
	{
		//print(l<<' '<<r);
		int mid=(l+r)>>1;
		if(query(a-1,b-1,mid)>=val) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}
