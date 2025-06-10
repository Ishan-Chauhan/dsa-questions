class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        if(n==2) return max(0, prices[1]-prices[0]);

        vector<int> dp(n+1, 0);
        int curr;

        for(int i=2;i<=n;i++)
        {
            curr = prices[i-1];
            dp[i] = dp[i-1];
            for(int j=i-2; j>=0; j--)
            {
                if(prices[j]<curr) 
                {
                    // if(j==0) dp[i] = max(dp[i], curr-prices[j]);
                    // else 
                    dp[i] = max(dp[i], curr-prices[j]+dp[j]);
                }
            }
            // cout<<dp[i]<<" ";
        }

        return dp[n];
    }
};