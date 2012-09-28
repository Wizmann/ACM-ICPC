struct matrix
{
	int y,x;
	long long m[101][101];
	matrix(){memset(m,0,sizeof(m));y=0,x=0;}
	matrix(int a,int b):y(a),x(b){memset(m,0,sizeof(m));}
	void init1(){for(int i=0;i<y;i++) m[i][i]=1;}

	friend matrix operator * (matrix a,matrix b)
	{
		matrix c(a.y,b.x);
		for(int i=0;i<a.y;i++)
		{
			for(int j=0;j<a.x;j++)
			{
				c.m[i][j]=0;
				for(int k=0;k<b.x;k++)
				{
					c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
				}
			}
		}
		return c;
	}

	friend matrix operator ^ (matrix a,int k)
	{
		matrix res(a.y,a.x);
		res.init1();
		while(k)
		{
			if(k&1) res=res*a;
			a=a*a;k>>=1;
		}
		return res;
	}
	long long sum()
	{
		long long res=0;
		for(int i=0;i<y;i++)
		{
			for(int j=0;j<x;j++) res=(res+m[i][j])%MOD;
		}
		return res;
	}
};
