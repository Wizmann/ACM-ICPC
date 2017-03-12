vector<int> g[SIZE];
int pre[SIZE],match[SIZE];

bool deal(int nr)
{
	for(int i=0;i<(int)g[nr].size();i++)
	{
		int next=g[nr][i];
		if(match[next] == -1)
		{
			match[next]=true;
			if(pre[next] != -1 || deal(pre[next]))
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
	memset(pre,-1,sizeof(pre));
	
	for(int i=0;i<n;i++)
	{
		memset(match,-1,sizeof(match));
		if(deal(i,match))
		{
			sum++;
			ans.push_back(i);
		}
	}
	return sum;
}


////////////////////////////////////////////////////////////////////////
char visit[SIZE];
int pre[SIZE];
int g[SIZE][SIZE];

//pre[i]=x 代表二分图左边的x对应的右边的元素为i

bool deal(int x)
{
	for(int i=0;i<n;i++) if(g[x][i])
	{
		if(!visit[i])
		{
			visit[i]=1;
			if(pre[i]==-1 || deal(pre[i]))
			{
				pre[i]=x;
				return true;
			}
		}
	}
	return false;
}
				
			

int hungary()
{
	int sum=0;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
	{
		memset(visit,0,sizeof(visit));
		if(deal(i)) sum++;
	}
	return sum;
}
