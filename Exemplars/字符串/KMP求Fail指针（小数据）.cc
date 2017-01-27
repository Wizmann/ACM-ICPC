/*
Infinite monkey theorem
Time Limit: 1000MS		Memory Limit: 32768KB

Description
Could you imaging a monkey writing computer programs? Surely monkeys are smart among animals. But their limited intelligence is no match for our human beings. However, there is a theorem about monkeys, and it states that monkeys can write everything if given enough time.
The theorem is called “Infinite monkey theorem”. It states that a monkey hitting keys at random on a typewriter keyboard for an infinite amount of time will almost surely type any given text, which of course includes the programs you are about to write (All computer programs can be represented as text, right?).
It’s very easy to prove this theorem. A little calculation will show you that if the monkey types for an infinite length of time the probability that the output contains a given text will approach 100%.
However, the time used is too long to be physically reasonable. The monkey will not be able to produce any useful programs even if it types until the death of the universe. To verify this and ensure that our human beings are not replaceable by monkeys, you are to calculate the probability that a monkey will get things right.
 
Input
There will be several test cases.
Each test case begins with a line containing two integers n and m separated by a whitespace (2<=n<=26, 1<=m<=1000). n is the number of keys on the typewriter and the monkey will hit these keys m times. Thus the typewriter will finally produce an output of m characters.
The following n lines describe keys on the typewriter. Each line has a lower case letter and a real number separated by a whitespace. The letter indicates what the typewriter will produce if the monkey hits that key and the real number indicates the probability that the monkey will hit this key. Two hits of the monkey are independent of each other (Two different hits have the same probability for a same key), and sum of all the probabilities for each key is ensured to be 1.
The last line of the test case contains a word composed of lower case letters. The length of the word will be less than or equal to 10.
The input will end with a line of two zeros separated by a whitespace. This line should not be processed.
 
Output
For each test case, output one line containing the probability that the given word will appear in the typewriter’s output. The output should be in percentage format and numbers should be rounded to two digits after the decimal point.
 
Sample Input
4 10
w 0.25
o 0.25
r 0.25
d 0.25
word
2 10
a 1.0
b 0.0
abc
2 100
a 0.312345
b 0.687655
abab
0 0
 
Sample Output
2.73%
0.00%
98.54%
*/

/*
题意：字符集中有一些字符，给出每个字符的出现概率（它们的和保证为1），再给出一个子串S，问任给一个长度为N的字符串A（只能包含字符集中的字符），使得S是A的子串的概率。
*/

//Result:2012-09-05 21:18:49	Accepted	3689	15MS	508K	1531 B	C++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 1024


int to[SIZE][26];
char word[12];
int next[SIZE];
int n,q;
double pp[512];
double dp[SIZE][12];

void kmp_get_next()
{
	memset(to,0,sizeof(to));
	int len=strlen(word);
	next[0]=-1;
	for(int i=0,j=-1;i<len;i++,j++,next[i]=j)
	{
		while(j>=0 && word[i]!=word[j]) j=next[j];
	}
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<26;j++)
		{
			int nx=i;
			while(nx!=-1 && word[nx]!='a'+j) nx=next[nx];//KMP求Fail指针
			to[i][j]=++nx;
		}
	}
}

double slove()
{
	int len=strlen(word);
	//for(int i=0;i<len;i++) next[i]+=1;
	memset(dp,0,sizeof(dp));
	dp[0][0]=100;
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(dp[i][j]>1e-7)
			{
				double now=dp[i][j];
				dp[i+1][j+1]+=now*pp[int(word[j])];
				for(int k=0;k<26;k++) if(k+'a'!=word[j])
				{
					int nx=to[j][k];
					dp[i+1][nx]+=now*pp[int('a'+k)];
				}
			}
		}
		dp[i+1][len]+=dp[i][len];
	}
	/*
	for(int i=0;i<=q;i++)
	{
		for(int j=0;j<=len;j++)
		{
			printf("%.2lf ",dp[i][j]);
		}
		puts("");
	}
	*/
	return dp[q][len];
}


int main()
{
	freopen("input.txt","r",stdin);
	char cmd[10];
	double tmp;
	while(input(n>>q) && n+q)
	{
		memset(pp,0,sizeof(pp));
		for(int i=0;i<n;i++)
		{
			scanf("%s%lf",cmd,&tmp);
			pp[int(*cmd)]=tmp;
		}
		scanf("%s",word);
		kmp_get_next();
		printf("%.2lf%%\n",slove());
	}
	return 0;
}

