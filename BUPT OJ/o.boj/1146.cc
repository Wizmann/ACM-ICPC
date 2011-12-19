#include <iostream>

using namespace std;

typedef struct paper
{
	int x,y;
	
	paper(int m,int n)
	{
		x=m;y=n;
		if(y>x) swap(x,y);
	}
}paper;

int main()
{
	
	freopen("input.txt","r",stdin);
	
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	while(a&&b&&c&&d)
	{
		paper pic(a,b),back(c,d);
		int rate=100*((double)back.x/pic.x);
		if(rate>=100) rate=100;
		if(100*((double)back.y/pic.y)<rate)
		{
			rate=100*((double)back.y/pic.y);
			if(rate>=100) rate=100;
		}
		
		cout<<rate<<"%"<<endl;
		cin>>a>>b>>c>>d;
	}
	return 0;
}