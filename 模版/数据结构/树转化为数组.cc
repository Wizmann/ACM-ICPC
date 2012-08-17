void dfs(int now,int father)
{
    lson[now]=rson[now]=++ind;
    val[now]=w[now];
    for(int i=0;i<(int)g[now].size();i++)
    {
        int next=g[now][i];
        if(next!=father)
        {
            dfs(next,now);
            rson[now]=rson[next];
        }
    }
}
