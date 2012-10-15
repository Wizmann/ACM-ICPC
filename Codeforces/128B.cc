//Result:Wizmann	CodeForces 128B	Accepted	1900 KB	109 ms	Microsoft Visual C++ 2005+	810 B	
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char str[100100];
struct node
{
	int sz,pos;
	node(){}
	node(int isz,int ipos){sz=isz;pos=ipos;}
	void show(){for(int i=0;i<sz;i++) putchar(str[pos+i]);puts("");}
	friend bool operator < (const node &a,const node &b)
	{
		for(int i=0;i<min(a.sz,b.sz);i++) if(str[a.pos+i]!=str[b.pos+i]) return str[a.pos+i]>str[b.pos+i]? true:false;
		return a.sz>b.sz;
	}
};	
int main()
{
	int xx;
	scanf("%s%d",str,&xx);
	int len=strlen(str);
	priority_queue<node> pq;
	for(int i=0;i<len;i++) pq.push(node(1,i));
	while(!pq.empty()){node now=pq.top();pq.pop();xx--;if(!xx){now.show();break;}else if(now.pos+now.sz+1<=len) pq.push(node(now.sz+1,now.pos));}
	if(xx) puts("No such line.");
	return 0;
}
