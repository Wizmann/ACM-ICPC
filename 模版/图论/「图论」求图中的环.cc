stack<int> st;
vector<int> g[SIZE];

//使用stack存储图中的环
bool dfs(int pos,int step=0)
{
    visit[pos]=step;
    st.push(pos);
    for(int i=0;i<(int)g[pos].size();i++)
    {
        int next=g[pos][i];
        if(visit[next]==-1)
        {
            if(dfs(next,step+1)) return true;
        }
        else if(visit[next]+n-1==step)//<-这里是n元环，可以根据需要进行修改
        {
            return true;
        }
    }
    visit[pos]=-1;
    st.pop();
    return false;
}

int main()
{
	//...
	
	memset(visit,-1,sizeof(visit));
	
	//...
	return 0;
}
