class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1);
        dp[0]=1;
        long long mod = 1e9 + 7;

        for(int i=1;i<=n;i++)
        {
            int t = pow(i, x);
            if(t>n) break;

            for(int j=n;j>=t;j--)
            {
                dp[j] = (dp[j] + dp[j-t])%mod;
            }
        }
        return dp[n];
        
    }
};