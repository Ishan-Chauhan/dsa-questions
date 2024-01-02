class Solution {
public:
    int mod=1e9+7;
    int sol(int s, int e, int k, vector<vector<int>>& dp)
    {
        
        if(k==0 && s==e) return 1;
        if(abs(s-e)>k) return 0;
        
        if(dp[s][k]!=-1) return dp[s][k]%mod;
        
        
        return dp[s][k] = (sol(s+1, e, k-1, dp)%mod + sol(s-1, e, k-1, dp)%mod)%mod;
    }
    int numberOfWays(int s, int e, int k) {
        
        e=abs(e-s);
        s=0;
        
        
        vector<vector<int>> dp(2001, vector<int>(k+1, -1));
        
        return sol(s+1000, e+1000, k, dp)%mod;
    }
};