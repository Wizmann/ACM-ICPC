vector<int> g[SIZE];
int pre[SIZE],match[SIZE];

bool deal(int nr)
{
	for(int i=0;i<(int)g[nr].size();i++)
	{
		int next=g[nr][i];
		if(!match[next])
		{
			match[next]=true;
			if(!pre[next] || deal(pre[next]))
			{
				pre[next]=nr;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int sum=0;
	memset(pre,0,sizeof(pre));
	
	for(int i=0;i<n;i++)
	{
		memset(match,0,sizeof(match));
		if(deal(i,match))
		{
			sum++;
			ans.push_back(i);
		}
	}
	return sum;
}
