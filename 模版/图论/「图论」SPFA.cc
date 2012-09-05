void spfa(int st)
{
	queue<int> q;
	bitset<SIZE> visit;
	q.push(st);
	for(int i=0;i<SIZE;i++) dis[i]=INF;
	dis[st]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		visit[now]=0;
		for(int i=0;i<(int)g[now].size();i++)
		{
			int next=g[now][i].next;
			int cost=g[now][i].cost;
			if(dis[next]>dis[now]+cost)
			{
				dis[next]=dis[now]+cost;
				if(!visit[next])
				{
					visit[next]=1;
					q.push(next);
				}
			}
		}
	}
	//dis[x]为图中(st->x)的最短路径
}
