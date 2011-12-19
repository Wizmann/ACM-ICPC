#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int min(int a,int b,int c,int d)
{
	int min=a;
	if(min>b) min=b;
	if(min>c) min=c;
	if(min>d) min=d;
	
	return min;
}

int t[6000];

int main()
{
	freopen("input.txt","r",stdin);
	
	int p2=1,p3=1,p5=1,p7=1;
	int pos=1;
	t[1]=1;
	while(t[pos]<2000000000)
	{
		t[++pos]=min(t[p2]*2,t[p3]*3,t[p5]*5,t[p7]*7);
		if(t[pos]==t[p2]*2) p2++;
		if(t[pos]==t[p3]*3) p3++;
		if(t[pos]==t[p5]*5) p5++;
		if(t[pos]==t[p7]*7) p7++;
	}
	
	int n;
	
	while(scanf("%d",&n)!=EOF&&n)
	{
		printf("The %d",n);
		if(n%10==1&&n/10%10!=1) printf("st");
		else if(n%10==2&&n/10%10!=1) printf("nd");
		else if(n%10==3&&n/10%10!=1) printf("rd");
		else printf("th");
		printf(" humble number is %d.\n",t[n]);
	}
	return 0;
}
