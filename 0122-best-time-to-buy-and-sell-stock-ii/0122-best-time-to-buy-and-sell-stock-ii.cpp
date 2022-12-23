class Solution {
public:
    int sol(int i, int n, vector<int>& prices, int f, vector<vector<int>> &dp)
    {
        if(i>=n) return 0;
        // f==1 => buy the stock
        if(dp[i][f]!=-1) return dp[i][f];
        if(f==1)
        {
            int buy = -prices[i] + sol(i+1,n,prices,0,dp);
            int buy_next = sol(i+1,n,prices,1,dp);
            
            return dp[i][f]=max(buy, buy_next);
        }
        
        int sell = prices[i] + sol(i+1,n,prices,1,dp);
        int not_sell = sol(i+1,n,prices,0,dp);
            
        return dp[i][f]=max(sell,not_sell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = INT_MIN;
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return sol(0,n,prices,1,dp);
    }
};