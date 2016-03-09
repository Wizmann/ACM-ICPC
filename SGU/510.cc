//Result:Wizmann	C	Accepted	955 KB	31 ms	GNU CPP (MinGW, GCC 4)	10201 B	2012-07-12 15:10:51
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

/*
int n;

int getans(string x)
{
	set<string> st;
	int sz=x.length();
	for(int i=0;i<sz;i++)
	{
		string t;
		for(int j=i;j<sz;j++)
		{
			t+=x[j];
			st.insert(t);
		}
	}
	return st.size();
}


bool cal(string s,int l)
{
	string ss=s;
	char x='z'+1;
	for(int i=l;i<(int)s.length();i++)
	{
		ss[i]=x++;
	}
	return getans(ss)<n;
}

bool dfs(string s,int l,char up='a')
{
	if(cal(s,l)) return 0;
	if(l==(int)s.length()-1)
	{
		if(getans(s)==n)
		{
			printf("%s",s.c_str());
			return 1;
		}
		else return 0;
	}

	string ss=s;
	for(char i='a';i<=up;i++)
	{
		ss[l+1]=i;
		if(dfs(ss,l+1,up)) return 1;
	}
	if(up<'z')
	{
		ss[l+1]=++up;
		if(dfs(ss,l+1,up)) return 1;
	}
	return 0;
}



int main()
{
	for(n=1;n<=300;n++)
	{
		printf("ans[%d]=\"",n);
		int len=1;
		while(1)
		{
			string str;
			str.resize(len,'a');
			if(dfs(str,0)) break;
			len++;
		}
		printf("\"\n");
	}
	return 0;
}
*/



string ans[320];

