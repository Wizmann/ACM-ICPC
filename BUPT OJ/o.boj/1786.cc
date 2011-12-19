//Result:1786 	Accepted	4MS	316K	G++	850B	2011-07-29 11:05:26	Wizmann 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <iostream>

using std::stack;

int m,n;
char k[10];
int len;

int dfs(int l,int ex,int base)
{
	int head=k[l]-'0';
	if(len-l==1)
	{
		if(ex<=head) return head;
		else return head+1;
	}	
	int t=0;
	int num=(ex<base?base-1:base);
	if(ex<head) t=(head-1)*pow(num,len-l-1);
	else t=(head)*pow(num,len-l-1);
	if(ex!=head) t+=dfs(l+1,ex,base);
	return t;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d%d",k,&m,&n);
		len=strlen(k);
		int ans=dfs(0,m,n)-1;
		stack<int> st;
		if(ans!=0)
		{
			while(ans>0)
			{
				st.push(ans%n);
				ans/=n;
			}
			while(!st.empty())
			{
				printf("%d",st.top());
				st.pop();
			}
			puts("");
		}
		else puts("0");
	}
	return 0;
}
			
