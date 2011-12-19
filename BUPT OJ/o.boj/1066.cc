#include <cstdio>

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	int h,m,l;
	int ans=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d:%d%d",&h,&m,&l);
		int time=h*60+m;
		if(time>=420&&time+l<=1140) ans+=l*10;
		else if(time>=420&&time<=1140&&time+l>1140)
		{
			ans+=(time+l-1140)*5+(1140-time)*10;
		}
		else if(time<=420&&time+l>=420)
		{
			ans+=(time+l-420)*10+(420-time)*5;
		}
		else ans+=l*5;
	}
	
	printf("%d\n",ans);
	return 0;
}
