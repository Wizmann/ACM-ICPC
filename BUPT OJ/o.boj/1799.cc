#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 105
#define MIN -1<<20

int mat[N][N];
int b[N];
int n;

int maxArray()
{
    int sum=0,max=MIN;
    for(int i=0;i<n;i++)
    {
        if(sum>0) sum+=b[i];
        else sum=b[i];
       
        if(sum>max) max=sum;
    }
    return max;
}

int maxmat()
{
    int res=MIN;
    for(char i=0;i<n;i++)
    {
        memset(b,0,sizeof(b));
       
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<n;k++) b[k]+=mat[j][k];
            int max=maxArray();
            if(max>res) res=max;
        }
    }
    return res;
}
           

int main()
{
    freopen("input.txt","r",stdin);
   
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
		memset(mat,0,sizeof(mat));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) scanf("%d",&mat[i][j]);
		}
	
		printf("%d\n",maxmat());
	}
    return 0;
}
