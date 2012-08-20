//Result:wizmann	2121	Accepted	744K	32MS	G++	2062B
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define BUFFER 1024

map<string,int> nummer;
vector<string> innum;

void init()
{
	nummer.clear();
	nummer["zero"]=0;
	nummer["one"]=1;
	nummer["two"]=2;
	nummer["three"]=3;
	nummer["four"]=4;
	nummer["five"]=5;
	nummer["six"]=6;
	nummer["seven"]=7;
	nummer["eight"]=8;
	nummer["nine"]=9;
	nummer["ten"]=10;
	nummer["eleven"]=11;
	nummer["twelve"]=12;
	nummer["thirteen"]=13;
	nummer["fourteen"]=14;
	nummer["fifteen"]=15;
	nummer["sixteen"]=16;
	nummer["seventeen"]=17;
	nummer["eighteen"]=18;
	nummer["nineteen"]=19;
	nummer["twenty"]=20;
	nummer["thirty"]=30;
	nummer["forty"]=40;
	nummer["fifty"]=50;
	nummer["sixty"]=60;
	nummer["seventy"]=70;
	nummer["eighty"]=80;
	nummer["ninety"]=90;
	nummer["hundred"]=100;
	nummer["thousand"]=1000;
	nummer["million"]=1000000;
}

int slove()
{
	int sig=1,res=0;
	int ptr=0,tmp=0;
	if(innum[ptr]=="negative")
	{
		sig=-1;
		ptr++;
	}
	//if(innum.size()-ptr==1) return sig*nummer[innum[ptr]];
	for(/**/;ptr<(int)innum.size();/**/)
	{
		if(nummer[innum[ptr]]<10)
		{
			if(ptr+1<(int)innum.size() && innum[ptr+1]=="hundred")
			{
				tmp+=nummer[innum[ptr]]*100;
				ptr+=2;
			}
			else
			{
				tmp+=nummer[innum[ptr]];
				ptr++;
			}
		}
		else if(nummer[innum[ptr]]<1000)
		{
			tmp+=nummer[innum[ptr]];
			ptr++;
		}
		else
		{
			res+=tmp*nummer[innum[ptr]];
			tmp=0;
			ptr++;
		}
	}
	res+=tmp;
	return int(sig*res);
}
		
	

int main()
{
	freopen("input.txt","r",stdin);
	init();
	
	char buffer[BUFFER];
	while(gets(buffer) && buffer[0]!='\0')
	{
		innum.clear();
		char *p=strtok(buffer," ");
		while(p)
		{
			innum.push_back(string(p));
			p=strtok(NULL," ");
		}
		/*
		for(int i=0;i<(int)innum.size();i++)
		{
			cout<<innum[i]<<' ';
		}
		puts("");
		*/
		print(slove());
	}
	return 0;
}
	
