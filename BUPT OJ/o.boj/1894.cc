#include <cstdio>
#include <cstdlib>
#include <cstring>

char word[110];
char hash[300];
char dp[110][20][2];

bool good(int pos,int last,int k)
{
	if(dp[pos][last][k]) return true;
	dp[pos][last][k]=true;
	
	if( (last>2&&k==0)  ||  (last>4&&k==1) )
	{
		//printf("FALSE\n");
		return false;
	}
	if(word[pos]=='\0') return true;
	if(word[pos]=='#') return good(pos+1,last+1,k)&&good(pos+1,1,!k);
	if(hash[word[pos]]==1)
	{
		if(k==0) return good(pos+1,last+1,0);
		else return good(pos+1,1,0);
	}
	else
	{
		if(k==1) return good(pos+1,last+1,1);
		else return good(pos+1,1,1);
	}
	return -1;
}

bool bad(int pos,int last,int k)
{	
	if(dp[pos][last][k]) return true;
	dp[pos][last][k]=true;
	
	if((last>2&&k==0)  ||  (last>4&&k==1)) return true;
	if(word[pos]=='\0') return false;
	if(word[pos]=='#') return bad(pos+1,last+1,k)&&bad(pos+1,1,!k);
	if(hash[word[pos]]==1)
	{
		if(k==0) return bad(pos+1,last+1,0);
		else return bad(pos+1,1,0);
	}
	else
	{
		if(k==1) return bad(pos+1,last+1,1);
		else return bad(pos+1,1,1);
	}
	return -1;
}

int judge()
{
	memset(dp,0,sizeof(dp));
	if(good(0,0,0)) return 0;
	memset(dp,0,sizeof(dp));
	if(bad(0,0,0)) return 1;
	else return 2;
}

int main()
{
	
	freopen("input.txt","r",stdin);
	
	hash['a']=hash['e']=hash['i']=hash['o']=hash['u']=1;
	int cas=0,res;
	while(scanf("%s",word)!=EOF)
	{
		printf("Case #%d\n",cas++);
		res=judge();
		
		if(res==0) printf("Good\n\n");
		else if(res==1) printf("Bad\n\n");
		else if(res==-1) printf("ERROR\n\n");
		else printf("Both\n\n");
	}
	return 0;
}
