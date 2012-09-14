int maxi[N][16],mini[N][16];

void initRMQ()
{
	int m=floor(log2(double(n)));
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)
		{
			maxi[j][i]=maxi[j][i-1];
			if(j+(1<<(i-1))<=n) maxi[j][i]=max(maxi[j][i],maxi[j+(1<<(i-1))][i-1]);
			mini[j][i]=mini[j][i-1];
			if(j+(1<<(i-1))<=n) mini[j][i]=min(mini[j][i],mini[j+(1<<(i-1))][i-1]);
		}
	}
}

int query_max(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return max(maxi[l][m],maxi[r-(1<<m)+1][m]);
}

int query_min(int l,int r)
{
	int m=floor(log2(double(r-l+1)));
	return min(mini[l][m],mini[r-(1<<m)+1][m]);
}
