#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back

typedef struct point
{
	int x,y;
	
	inline void setpoint(int a,int b){x=a;y=b;}
	
	friend bool operator < (const point a,const point b)
	{
		if(a.x<b.x) return true;
		else if(a.x==b.x) return a.y<b.y;
		else return false;
	}
	
	inline void printpoint(){printf("(%d,%d)\n",x,y);}
}point;

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		vector<point> vec;
		int x1,y1,x2,y2;
		int a,b;
		scanf("%d%d",&x1,&y1);
		scanf("%d%d",&x2,&y2);
		a=x1-x2;b=y1-y2;
		swap(a,b);
		point t;
		t.setpoint(x1-a,y1+b);
		vec.pb(t);
		t.setpoint(x2-a,y2+b);
		vec.pb(t);
		t.setpoint(x1+a,y1-b);
		vec.pb(t);
		t.setpoint(x2+a,y2-b);
		vec.pb(t);
		sort(vec.begin(),vec.end());
		for(int i=0;i<4;i++) vec[i].printpoint();
	}
	return 0;
}
		
