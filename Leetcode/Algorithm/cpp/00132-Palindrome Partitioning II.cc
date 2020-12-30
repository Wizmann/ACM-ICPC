class Solution {
public:
    int minCut(string s) {
        memset(isP,0,sizeof(isP));
        memset(dp,0,sizeof(dp));
        ss = s;
        int len = s.length();
        for(int i=len-1;i>=0;i--)
        {
            for(int j=i;j<len;j++)
            {
                if(s[i]==s[j] && (j-i<2 || isP[i+1][j-1]))
                {
                    isP[i][j]=1;
                }
            }
        }
        for(int i=0;i<len;i++) dp[i]=len-i;
        for(int i=len-1;i>=0;i--)
        {
            for(int j=i;j<len;j++)
            {
                if(isP[i][j])
                {
                    dp[i]=min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0]-1;
    }
    enum{ SIZE=1500 };
    string ss;
    int dp[SIZE];
    char isP[SIZE][SIZE];
};