class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1, 0);
        long long newuser=0;
        int mod=1e9+7;
        
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            if(i-delay>0) newuser += dp[i-delay];
            if(i-forget>0) newuser -= dp[i-forget];
            
            dp[i]=newuser%mod;
        }
        long long res=0;
        
        for(int i=n-forget+1;i<=n;i++) res = (res+dp[i])%mod;
        
        return res;
    }
};