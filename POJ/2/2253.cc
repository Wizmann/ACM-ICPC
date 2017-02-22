#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

typedef struct node
{
    int x,y;
    
    void setnode()
    {
        scanf("%d%d",&x,&y);
    }
    
    double getdis(node other)
    {
        double ans=(x-other.x)*(x-other.x)+(y-other.y)*(y-other.y);
        return sqrt(ans);
    }
}node;

node array[210];
int n;
double dis[210][210];
double pos[210];
char used[210];
double ans=-1;

void dij()
{
    for(int i=0;i<n;i++) pos[i]=dis[i][0];
    pos[1]=1<<20;
    for(int i=0;i<n;i++)
    {
        double min=1<<20;
        int next;
        for(int j=0;j<n;j++)
        {
            if(!used[j]&&pos[j]<min)
            {
                min=pos[j];
                next=j;
            }
        }
        used[next]=1;
        
        for(int j=0;j<n;j++)
        {
            if(pos[j]>dis[j][next]+pos[next])
            {
                pos[j]=dis[j][next]+pos[next];
                if(dis[j][next]>ans) ans=dis[j][next];
            }
        }
    }
}
        

int main()
{
    freopen("input.txt","r",stdin);
    int cas=1;
    while(scanf("%d",&n),n)
    {
        printf("Scenario #%d\n",cas++);
        ans=-1;
        memset(used,0,sizeof(used));
        memset(array,0,sizeof(array));
        memset(dis,0,sizeof(dis));
        memset(pos,0,sizeof(pos));
        for(int i=0;i<n;i++) array[i].setnode();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                dis[i][j]=dis[j][i]=array[i].getdis(array[j]);
            }
        }
        dij();

        printf("Frog Distance = %.3f\n\n",ans+1e-6);
    }
    return 0;
}
