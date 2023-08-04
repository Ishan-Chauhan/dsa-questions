class Solution {
public:
    int sol(string s, int i, int n, vector<int> &dp)
    {
        if(i==n) return 1;
        if(i>n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        if(s[i]=='1') return dp[i] = sol(s,i+1,n,dp) + sol(s,i+2,n,dp);
        
        if(s[i]=='2')
        {
            if(i<n-1 && s[i+1]>='0' && s[i+1]<='6') return dp[i]= sol(s,i+1,n,dp)+sol(s,i+2,n,dp);
            else return dp[i] = sol(s,i+1,n,dp);
        }
        
        if(s[i]=='0') return dp[i] = 0;
        
        return dp[i] = sol(s,i+1,n,dp);
        
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        
        int x = sol(s, 0, n, dp);
        
        return dp[0];
    }
};