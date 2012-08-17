struct BIT_RMQ
{
	int baum[SIZE],num[SIZE];
	inline int lowbit(int x)
	{
		return x&(-x);
	}
	void init()
	{
		memset(baum,0,sizeof(baum));
		memset(num,0,sizeof(num));
	}
	int query(int a,int b)
	{
		int ans=num[b];
		while(1)
		{
			ans=max(ans,num[b]);
			if(a==b) break;
			else
			{
				b--;
				while(b-a>=lowbit(b))
				{
					ans=max(ans,baum[b]);
					b-=lowbit(b);
				}
			}
		}
		return ans;
	}

	void modify(int pos,int val)
	{
		num[pos]=val;
		for(int i=pos;i<SIZE;i+=lowbit(i))
		{
			baum[i]=max(val,baum[i]);
			for(int j=1;j<lowbit(i);j<<=1)
			{
				baum[i]=max(baum[i],baum[i-j]);
			}
		}
	}
};
