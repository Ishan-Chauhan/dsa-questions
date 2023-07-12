class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        vector<int> dp(n+1,0);
        dp[0]=0;
        int ones=0;
        
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='1') 
            {
                ones++;
                dp[i] = dp[i-1];
            }
            else
            {
                dp[i] = min(ones, 1+dp[i-1]);
            }
        }
        return dp[n];
    }
};