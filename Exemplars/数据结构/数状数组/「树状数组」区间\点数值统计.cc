#define SIZE 100100

inline int lowbit(int x)
{
	return x&(-x);
}

struct BIT//点更新，区间查询
{
	int baum[SIZE];
	inline void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,int val)
	{
		while(x<SIZE)
		{
			baum[x]+=val;
			x+=lowbit(x);
		}
	}
	int sum(int x)
	{
		int res=0;
		while(x>0)
		{
			res+=baum[x];
			x-=lowbit(x);
		}
		return res;
	}
	int sum(int a,int b)//查询区间和
	{
		return sum(b)-sum(a-1);
	}
};

struct SegBIT//区间更新，点查询
{
	int baum[SIZE];
	inline void init()
	{
		memset(baum,0,sizeof(baum));
	}
	void add(int x,int val)
	{
		while(x>0)
		{
			baum[x]+=val;
			x-=lowbit(x);
		}
	}
	void addseg(int a,int b,int val)//区间更新
	{
		add(a-1,-val);
		add(b,val);
	}
	int sum(int x)//点查询
	{
		int res=0;
		while(x<SIZE)
		{
			res+=baum[x];
			x+=lowbit(x);
		}
		return res;
	}
};

struct SegSegBIT//区间更新，区间查询
{
	SegBIT A;
	BIT B;
	inline void init()
	{
		A.init();
		B.init();
	}
	
	void update(int pos,int val)
	{
		A.add(pos,val);
		B.add(pos,pos*val);
	}
	
	void addseg(int a,int b,int val)//区间更新
	{
		update(b,val);
		if(a>1) update(a-1,-val);
	}

	int sum(int x)
	{
		if(x) return A.sum(x)*x+B.sum(x-1);
		else return 0;
	}

	int sum(int a,int b)//区间查询
	{
		return sum(b)-sum(a-1);
	}
};
