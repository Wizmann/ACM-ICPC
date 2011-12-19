//Result:wizmann	3007	Accepted	764K	829MS	G++	1575B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

typedef struct node
{
	char s[100];
	
	void setnode(char *a,char *b)
	{
		memset(s,0,sizeof(s));
		strcpy(s,a);
		strcat(s,b);
	}
	
	void setnode(char *a)
	{
		memset(s,0,sizeof(s));
		strcpy(s,a);
	}
	
	friend bool operator < (const node a,const node b)
	{
		int t=strcmp(a.s,b.s);
		if(t<0) return true;
		else return false;
	}
	
	friend bool operator == (const node a,const node b)
	{
		if(strcmp(a.s,b.s)==0) return true;
		else return false;
	}
}node;

char str[100];
int len;
set<node> st;

void strrev(char *s)
{
	int l=0,r=strlen(s)-1;
	while(l<=r)
	{
		swap(s[l],s[r]);
		l++;r--;
	}
}

void cut(int pos)
{
	node t;
	char a[100],b[100],c[100];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=0;i<=pos;i++) a[i]=str[i];
	for(int i=pos+1;i<len;i++) b[i-pos-1]=str[i];
	
	t.setnode(a,b);
	st.insert(t);
		
	t.setnode(b,a);
	st.insert(t);
	
	strcpy(c,a);
	strrev(c);
	
	t.setnode(b,c);
	st.insert(t);
	
	t.setnode(c,b);
	st.insert(t);
	
	strcpy(c,b);
	strrev(c);
	
	t.setnode(a,c);
	st.insert(t);
	
	t.setnode(c,a);
	st.insert(t);
	
	strrev(a);strrev(b);
	t.setnode(a,b);
	st.insert(t);
	
	t.setnode(b,a);
	st.insert(t);
}

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		st.clear();
		scanf("%s",str);
		len=strlen(str);
		for(int i=0;i<len-1;i++)
			cut(i);
		printf("%d\n",st.size());
		set<node>::iterator iter=st.begin();
	}
	return 0;
}
