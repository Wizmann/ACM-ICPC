#include <cstdio>
#include <cstdlib>
#include <cstring>
 
char mat[12][12];
int x,y;
 
const int mx[4]={1,-1,0,0};
const int my[4]={0,0,1,-1};
 
int main()
{
	//freopen("input.txt","r",stdin);
	int ans=0;
	scanf("%d%d",&y,&x);
	for(int i=0;i<y;i++) scanf("%s",mat[i]);
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			if(mat[i][j]=='P')
			{
				for(int k=0;k<4;k++)
				{
					if(i+my[k]>=0&&i+my[k]<y&&j+mx[k]>=0&&j+mx[k]<x)
					{
						if(mat[i+my[k]][j+mx[k]]=='W')
						{
							ans++;
							mat[i+my[k]][j+mx[k]]='.';
							mat[i][j]='.';
							break;
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
