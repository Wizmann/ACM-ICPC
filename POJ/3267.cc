//Result:wizmann	3267	Accepted	584K	94MS	G++	1010B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define min(a,b) (a<b?a:b)

int n,length;
char mes[320];
int dp[320];

typedef struct str
{
	char s[320];
	int len;
	
	inline void setstr()
	{
		scanf("%s",s);
		len=strlen(s);
	}
}str;
str dict[620];

int getEnd(char *s,int pos)
{
	int res=0;
	int t=0;
	char *p=dict[pos].s;
	while(s[res]!='\0'&&*p!='\0')
	{
		if(s[res]==*p){res++;p++;t++;}
		else res++;
	}
	if(t!=dict[pos].len) return -1;
	else return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&length);
	scanf("%s",mes);
	for(int i=0;i<length;i++) dp[i]=length-i;
	for(int i=0;i<n;i++) dict[i].setstr();
	for(int i=length-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(dict[j].len>(length-i)) continue;
			else if(dict[j].s[0]!=mes[i]) continue;
			else
			{
				int t=getEnd(mes+i,j);
				if(t==-1) continue;
				else dp[i]=min(dp[i+t]+t-dict[j].len,dp[i]);
			}
		}
		dp[i]=min(dp[i],dp[i+1]+1);
	}
	printf("%d\n",dp[0]);
	return 0;
}
	
