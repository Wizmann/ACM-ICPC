inline int lowbit(int x){return (x)&(-x);}

struct BIT
{
	int baum[SIZE];
	inline void init(){memset(baum,0,sizeof(baum));}
	
	inline void add(int pos,int val)
	{
		while(pos<SIZE)
		{
			baum[pos]+=val;
			pos+=lowbit(pos);
		}
	}
	inline int sum(int pos)
	{
		int res=0;
		while(pos>0)
		{
			res+=baum[pos];
			pos-=lowbit(pos);
		}
		return res;
	}
	inline int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};

struct BIT_2D
{
	BIT baum[SIZE];
	inline void init()
	{
		for(int i=0;i<SIZE;i++) baum[i].init();
	}
	inline void add(int y,int x,int val)
	{
		while(y<SIZE)
		{
			baum[y].add(x,val);
			y+=lowbit(y);
		}
	}
	inline int sum(int y1,int x1,int y2,int x2)
	{
		int res=0;
		while(y2>0)
		{
			res+=baum[y2].sum(x1,x2);
			y2-=lowbit(y2);
		}
		y1--;
		while(y1>0)
		{
			res-=baum[y1].sum(x1,x2);
			y1-=lowbit(y1);
		}
		return res;
	}
};
