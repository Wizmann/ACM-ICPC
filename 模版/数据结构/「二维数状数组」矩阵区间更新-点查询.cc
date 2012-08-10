struct SegBIT_2D
{
	SegBIT baum[SIZE];
	inline void init()
	{
		for(int i=0;i<SIZE;i++) baum[i].init();
	}
	void add(int y,int x1,int x2,int val)
	{
		while(y>0)
		{
			baum[y].addseg(x1,x2,val);
			y-=lowbit(y);
		}
	}
	void addseg(int y1,int x1,int y2,int x2,int val)
	{
		add(y1-1,x1,x2,-val);
		add(y2,x1,x2,val);
	}
	int sum(int y,int x)
	{
		int res=0;
		while(y<SIZE)
		{
			res+=baum[y].sum(x);
			y+=lowbit(y);
		}
		return res;
	}
};
