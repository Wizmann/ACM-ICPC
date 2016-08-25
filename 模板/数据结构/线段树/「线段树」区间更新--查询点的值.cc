//如遇到较大的数据范围可以考虑离散化
#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 100010
#define left(x) ((x<<1)+1)
#define right(x) (left(x)+1)

const int ROOT=0;

struct node
{
	int l,r;
	int val;
	node(){}
	node(int il,int ir,int ival)
	{
		l=il;r=ir;
		val=ival;
	}
	
	bool under_cover(int il,int ir)
	{
		//i'm the old lover undercover.
		return il<=l && ir>=r;
	}
	
	bool equal(int x)
	{
		return x==l && x==r;
	}
	
	int getmid()
	{
		return (l+r)>>1;
	}
};

int n,q;
node stree[SIZE<<2];
int flower[SIZE][2],query[SIZE];
int ind;
map<int,int> hash;

void init_stree(int l,int r,int pos=ROOT)
{
	stree[pos]=node(l,r,0);
	if(l!=r)
	{
		int mid=(l+r)>>1;
		init_stree(l,mid,left(pos));
		init_stree(mid+1,r,right(pos));
	}
}

void insert(int l,int r,int val,int pos=ROOT)
{
	if(stree[pos].under_cover(l,r))
	{
		stree[pos].val++;
		return;
	}
	else
	{
		if(stree[pos].val>0)
		{
			stree[left(pos)].val+=stree[pos].val;
			stree[right(pos)].val+=stree[pos].val;
			stree[pos].val=0;
		}
		int mid=stree[pos].getmid();
		if(l<=mid) insert(l,r,val,left(pos));
		if(r>mid) insert(l,r,val,right(pos));
	}
}


int ask(int x,int pos=ROOT)
{
	if(stree[pos].equal(x)) return stree[pos].val;
	else
	{
		if(stree[pos].val>0)
		{
			stree[left(pos)].val+=stree[pos].val;
			stree[right(pos)].val+=stree[pos].val;
			stree[pos].val=0;
		}
		int mid=stree[pos].getmid();
		if(x<=mid) return ask(x,left(pos));
		else return ask(x,right(pos));
	}
}

