//Sep 11, 2011 8:00:01 AM 	Wizmann 	D - Petr# 	MS C++ 	Accepted 	110 ms 	5200 KB 

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 2010
#define pb push_back

char word[SIZE],st[SIZE],end[SIZE];
vector<string> vc;

void make_suffix_array()
{
	vc.pb("");
	char *p=word;
	int sz=strlen(word);
	while(p&&p<word+sz)
	{
		p=strstr(p,st);
		if(p)
		{
			string t(p);
			vc.pb(t);
			p++;
		}
	}
	sort(vc.begin(),vc.end());
	vc.erase(unique(vc.begin(),vc.end()),vc.end());
}



int main()
{
	//freopen("d.txt","r",stdin);
	scanf("%s%s%s",word,st,end);
	int esz=strlen(end);
	make_suffix_array();
	int stsz=strlen(st);
	int ans=0;
	int sz=vc.size();
	for(int i=1;i<sz;i++)
	{
		bool same=true;
		int ssz=vc[i].size();
		int bsz=vc[i-1].size();
		for(int j=0;j<ssz;j++)
		{
			if(j>=bsz || vc[i-1][j]!=vc[i][j]) same=false;
			if(j+1-esz<0) continue;
			string t=vc[i].substr(j+1-esz,esz);
			if(!same && j>=stsz-1 && t==end) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
	
