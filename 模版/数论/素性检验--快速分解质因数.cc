namespace NUMBER
{
	enum{SIZE=128};
	
	bool rand_init=false;
	llint rand_val[SIZE];
	llint rand_ptr;
	
	
	llint mulMod(llint a,llint b,llint n)//(a*b)%n
	{
		llint exp=a%n,res=0;
		while(b)
		{
			if(b&1)
			{
				res+=exp;
				if(res>n) res -= n;
			}
			exp <<= 1;
			if(exp>n) exp -= n;
			b>>=1;
		}
		return res;
	}

	llint powMod(llint a,llint b,llint c)//(a^b)%n
	{
		llint k = 1;
		while(b)
		{
			if(b&1) k=mulMod(k,a,c);
			a=mulMod(a,a,c);
			b>>=1;
		}
		return k;
	}

	llint fastPow(llint a,llint b)//a*b
	{
		if(b==0) return 1;
		llint x=fastPow(a,b>>1);
		x*=x;
		if(b&1) x*=a;
		return x;
	}

	llint gcd(llint a, llint b)
	{
		llint t;
		while(b)
		{
			t=a;
			a=b;
			b=t%b;
		}
		return a;
	}
	
	void init_random()
	{
		srand(time(NULL));
		for(int i=0;i<SIZE;i++)
		{
			rand_val[i]=rand();
		}
		rand_ptr=0;
	}
	
	llint randint(llint x)
	{
		if(!rand_init)
		{
			init_random();
			rand_init=true;
		}
		llint res=rand_val[rand_ptr]%x;
		rand_ptr=(rand_ptr+1)%SIZE;
		return res;
	}
	
	
	bool miller_rabin(llint n,int times=5)
	{
		if(n==2)return 1;
		if(n<2||!(n&1))return 0;

		llint a, u=n-1, x, y;
		int t=0;
		while(u%2==0)
		{
			t++;
			u/=2;
		}
		for(int i=0;i<times;i++)
		{
			a=randint(n-1)+1;
			x=powMod(a,u,n);
			for(int j=0;j<t;j++)
			{
				y=mulMod(x,x,n);
				if(y==1 && x!=1 && x!=n-1) return false;
				x=y;
			}
			if(y!=1) return false;
		}
		return true;
	}
	
	struct pollard_rho//快速因数分解
	{
		llint factor[SIZE];
		int cnt;
		
		void init(){cnt=0;}
		
		llint Pollard(llint n,llint c)
		{
			llint x,y,d,i=1,k=2;
			y=x=randint(n-1)+1;
			while(1)
			{
				i++;
				x = (mulMod(x,x,n) + c)%n;
				d = gcd((x-y+n)%n,n);
				if(d>1&&d<n)
					return d;
				if(x==y)
					return n;
				if(i==k)
				{
					k<<=1;
					y = x;
				}
			}
		}
		void Find_factor(llint n,llint c)
		{
			if(n==1) return;
			if(miller_rabin(n,5))
			{
				factor[cnt++] = n;
				return;
			}
			llint p = n;
			llint k = c;
			while(p>=n) p=Pollard(p,c--);
			Find_factor(p,k);
			Find_factor(n/p,k);
		}

		void makesort()
		{
			sort(factor,factor+cnt);
		}
	};
}