void init()
{
	ans[1]="a";
	ans[2]="aa";
	ans[3]="ab";
	ans[4]="aaaa";
	ans[5]="aab";
	ans[6]="abc";
	ans[7]="aaab";
	ans[8]="aaba";
	ans[9]="aabc";
	ans[10]="abcd";
	ans[11]="aaaba";
	ans[12]="aaabc";
	ans[13]="aabac";
	ans[14]="aabcd";
	ans[15]="abcde";
	ans[16]="aaabba";
	ans[17]="aaabac";
	ans[18]="aaabcd";
	ans[19]="aabacd";
	ans[20]="aabcde";
	ans[21]="abcdef";
	ans[22]="aaaabcd";
	ans[23]="aaabaca";
	ans[24]="aaabacd";
	ans[25]="aaabcde";
	ans[26]="aabacde";
	ans[27]="aabcdef";
	ans[28]="abcdefg";
	ans[29]="aaaabacd";
	ans[30]="aaaabcde";
	ans[31]="aaabacad";
	ans[32]="aaabacde";
	ans[33]="aaabcdef";
	ans[34]="aabacdef";
	ans[35]="aabcdefg";
	ans[36]="abcdefgh";
	ans[37]="aaaabacad";
	ans[38]="aaaabacde";
	ans[39]="aaaabcdef";
	ans[40]="aaabacade";
	ans[41]="aaabacdef";
	ans[42]="aaabcdefg";
	ans[43]="aabacdefg";
	ans[44]="aabcdefgh";
	ans[45]="abcdefghi";
	ans[46]="aaaabaacde";
	ans[47]="aaaabacade";
	ans[48]="aaaabacdef";
	ans[49]="aaaabcdefg";
	ans[50]="aaabacadef";
	ans[51]="aaabacdefg";
	ans[52]="aaabcdefgh";
	ans[53]="aabacdefgh";
	ans[54]="aabcdefghi";
	ans[55]="abcdefghij";
	ans[56]="aaaaabcdefg";
	ans[57]="aaaabaacdef";
	ans[58]="aaaabacadef";
	ans[59]="aaaabacdefg";
	ans[60]="aaaabcdefgh";
	ans[61]="aaabacadefg";
	ans[62]="aaabacdefgh";
	ans[63]="aaabcdefghi";
	ans[64]="aabacdefghi";
	ans[65]="aabcdefghij";
	ans[66]="abcdefghijk";
	ans[67]="aaaaabacdefg";
	ans[68]="aaaaabcdefgh";
	ans[69]="aaaabaacdefg";
	ans[70]="aaaabacadefg";
	ans[71]="aaaabacdefgh";
	ans[72]="aaaabcdefghi";
	ans[73]="aaabacadefgh";
	ans[74]="aaabacdefghi";
	ans[75]="aaabcdefghij";
	ans[76]="aabacdefghij";
	ans[77]="aabcdefghijk";
	ans[78]="abcdefghijkl";
	ans[79]="aaaaabacadefg";
	ans[80]="aaaaabacdefgh";
	ans[81]="aaaaabcdefghi";
	ans[82]="aaaabaacdefgh";
	ans[83]="aaaabacadefgh";
	ans[84]="aaaabacdefghi";
	ans[85]="aaaabcdefghij";
	ans[86]="aaabacadefghi";
	ans[87]="aaabacdefghij";
	ans[88]="aaabcdefghijk";
	ans[89]="aabacdefghijk";
	ans[90]="aabcdefghijkl";
	ans[91]="abcdefghijklm";
	ans[92]="aaaaabaacdefgh";
	ans[93]="aaaaabacadefgh";
	ans[94]="aaaaabacdefghi";
	ans[95]="aaaaabcdefghij";
	ans[96]="aaaabaacdefghi";
	ans[97]="aaaabacadefghi";
	ans[98]="aaaabacdefghij";
	ans[99]="aaaabcdefghijk";
	ans[100]="aaabacadefghij";
	ans[101]="aaabacdefghijk";
	ans[102]="aaabcdefghijkl";
	ans[103]="aabacdefghijkl";
	ans[104]="aabcdefghijklm";
	ans[105]="abcdefghijklmn";
	ans[106]="aaaaabaacadefgh";
	ans[107]="aaaaabaacdefghi";
	ans[108]="aaaaabacadefghi";
	ans[109]="aaaaabacdefghij";
	ans[110]="aaaaabcdefghijk";
	ans[111]="aaaabaacdefghij";
	ans[112]="aaaabacadefghij";
	ans[113]="aaaabacdefghijk";
	ans[114]="aaaabcdefghijkl";
	ans[115]="aaabacadefghijk";
	ans[116]="aaabacdefghijkl";
	ans[117]="aaabcdefghijklm";
	ans[118]="aabacdefghijklm";
	ans[119]="aabcdefghijklmn";
	ans[120]="abcdefghijklmno";
	ans[121]="aaaaaabcdefghijk";
	ans[122]="aaaaabaacadefghi";
	ans[123]="aaaaabaacdefghij";
	ans[124]="aaaaabacadefghij";
	ans[125]="aaaaabacdefghijk";
	ans[126]="aaaaabcdefghijkl";
	ans[127]="aaaabaacdefghijk";
	ans[128]="aaaabacadefghijk";
	ans[129]="aaaabacdefghijkl";
	ans[130]="aaaabcdefghijklm";
	ans[131]="aaabacadefghijkl";
	ans[132]="aaabacdefghijklm";
	ans[133]="aaabcdefghijklmn";
	ans[134]="aabacdefghijklmn";
	ans[135]="aabcdefghijklmno";
	ans[136]="abcdefghijklmnop";
	ans[137]="aaaaaabacdefghijk";
	ans[138]="aaaaaabcdefghijkl";
	ans[139]="aaaaabaacadefghij";
	ans[140]="aaaaabaacdefghijk";
	ans[141]="aaaaabacadefghijk";
	ans[142]="aaaaabacdefghijkl";
	ans[143]="aaaaabcdefghijklm";
	ans[144]="aaaabaacdefghijkl";
	ans[145]="aaaabacadefghijkl";
	ans[146]="aaaabacdefghijklm";
	ans[147]="aaaabcdefghijklmn";
	ans[148]="aaabacadefghijklm";
	ans[149]="aaabacdefghijklmn";
	ans[150]="aaabcdefghijklmno";
	ans[151]="aabacdefghijklmno";
	ans[152]="aabcdefghijklmnop";
	ans[153]="abcdefghijklmnopq";
	ans[154]="aaaaaabacadefghijk";
	ans[155]="aaaaaabacdefghijkl";
	ans[156]="aaaaaabcdefghijklm";
	ans[157]="aaaaabaacadefghijk";
	ans[158]="aaaaabaacdefghijkl";
	ans[159]="aaaaabacadefghijkl";
	ans[160]="aaaaabacdefghijklm";
	ans[161]="aaaaabcdefghijklmn";
	ans[162]="aaaabaacdefghijklm";
	ans[163]="aaaabacadefghijklm";
	ans[164]="aaaabacdefghijklmn";
	ans[165]="aaaabcdefghijklmno";
	ans[166]="aaabacadefghijklmn";
	ans[167]="aaabacdefghijklmno";
	ans[168]="aaabcdefghijklmnop";
	ans[169]="aabacdefghijklmnop";
	ans[170]="aabcdefghijklmnopq";
	ans[171]="abcdefghijklmnopqr";
	ans[172]="aaaaaabaacdefghijkl";
	ans[173]="aaaaaabacadefghijkl";
	ans[174]="aaaaaabacdefghijklm";
	ans[175]="aaaaaabcdefghijklmn";
	ans[176]="aaaaabaacadefghijkl";
	ans[177]="aaaaabaacdefghijklm";
	ans[178]="aaaaabacadefghijklm";
	ans[179]="aaaaabacdefghijklmn";
	ans[180]="aaaaabcdefghijklmno";
	ans[181]="aaaabaacdefghijklmn";
	ans[182]="aaaabacadefghijklmn";
	ans[183]="aaaabacdefghijklmno";
	ans[184]="aaaabcdefghijklmnop";
	ans[185]="aaabacadefghijklmno";
	ans[186]="aaabacdefghijklmnop";
	ans[187]="aaabcdefghijklmnopq";
	ans[188]="aabacdefghijklmnopq";
	ans[189]="aabcdefghijklmnopqr";
	ans[190]="abcdefghijklmnopqrs";
	ans[191]="aaaaaabaacadefghijkl";
	ans[192]="aaaaaabaacdefghijklm";
	ans[193]="aaaaaabacadefghijklm";
	ans[194]="aaaaaabacdefghijklmn";
	ans[195]="aaaaaabcdefghijklmno";
	ans[196]="aaaaabaacadefghijklm";
	ans[197]="aaaaabaacdefghijklmn";
	ans[198]="aaaaabacadefghijklmn";
	ans[199]="aaaaabacdefghijklmno";
	ans[200]="aaaaabcdefghijklmnop";
	ans[201]="aaaabaacdefghijklmno";
	ans[202]="aaaabacadefghijklmno";
	ans[203]="aaaabacdefghijklmnop";
	ans[204]="aaaabcdefghijklmnopq";
	ans[205]="aaabacadefghijklmnop";
	ans[206]="aaabacdefghijklmnopq";
	ans[207]="aaabcdefghijklmnopqr";
	ans[208]="aabacdefghijklmnopqr";
	ans[209]="aabcdefghijklmnopqrs";
	ans[210]="abcdefghijklmnopqrst";
	ans[211]="aaaaaabaacadaefghijkl";
	ans[212]="aaaaaabaacadefghijklm";
	ans[213]="aaaaaabaacdefghijklmn";
	ans[214]="aaaaaabacadefghijklmn";
	ans[215]="aaaaaabacdefghijklmno";
	ans[216]="aaaaaabcdefghijklmnop";
	ans[217]="aaaaabaacadefghijklmn";
	ans[218]="aaaaabaacdefghijklmno";
	ans[219]="aaaaabacadefghijklmno";
	ans[220]="aaaaabacdefghijklmnop";
	ans[221]="aaaaabcdefghijklmnopq";
	ans[222]="aaaabaacdefghijklmnop";
	ans[223]="aaaabacadefghijklmnop";
	ans[224]="aaaabacdefghijklmnopq";
	ans[225]="aaaabcdefghijklmnopqr";
	ans[226]="aaabacadefghijklmnopq";
	ans[227]="aaabacdefghijklmnopqr";
	ans[228]="aaabcdefghijklmnopqrs";
	ans[229]="aabacdefghijklmnopqrs";
	ans[230]="aabcdefghijklmnopqrst";
	ans[231]="abcdefghijklmnopqrstu";
	ans[232]="aaaaaaabcdefghijklmnop";
	ans[233]="aaaaaabaacadaefghijklm";
	ans[234]="aaaaaabaacadefghijklmn";
	ans[235]="aaaaaabaacdefghijklmno";
	ans[236]="aaaaaabacadefghijklmno";
	ans[237]="aaaaaabacdefghijklmnop";
	ans[238]="aaaaaabcdefghijklmnopq";
	ans[239]="aaaaabaacadefghijklmno";
	ans[240]="aaaaabaacdefghijklmnop";
	ans[241]="aaaaabacadefghijklmnop";
	ans[242]="aaaaabacdefghijklmnopq";
	ans[243]="aaaaabcdefghijklmnopqr";
	ans[244]="aaaabaacdefghijklmnopq";
	ans[245]="aaaabacadefghijklmnopq";
	ans[246]="aaaabacdefghijklmnopqr";
	ans[247]="aaaabcdefghijklmnopqrs";
	ans[248]="aaabacadefghijklmnopqr";
	ans[249]="aaabacdefghijklmnopqrs";
	ans[250]="aaabcdefghijklmnopqrst";
	ans[251]="aabacdefghijklmnopqrst";
	ans[252]="aabcdefghijklmnopqrstu";
	ans[253]="abcdefghijklmnopqrstuv";
	ans[254]="aaaaaaabacdefghijklmnop";
	ans[255]="aaaaaaabcdefghijklmnopq";
	ans[256]="aaaaaabaacadaefghijklmn";
	ans[257]="aaaaaabaacadefghijklmno";
	ans[258]="aaaaaabaacdefghijklmnop";
	ans[259]="aaaaaabacadefghijklmnop";
	ans[260]="aaaaaabacdefghijklmnopq";
	ans[261]="aaaaaabcdefghijklmnopqr";
	ans[262]="aaaaabaacadefghijklmnop";
	ans[263]="aaaaabaacdefghijklmnopq";
	ans[264]="aaaaabacadefghijklmnopq";
	ans[265]="aaaaabacdefghijklmnopqr";
	ans[266]="aaaaabcdefghijklmnopqrs";
	ans[267]="aaaabaacdefghijklmnopqr";
	ans[268]="aaaabacadefghijklmnopqr";
	ans[269]="aaaabacdefghijklmnopqrs";
	ans[270]="aaaabcdefghijklmnopqrst";
	ans[271]="aaabacadefghijklmnopqrs";
	ans[272]="aaabacdefghijklmnopqrst";
	ans[273]="aaabcdefghijklmnopqrstu";
	ans[274]="aabacdefghijklmnopqrstu";
	ans[275]="aabcdefghijklmnopqrstuv";
	ans[276]="abcdefghijklmnopqrstuvw";
	ans[277]="aaaaaaabacadefghijklmnop";
	ans[278]="aaaaaaabacdefghijklmnopq";
	ans[279]="aaaaaaabcdefghijklmnopqr";
	ans[280]="aaaaaabaacadaefghijklmno";
	ans[281]="aaaaaabaacadefghijklmnop";
	ans[282]="aaaaaabaacdefghijklmnopq";
	ans[283]="aaaaaabacadefghijklmnopq";
	ans[284]="aaaaaabacdefghijklmnopqr";
	ans[285]="aaaaaabcdefghijklmnopqrs";
	ans[286]="aaaaabaacadefghijklmnopq";
	ans[287]="aaaaabaacdefghijklmnopqr";
	ans[288]="aaaaabacadefghijklmnopqr";
	ans[289]="aaaaabacdefghijklmnopqrs";
	ans[290]="aaaaabcdefghijklmnopqrst";
	ans[291]="aaaabaacdefghijklmnopqrs";
	ans[292]="aaaabacadefghijklmnopqrs";
	ans[293]="aaaabacdefghijklmnopqrst";
	ans[294]="aaaabcdefghijklmnopqrstu";
	ans[295]="aaabacadefghijklmnopqrst";
	ans[296]="aaabacdefghijklmnopqrstu";
	ans[297]="aaabcdefghijklmnopqrstuv";
	ans[298]="aabacdefghijklmnopqrstuv";
	ans[299]="aabcdefghijklmnopqrstuvw";
	ans[300]="abcdefghijklmnopqrstuvwx";
}


int main()
{
	int n;
	init();
	input(n);
	print(ans[n]);
	return 0;
}
